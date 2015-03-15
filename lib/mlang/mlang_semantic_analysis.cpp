/*
 * mlang_semantic_analysis.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: mario
 */
#include <map>
#include <vector>
#include <iostream>

#include "mlang_semantic_analysis.hh"
#include "mlang_dom_provider.hh"

class SemanticPass: public CodeObjectVisitorBase {
private:
	vector<p_CompilerError>& m_errors;
public:
	SemanticPass(vector<p_CompilerError>& errors) :
			m_errors(errors) {
	}

	virtual ~SemanticPass() {

	}
	void error(Location* location, std::string msg) {
		p_CompilerError err = new CompilerError();
		err->location(location);
		err->message(msg);
		m_errors.push_back(err);
	}

	void error(CodeObject* object, std::string msg) {
		p_CompilerError err = new CompilerError();
		err->location(object->location());
		err->message(msg);
		m_errors.push_back(err);
	}

	inline vector<p_CompilerError>& errors() {
		return this->m_errors;
	}

};

class LoadTypes: public SemanticPass {
private:
	std::string current_namespace;
	std::string current_type_name;

	std::map<std::string, CodeTypeDeclaration*> m_type_declarations;
	std::multimap<std::string, CodeMemberMethod*> m_method_declarations;

protected:
	using CodeObjectVisitorBase::on_visit;

public:
	std::map<std::string, CodeTypeDeclaration*> type_declarations() {
		return m_type_declarations;
	}

	LoadTypes(vector<p_CompilerError>& errors) :
			SemanticPass(errors) {
	}

	virtual ~LoadTypes() {

	}

	inline void on_visit(CodeCompileUnit* object) {
		current_namespace = "global";
		current_type_name = "global";

		for (auto x : *object->namespaces()) {
			x->accept(this);
		}

		for (auto x : *object->types()) {
			x->accept(this);
		}

		current_type_name = "";
		current_namespace = "";
	}

	inline void on_visit(CodeNamespace* object) {
		std::string orig = current_namespace;
		if (current_namespace == "global")
			current_namespace = "global::" + object->name();
		else
			current_namespace = current_namespace + "." + object->name();

		for (auto x : *object->types()) {
			x->accept(this);
		}

		for (auto x : *object->methods()) {
			x->accept(this);
		}

		current_namespace = orig;
	}

	inline void on_visit(CodeTypeDeclaration* object) {
		std::string orig = current_type_name;

		current_type_name = "";
		if (current_namespace == "global")
			current_type_name = "global::" + object->name();
		else
			current_type_name = current_namespace + "." + object->name();

		std::map<std::string, CodeTypeDeclaration*>::iterator it =
				m_type_declarations.find(current_type_name);
		if (it != m_type_declarations.end()) {
			error(object,
					"The namespace `" + current_namespace
							+ "' already contains a definition for `"
							+ object->name() + "'.");
		}
		else
		{
			m_type_declarations.insert(
					std::map<std::string, CodeTypeDeclaration*>::value_type(
							current_type_name, object));
		}

		current_type_name = orig;
	}
};


class ResolveReferences: public SemanticPass {
private:
	std::map<std::string, CodeTypeDeclaration*>& m_type_declarations;

	std::vector<std::string> included_namespace_prefixes;

	bool match(CodeMemberMethod* method, CodeMethodInvokeExpression* object) {
		if (match(method, object->method())) {
			CodeTypeDeclaration* method_owner_type = nullptr;
			CodeObject* tmp = method->parent();
			while (tmp != nullptr && method_owner_type == nullptr) {
				if (tmp->type_of(CodeObjectKind::CodeTypeDeclaration))
					method_owner_type = (CodeTypeDeclaration*) tmp;
				tmp = tmp->parent();
			}

			//
			// if we have a match on the CodeMethodReferenceExpression we just need to validate the argument_types
			//
			auto method_declared_parameters = *method->parameters();
			CodeParameterDeclarationExpressionCollection::iterator it_method_declared_parameters =
					method_declared_parameters.begin();

			if (method_owner_type == nullptr
					&& object->method()->target_object() != nullptr)
				it_method_declared_parameters++;

			auto passed_parameters = *object->parameters();
			CodeExpressionCollection::iterator it_passed_parameters =
					passed_parameters.begin();

			bool ok = true;
			while (ok
					&& it_method_declared_parameters
							!= method_declared_parameters.end()
					&& it_passed_parameters != passed_parameters.end()) {
				auto method_declared_parameter = *it_method_declared_parameters;
				auto passed_parameter = *it_passed_parameters;
				auto method_declared_parameter_type = resolve_type(
						method_declared_parameter->type());
				auto passed_parameter_type = resolve_type(passed_parameter);

				ok &= (method_declared_parameter_type != nullptr
						&& passed_parameter_type != nullptr
						&& method_declared_parameter_type
								== passed_parameter_type);
				;

				it_method_declared_parameters++;
				it_passed_parameters++;
			}
			return ok;
		}
		return false;
	}

	bool match(CodeMemberMethod* method,
			CodeMethodReferenceExpression* object) {
		//
		// if the method_name doesn't match then skip all the rest.
		//
		if (object->method_name() == method->name()) {
			//
			// if a target_object is set, then this can indicate we are referencing a method that is member of a type
			//
			if (object->target_object() != nullptr) {
				//
				// is this method member of a CodeTypeDeclaration?
				//
				CodeTypeDeclaration* method_owner_type = nullptr;
				CodeObject* tmp = method->parent();
				while (tmp != nullptr && method_owner_type == nullptr) {
					if (tmp->type_of(CodeObjectKind::CodeTypeDeclaration))
						method_owner_type = (CodeTypeDeclaration*) tmp;
					tmp = tmp->parent();
				}

				//
				// if we find that the target_object_type and the type owning the method are the same then we must consider this method as a match.
				// however it can still turn out to be a false match when also considering all other arguments.
				//
				auto target_object_type = resolve_type(object->target_object());
				if (method_owner_type != nullptr) {
					if (target_object_type == method_owner_type) {
						return true;
					}
				} else {
					//
					// now, we can still see if there's no match when considering the target_object as a argument.
					// this can only be for methods that are not part of a type_declaration
					//
					if (method->parameters()->size() > 0) {
						auto first_param = method->parameters()->front();
						auto first_method_parameter_type = resolve_type(
								first_param);
						if (target_object_type == first_method_parameter_type)
							return true;
					}
				}
			} else {
				return true;
			}
		}

		return false;
	}

	inline std::string get_operator(CodeMemberMethod* object) {
		// eg. [Operator("+")]
		for (auto custom_attribute : object->custom_attributes()) {
			auto operator_attribute = get_type("Operator");
			if (operator_attribute == get_type(custom_attribute->name())) {
				for (auto argument : custom_attribute->arguments()) {
					if (argument->value() != nullptr
							&& argument->value()->type_of(
									CodeObjectKind::CodePrimitiveExpression)
							&& resolve_type(argument->value())
									== get_type("Array")) {
						std::string op =
								((CodePrimitiveExpression*) argument->value())->value_as_string();
						return op;
					}
				}
			}
		}

		return "";
	}

	inline bool is_cast_operator(CodeMemberMethod* object) {
		// eg. [CastOperator]
		for (auto custom_attribute : object->custom_attributes()) {
			if (custom_attribute->arguments().size() == 0) {
				auto operator_attribute = get_type("CastOperator");
				if (operator_attribute == get_type(custom_attribute->name())) {
					return true;
				}
			}
		}

		return false;
	}

	bool match_operator(CodeMemberMethod* method,
			CodeMethodInvokeExpression* object) {
		if (match_operator(method, object->method())) {
			CodeTypeDeclaration* method_owner_type = nullptr;
			CodeObject* tmp = method->parent();
			while (tmp != nullptr && method_owner_type == nullptr) {
				if (tmp->type_of(CodeObjectKind::CodeTypeDeclaration))
					method_owner_type = (CodeTypeDeclaration*) tmp;
				tmp = tmp->parent();
			}

			//
			// if we have a match on the CodeMethodReferenceExpression we just need to validate the argument_types
			//
			auto method_declared_parameters = *method->parameters();
			CodeParameterDeclarationExpressionCollection::iterator it_method_declared_parameters =
					method_declared_parameters.begin();

			if (method_owner_type == nullptr
					&& object->method()->target_object() != nullptr)
				it_method_declared_parameters++;

			auto passed_parameters = *object->parameters();
			CodeExpressionCollection::iterator it_passed_parameters =
					passed_parameters.begin();

			bool ok = true;
			while (ok
					&& it_method_declared_parameters
							!= method_declared_parameters.end()
					&& it_passed_parameters != passed_parameters.end()) {
				auto method_declared_parameter = *it_method_declared_parameters;
				auto passed_parameter = *it_passed_parameters;
				auto method_declared_parameter_type = resolve_type(
						method_declared_parameter->type());
				auto passed_parameter_type = resolve_type(passed_parameter);

				ok &= (method_declared_parameter_type != nullptr
						&& passed_parameter_type != nullptr
						&& method_declared_parameter_type
								== passed_parameter_type);
				;

				it_method_declared_parameters++;
				it_passed_parameters++;
			}
			return ok;
		}
		return false;
	}

	bool match_operator(CodeMemberMethod* method,
			CodeMethodReferenceExpression* object) {
		//
		// if the method_name doesn't match then skip all the rest.
		//
		if (object->method_name() == get_operator(method)) {
			//
			// if a target_object is set, then this can indicate we are referencing a method that is member of a type
			//
			if (object->target_object() != nullptr) {
				//
				// is this method member of a CodeTypeDeclaration?
				//
				CodeTypeDeclaration* method_owner_type = nullptr;
				CodeObject* tmp = method->parent();
				while (tmp != nullptr && method_owner_type == nullptr) {
					if (tmp->type_of(CodeObjectKind::CodeTypeDeclaration))
						method_owner_type = (CodeTypeDeclaration*) tmp;
					tmp = tmp->parent();
				}

				//
				// if we find that the target_object_type and the type owning the method are the same then we must consider this method as a match.
				// however it can still turn out to be a false match when also considering all other arguments.
				//
				auto target_object_type = resolve_type(object->target_object());
				if (method_owner_type != nullptr) {
					if (target_object_type == method_owner_type) {
						return true;
					}
				} else {
					//
					// now, we can still see if there's no match when considering the target_object as a argument.
					// this can only be for methods that are not part of a type_declaration
					//
					if (method->parameters()->size() > 0) {
						auto first_param = method->parameters()->front();
						auto first_method_parameter_type = resolve_type(
								first_param);
						if (target_object_type == first_method_parameter_type)
							return true;
					}
				}
			} else {
				return true;
			}
		}

		return false;
	}

	inline CodeMemberMethod*
	resolve_cast_expression(CodeCastExpression* object) {
		CodeMemberMethod* ret = nullptr;
		if (nullptr == object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_METHOD))
		{
			CodeScope* reachable_scope = object->scope();
					while (reachable_scope != nullptr) {
						for(auto member: *reachable_scope->members()) {
							if (member->type_of(CodeObjectKind::CodeMemberMethod)) {
								CodeMemberMethod* method = (CodeMemberMethod*)member;
								if (method->return_type() != nullptr && method->parameters()->size() == 1) {
									if (is_cast_operator(method)) {
										auto target_type = resolve_type(object->target_type());
										auto method_return_type = resolve_type(method->return_type());
										if (target_type == method_return_type) {

											auto cast_expression_type = resolve_type(object->expression());
											auto method_argument_type = resolve_type(method->parameters()->front());

											if (cast_expression_type == method_argument_type) {
												ret = method;
												object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_METHOD, method);
												return ret;
											}
										}
									}
								}
							}
						}
						reachable_scope = reachable_scope->parent();
					}
		}
		else
		{
			ret = (CodeMemberMethod*) object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_METHOD);
		}

		return ret;
	}

	inline CodeMemberMethod*
	resolve_method(CodeMethodInvokeExpression* object) {
		CodeMemberMethod* ret = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_METHOD)) {
			std::vector<CodeMemberMethod*>* res_list = new std::vector<
					CodeMemberMethod*>();

			CodeScope* scope = object->scope();
			while (scope != nullptr) {
				for (auto m : *scope->members()) {
					if (m->type_of(CodeObjectKind::CodeMemberMethod)) {
						auto code_member_method = (CodeMemberMethod*) m;
						if (match(code_member_method, object)) {
							res_list->push_back(code_member_method);
						}
					}
				}
				scope = scope->parent();
			}

			if (res_list->size() == 1) {
				object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_METHOD,
						res_list->front());
				ret = res_list->front();
			}
		} else {
			ret = (CodeMemberMethod*) object->user_data(
					UserDataKind::MLANG_RESOLVED_MEMBER_METHOD);
		}
		return ret;
	}

	inline CodeMemberMethod*
	resolve_binary_operator(CodeBinaryOperatorExpression* object) {

		auto method_reference = new CodeMethodReferenceExpression();
		switch (object->operator_()) {
		case CodeBinaryOperatorType::Add:
			method_reference->method_name("+");
			break;
		case CodeBinaryOperatorType::Divide:
			method_reference->method_name("/");
			break;
		case CodeBinaryOperatorType::Subtract:
			method_reference->method_name("-");
			break;
		case CodeBinaryOperatorType::Multiply:
			method_reference->method_name("*");
			break;
		case CodeBinaryOperatorType::BitwiseOr:
			method_reference->method_name("|");
			break;
		case CodeBinaryOperatorType::BooleanOr:
			method_reference->method_name("||");
			break;
		case CodeBinaryOperatorType::BitwiseAnd:
			method_reference->method_name("&");
			break;
		case CodeBinaryOperatorType::BooleanAnd:
			method_reference->method_name("&&");
			break;
		case CodeBinaryOperatorType::ExlusiveOr:
			method_reference->method_name("^");
			break;
		case CodeBinaryOperatorType::IdentityEquality:
			method_reference->method_name("==");
			break;
		case CodeBinaryOperatorType::IdentityInEquality:
			method_reference->method_name("!=");
			break;
		case CodeBinaryOperatorType::LessThan:
			method_reference->method_name("<");
			break;
		case CodeBinaryOperatorType::LessThanOrEqual:
			method_reference->method_name("<=");
			break;
		case CodeBinaryOperatorType::GreaterThan:
			method_reference->method_name(">");
			break;
		case CodeBinaryOperatorType::GreaterThanOrEqual:
			method_reference->method_name(">=");
			break;
		case CodeBinaryOperatorType::Modulus:
			method_reference->method_name("%");
			break;
		case CodeBinaryOperatorType::ShiftLeft:
			method_reference->method_name("<<");
			break;
		case CodeBinaryOperatorType::ShiftRight:
			method_reference->method_name(">>");
			break;
		}

		auto method_invoke_expression = new CodeMethodInvokeExpression();
		method_invoke_expression->parameters()->push_back(object->left());
		method_invoke_expression->parameters()->push_back(object->right());
		method_invoke_expression->method(method_reference);

		CodeMemberMethod* ret = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_METHOD)) {
			std::vector<CodeMemberMethod*>* res_list = new std::vector<
					CodeMemberMethod*>();

			CodeScope* scope = object->scope();
			while (scope != nullptr) {
				for (auto m : *scope->members()) {
					if (m->type_of(CodeObjectKind::CodeMemberMethod)) {
						auto code_member_method = (CodeMemberMethod*) m;
						if (match_operator(code_member_method,
								method_invoke_expression)) {
							res_list->push_back(code_member_method);
						}
					}
				}
				scope = scope->parent();
			}

			if (res_list->size() == 1) {
				object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_METHOD,
						res_list->front());
				ret = res_list->front();
			}
		} else {
			ret = (CodeMemberMethod*) object->user_data(
					UserDataKind::MLANG_RESOLVED_MEMBER_METHOD);
		}
		return ret;
	}

	inline CodeMemberField*
	resolve_field(CodeFieldReferenceExpression* object) {
		if (object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_FIELD)
				== nullptr) {
			CodeMemberField* res = nullptr;
			auto type = resolve_type(object->target_object());

			if (type != nullptr)
			{
				for (auto member : *type->members()) {
					if (member->type_of(CodeObjectKind::CodeMemberField)) {
						auto decl = (CodeMemberField*) member;
						if (decl->name() == object->field_name()) {
							res = decl;
							object->user_data(
									UserDataKind::MLANG_RESOLVED_MEMBER_FIELD, res);
							return res;
						}
					}
				}
			}

			return res;
		} else {
			return (CodeMemberField*) object->user_data(
					UserDataKind::MLANG_RESOLVED_MEMBER_FIELD);
		}

	}

	inline CodeMemberField*
	resolve_field(CodeVariableReferenceExpression* object) {
		if (object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_FIELD)
				== nullptr) {
			CodeMemberField* res = nullptr;

			CodeScope* scope = object->scope();
			while (scope != nullptr) {
				for (auto member : *scope->members()) {
					if (member->type_of(CodeObjectKind::CodeMemberField)) {
						auto decl = (CodeMemberField*) member;
						if (decl->name() == object->variable_name()) {
							res = decl;
							object->user_data(
									UserDataKind::MLANG_RESOLVED_MEMBER_FIELD,
									res);
							return res;
						}
					}
				}
				scope = scope->parent();
			}

			return res;
		} else {
			return (CodeMemberField*) object->user_data(
					UserDataKind::MLANG_RESOLVED_MEMBER_FIELD);
		}
	}

	inline CodeVariableDeclarationStatement*
	resolve_variable(CodeVariableReferenceExpression* object) {
		if (object->user_data(
				UserDataKind::MLANG_RESOLVED_VARIABLE_DECLARATION_STATEMENT)
				== nullptr) {
			CodeVariableDeclarationStatement* res = nullptr;

			CodeScope* scope = object->scope();
			while (scope != nullptr) {
				for (auto member : *scope->members()) {
					if (member->type_of(
							CodeObjectKind::CodeVariableDeclarationStatement)) {
						auto decl = (CodeVariableDeclarationStatement*) member;
						if (decl->name() == object->variable_name()) {
							res = decl;
							object->user_data(
									UserDataKind::MLANG_RESOLVED_VARIABLE_DECLARATION_STATEMENT,
									res);
							return res;
						}
					}
				}
				scope = scope->parent();
			}

			return res;
		} else {
			return (CodeVariableDeclarationStatement*) object->user_data(
					UserDataKind::MLANG_RESOLVED_VARIABLE_DECLARATION_STATEMENT);
		}
	}

	inline CodeParameterDeclarationExpression*
	resolve_parameter(CodeVariableReferenceExpression* object) {
		if (object->user_data(
				UserDataKind::MLANG_RESOLVED_PARAMETER_DECLARATION_EXPRESSION)
				== nullptr) {
			CodeParameterDeclarationExpression* res = nullptr;

			CodeScope* tmp = object->scope();
			while (tmp != nullptr) {
				for (auto m : *tmp->members()) {
					if (m->type_of(
							CodeObjectKind::CodeParameterDeclarationExpression)) {
						auto decl = (CodeParameterDeclarationExpression*) m;
						if (decl->name() == object->variable_name()) {
							res = decl;
							object->user_data(
									UserDataKind::MLANG_RESOLVED_PARAMETER_DECLARATION_EXPRESSION,
									res);
							return res;
						}
					}
				}
				tmp = tmp->parent();
			}

			return res;
		} else {
			return (CodeParameterDeclarationExpression*) object->user_data(
					UserDataKind::MLANG_RESOLVED_PARAMETER_DECLARATION_EXPRESSION);
		}
	}

	inline CodeTypeDeclaration* get_type(std::string base_type) {
		for (auto prefix : included_namespace_prefixes) {
			std::string search_string = prefix + base_type;

			std::map<std::string, CodeTypeDeclaration*>::iterator it =
					m_type_declarations.find(search_string);
			if (it != m_type_declarations.end()) {
				return it->second;
			}
		}
		return nullptr;
	}

	inline CodeTypeDeclaration* resolve_type(CodeAttributeDeclaration* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			res = get_type(object->name());
			if (res != nullptr) {
				object->user_data(
						UserDataKind::MLANG_RESOLVED_MEMBER_METHOD_LIST, res);
			}
		}
		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(CodeTypeReference* object) {
		if (nullptr
				== object->user_data(
						UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			CodeTypeDeclaration* res = nullptr;

			if (nullptr != object->array_element_type())
				resolve_type(object->array_element_type());

			for (auto prefix : included_namespace_prefixes) {
				std::string search_string = prefix + object->base_type();

				std::map<std::string, CodeTypeDeclaration*>::iterator it =
						m_type_declarations.find(search_string);
				if (it != m_type_declarations.end()) {
					res = it->second;
					break;
				}
			}

			if (res != nullptr) {
				void* tmp = res;
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						tmp);
			}
			return res;
		} else {
			void* tmp = object->user_data(
					UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
			return static_cast<CodeTypeDeclaration*>(tmp);
		}
	}

	inline CodeTypeDeclaration* resolve_type(
			CodeArrayCreateExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			// resolved code
			res = resolve_type(object->create_type());

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(CodeArrayIndexerExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			res = resolve_type(object->target_object());

			if (res != nullptr)
			{
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION, res);
			}
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(
			CodeAssemblyCallExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			res = resolve_type(object->return_type());

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(CodeAssignExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			res = resolve_type(object->right());

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(
			CodeBinaryOperatorExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			auto method = resolve_binary_operator(object);
			res = resolve_type(method->return_type());

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(CodeCastExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {

			res = resolve_type(object->target_type());

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(
			CodeFieldReferenceExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			auto field = resolve_field(object);
			res = resolve_type(field->type());

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(
			CodeMethodInvokeExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			auto method = resolve_method(object);
			if (method != nullptr) {
				res = resolve_type(method->return_type());

				if (res != nullptr)
					object->user_data(
							UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION, res);
			}
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(
			CodeMethodReferenceExpression* object) {
		return nullptr;
	}

	inline CodeTypeDeclaration* resolve_type(
			CodeObjectCreateExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			res = resolve_type(object->create_type());

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(
			CodeParameterDeclarationExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			res = resolve_type(object->type());

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(CodePrimitiveExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			res = resolve_type(object->type());

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(CodeSizeOfExpression* object) {
		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			res = get_type("UInt64");
			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(
			CodeVariableReferenceExpression* object) {

		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			auto var_decl = resolve_variable(object);
			if (var_decl == nullptr) {
				auto param_decl = resolve_parameter(object);
				if (param_decl == nullptr) {
					auto field_decl = resolve_field(object);

					if (field_decl == nullptr)
						return nullptr;

					res = resolve_type(field_decl->type());
				} else {
					res = resolve_type(param_decl->type());
				}
			} else {
				res = resolve_type(var_decl->type());
			}

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

	inline CodeTypeDeclaration* resolve_type(CodeExpression* object) {

		CodeTypeDeclaration* res = nullptr;
		if (!object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)) {
			// resolved code

			if (object->type_of(CodeObjectKind::CodeArrayCreateExpression))
				res = resolve_type((CodeArrayCreateExpression*) object);

			if (object->type_of(CodeObjectKind::CodeArrayIndexerExpression))
				res = resolve_type((CodeArrayIndexerExpression*) object);

			if (object->type_of(CodeObjectKind::CodeAssemblyCallExpression))
				res = resolve_type((CodeAssemblyCallExpression*) object);

			if (object->type_of(CodeObjectKind::CodeAssignExpression))
				res = resolve_type((CodeAssignExpression*) object);

			if (object->type_of(CodeObjectKind::CodeBinaryOperatorExpression))
				res = resolve_type((CodeBinaryOperatorExpression*) object);

			if (object->type_of(CodeObjectKind::CodeCastExpression))
				res = resolve_type((CodeCastExpression*) object);

			if (object->type_of(CodeObjectKind::CodeFieldReferenceExpression))
				res = resolve_type((CodeFieldReferenceExpression*) object);

			if (object->type_of(CodeObjectKind::CodeMethodInvokeExpression))
				res = resolve_type((CodeMethodInvokeExpression*) object);

			if (object->type_of(CodeObjectKind::CodeMethodReferenceExpression))
				res = resolve_type((CodeMethodReferenceExpression*) object);

			if (object->type_of(CodeObjectKind::CodeObjectCreateExpression))
				res = resolve_type((CodeObjectCreateExpression*) object);

			if (object->type_of(
					CodeObjectKind::CodeParameterDeclarationExpression))
				res = resolve_type(
						(CodeParameterDeclarationExpression*) object);

			if (object->type_of(CodeObjectKind::CodePrimitiveExpression))
				res = resolve_type((CodePrimitiveExpression*) object);

			if (object->type_of(CodeObjectKind::CodeSizeOfExpression))
				res = resolve_type((CodeSizeOfExpression*) object);

			if (object->type_of(
					CodeObjectKind::CodeVariableReferenceExpression))
				res = resolve_type((CodeVariableReferenceExpression*) object);

			if (res != nullptr)
				object->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION,
						res);
		}

		return (CodeTypeDeclaration*) object->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	}

protected:
	using SemanticPass::on_visit;
public:
	ResolveReferences(vector<p_CompilerError>& errors,
			std::map<std::string, CodeTypeDeclaration*>& type_declarations) :
			SemanticPass(errors), m_type_declarations(type_declarations) {
		included_namespace_prefixes.push_back("global::");
	}

	inline void on_visit(CodeCompileUnit* object) {
		for (auto x : *object->namespaces()) {
			x->accept(this);
		}

		for (auto x : *object->types()) {
			x->accept(this);
		}

		for (auto x : *object->methods()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeNamespace* object) {
		for (auto x : *object->types()) {
			x->accept(this);
		}

		for (auto x : *object->methods()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeTypeDeclaration* object) {
		for (auto x : *object->members()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeMemberMethod* object) {
		for (auto x : *object->parameters()) {
			x->accept(this);
		}

		for (auto x : *object->statements()) {
			x->accept(this);
		}

		if (object->return_type() != nullptr) {
			object->return_type()->accept(this);
		} else {
			// if this is null, then we should try to infer the type from the return_statements
			// not forgetting to create a TypeReference object and set it as return_type
		}
	}

	inline void on_visit(CodeArrayCreateExpression* object) {
		if (object->size_expression() != nullptr)
			object->size_expression()->accept(this);

		if (object->create_type() != nullptr)
			object->create_type()->accept(this);
	}

	inline void on_visit(CodeArrayIndexerExpression* object) {
		if (object->target_object() != nullptr)
			object->target_object()->accept(this);

		for (auto x : *object->indices()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeAssemblyCallExpression* object) {
		if (object->return_type() != nullptr) {
			object->return_type()->accept(this);
		}

		for (auto x : *object->parameters())
			x->accept(this);
	}

	inline void on_visit(CodeAssignExpression* object) {
		if (object->left() != nullptr) {
			object->left()->accept(this);
		}

		if (object->right() != nullptr)
			object->right()->accept(this);
	}

	inline void on_visit(CodeAttributeArgument* object) {
		object->value()->accept(this);
	}

	inline void on_visit(CodeAttributeDeclaration* object) {
		for (auto x : object->arguments()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeCastExpression* object) {
		object->target_type()->accept(this);
		object->expression()->accept(this);

		// validate if method can be found
		auto target_type = resolve_type(object->target_type());
		auto expression_type = resolve_type(object->expression());
		auto res = resolve_cast_expression(object);
		//if (res == nullptr)
		//	error(object->location(),
		//		"There's no cast operator defined that can convert`" + expression_type->name() + "' to `" + target_type->name() + "'.");
	}

	inline void on_visit(CodeConditionStatement* object) {
		object->condition()->accept(this);
		for (auto x : *object->true_statements()) {
			x->accept(this);
		}

		for (auto x : *object->false_statements()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeExpressionStatement* object) {
		object->expression()->accept(this);
	}

	inline void on_visit(CodeExpression* object) {
	}

	inline void on_visit(CodeFieldReferenceExpression* object) {
		if (object->target_object() != nullptr)
			object->target_object()->accept(this);

		// validate if method can be found
		auto res = resolve_field(object);
		if (res == nullptr)
			error(object->location(),
					"The field `" + object->field_name()
							+ "' could not be found.");
	}

	inline void on_visit(CodeFileInclude* object) {

	}

	inline void on_visit(CodeIrBlockStatement* object) {

	}

	inline void on_visit(CodeIterationStatement* object) {
		if (object->increment_statement() != nullptr)
			object->increment_statement()->accept(this);
		if (object->init_statement() != nullptr)
			object->init_statement()->accept(this);
		if (object->test_expression() != nullptr)
			object->test_expression()->accept(this);

		for (auto x : *object->statements())
			x->accept(this);
	}

	inline void on_visit(CodeMemberField* object) {
		if (object->type() != nullptr) {
			object->type()->accept(this);
		}
		if (object->init_expression() != nullptr)
			object->init_expression()->accept(this);
	}

	inline void on_visit(CodeMemberProperty* object) {
	}

	inline void on_visit(CodeMethodReturnStatement* object) {
		if (object->expression() != nullptr)
			object->expression()->accept(this);
	}

	inline void on_visit(CodeObjectCreateExpression* object) {
		if (object->create_type() != nullptr) {
			object->create_type()->accept(this);
		}
		for (auto x : *object->parameters())
			x->accept(this);
	}

	inline void on_visit(CodeParameterDeclarationExpression* object) {
		if (object->type() != nullptr) {
			object->type()->accept(this);
		}
	}

	inline void on_visit(CodePrimitiveExpression* object) {
		if (object->type() != nullptr) {
			object->type()->accept(this);
		}
	}

	inline void on_visit(CodeSizeOfExpression* object) {
		if (object->type() != nullptr)
			object->type()->accept(this);
	}

	inline void on_visit(CodeStatement* object) {
	}

	inline void on_visit(CodeVariableDeclarationStatement* object) {
		if (object->type() != nullptr)
			object->type()->accept(this);
		if (object->init_expression() != nullptr)
			object->init_expression()->accept(this);
	}

	inline void on_visit(CodeMethodInvokeExpression* object) {
		if (object->method() != nullptr) {
			object->method()->accept(this);
		}

		for (auto x : *object->parameters())
			x->accept(this);

		// validate if method can be found
		auto res = resolve_method(object);
		if (res == nullptr)
			error(object->location(),
					"The method name `" + object->method()->method_name()
							+ "' could not be found. Are you missing an assembly reference?");
	}

	inline void on_visit(CodeVariableReferenceExpression* object) {
		CodeObject* res = resolve_variable(object);

		if (res == nullptr)
			res = resolve_parameter(object);

		if (res == nullptr)
			res = resolve_field(object);

		if (res == nullptr)
			error(object->location(),
					"The variable `" + object->variable_name()
							+ "' could not be found. Are you missing an assembly reference?");
	}

	inline void on_visit(CodeTypeReference* object) {
		auto res = resolve_type(object);
		if (res == nullptr)
			error(object->location(),
					"The type `" + object->base_type()
							+ "' could not be found. Are you missing an assembly reference?");
	}

	inline void on_visit(CodeMethodReferenceExpression* object) {

	}

	inline void on_visit(CodeBinaryOperatorExpression* object) {
		if (object->left() != nullptr)
			object->left()->accept(this);
		if (object->right() != nullptr)
			object->right()->accept(this);

		auto res = resolve_binary_operator(object);
		if (res == nullptr)
			error(object->location(),
					"There's no definition for this operator.");
	}
};

class DetectCyclicStructures: public SemanticPass {
protected:
	using SemanticPass::on_visit;

public:
	DetectCyclicStructures(vector<p_CompilerError>& errors) :
			SemanticPass(errors) {
	}

	inline void on_visit(CodeCompileUnit* object) {
		for (auto x : *object->namespaces()) {
			x->accept(this);
		}

		for (auto x : *object->types()) {
			x->accept(this);
		}

		for (auto x : *object->methods()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeNamespace* object) {
		for (auto x : *object->types()) {
			x->accept(this);
		}

		for (auto x : *object->methods()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeTypeDeclaration* object) {
		if (object->is_struct())
		{
			for (auto member : *object->members()) {
				if (member->type_of(CodeObjectKind::CodeMemberField)) {
					CodeMemberField* field = (CodeMemberField*) member;
					if (is_cyclic_member_field(object, field)) {
						error(field->location(),
								"Struct member `" + object->name() + "."
										+ member->name() + "' of type `"
										+ field->type()->base_type()
										+ "' causes a cycle in the struct layout");
					} else {
						if (field->type()->user_data(
								UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)
								!= nullptr) {
							CodeTypeDeclaration* field_type =
									(CodeTypeDeclaration*) field->type()->user_data(
											UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
							if (has_cyclic_members(object, field_type->members())) {
								error(field->location(),
										"Struct member `" + object->name() + "."
												+ member->name() + "' of type `"
												+ field->type()->base_type()
												+ "' causes a cycle in the struct layout");
							}
						}
					}
				}
			}
		}
	}

	inline bool has_cyclic_members(CodeTypeDeclaration* root,
			CodeTypeMemberCollection* members) {
		bool ret = false;
		for (auto member : *members) {
			if (member->type_of(CodeObjectKind::CodeMemberField)) {
				CodeMemberField* field = (CodeMemberField*) member;
				if (is_cyclic_member_field(root, field)) {
					ret = true;
				} else {
					if (field->type()->user_data(
							UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION)
							!= nullptr) {
						CodeTypeDeclaration* field_type =
								(CodeTypeDeclaration*) field->type()->user_data(
										UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
						ret = has_cyclic_members(root, field_type->members());
					}
				}
			}
		}
		return ret;
	}

	inline bool is_cyclic_member_field(CodeTypeDeclaration* root,
			CodeMemberField* field) {
		CodeTypeDeclaration* field_type =
				(CodeTypeDeclaration*) field->type()->user_data(
						UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
		return root == field_type;
	}
};

MLangSemanticAnalysis::MLangSemanticAnalysis(const MLangDomProvider& p) :
		m_provider(p) {

}

MLangSemanticAnalysis::MLangSemanticAnalysis(const MLangSemanticAnalysis& orig) :
		m_provider(orig.m_provider) {

}

MLangSemanticAnalysis::~MLangSemanticAnalysis() {

}

void MLangSemanticAnalysis::analyse(CodeCompileUnit* compile_unit) {
	LoadTypes types(this->errors());
	compile_unit->accept(&types);

	auto b = types.type_declarations();
	ResolveReferences resolve_references(this->errors(), b);
	compile_unit->accept(&resolve_references);

	DetectCyclicStructures detect_cyclic_structures(this->errors());
	compile_unit->accept(&detect_cyclic_structures);
}

vector<p_CompilerError>&
MLangSemanticAnalysis::errors() {
	return this->m_errors;
}

