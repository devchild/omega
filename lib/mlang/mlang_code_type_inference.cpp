#include "codedom.hh"
#include "mlang_code_type_inference.hh"

# include <iostream>

MLangCodeTypeInference::MLangCodeTypeInference() {
	this->m_result = nullptr;
}
MLangCodeTypeInference::~MLangCodeTypeInference() {
}
CodeTypeReference*
MLangCodeTypeInference::result() {
	return this->m_result;
}
void MLangCodeTypeInference::on_visit(CodeBinaryOperatorExpression* object) {
	std::list<CodeTypeDeclaration*> params;

	MLangCodeTypeInference inf_left;
	object->left()->accept(&inf_left);
	params.push_back((CodeTypeDeclaration*) inf_left.result()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION));

	MLangCodeTypeInference inf_right;
	object->right()->accept(&inf_right);
	params.push_back((CodeTypeDeclaration*) inf_right.result()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION));

	std::string method_name = "";
	switch (object->operator_()) {
	case CodeBinaryOperatorType::Add:
		method_name = "add";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::Divide:
		method_name = "divide";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::Subtract:
		method_name = "subtract";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::Multiply:
		method_name = "multiply";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::BitwiseOr:
		method_name = "bitwise_or";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::BooleanOr:
		method_name = "boolean_or";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::BitwiseAnd:
		method_name = "bitwise_and";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::BooleanAnd:
		method_name = "boolean_or";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::ExlusiveOr:
		method_name = "exclusive_or";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::IdentityEquality:
		method_name = "equals";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::IdentityInEquality:
		method_name = "not_equals";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::LessThan:
		method_name = "not_equals";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::LessThanOrEqual:
		method_name = "not_equals";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::GreaterThan:
		method_name = "not_equals";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::GreaterThanOrEqual:
		method_name = "not_equals";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::Modulus:
		method_name = "modulus";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::ShiftLeft:
		method_name = "shift_left";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::ShiftRight:
		method_name = "shift_right";
		this->m_result =
				object->resolve_method(method_name, &params)->return_type();
		break;
	}
}
void MLangCodeTypeInference::on_visit(CodeCompileUnit* object) {
}
void MLangCodeTypeInference::on_visit(CodeConditionStatement* object) {
}
void MLangCodeTypeInference::on_visit(CodeExpression* object) {
}
void MLangCodeTypeInference::on_visit(CodeExpressionStatement* object) {
}
void MLangCodeTypeInference::on_visit(CodeIterationStatement* object) {
}
void MLangCodeTypeInference::on_visit(CodeMemberField* object) {
	this->m_result = object->type();
}
void MLangCodeTypeInference::on_visit(CodeMemberMethod* object) {
	this->m_result = object->return_type();
	if (this->m_result == nullptr) {
		for (auto x : *object->statements()) {
			if (x->type_of(CodeObjectKind::CodeMethodReturnStatement)) {
				CodeMethodReturnStatement* return_statement =
						(CodeMethodReturnStatement*) x;
				MLangCodeTypeInference inf;
				return_statement->accept(&inf);
				this->m_result = inf.result();
			}
		}
	}
}
void MLangCodeTypeInference::on_visit(CodeMemberProperty* object) {
}
void MLangCodeTypeInference::on_visit(CodeMethodInvokeExpression* object) {
	std::list<CodeTypeDeclaration*> param_types;

	if (object->method()->target_object() != nullptr) {
		MLangCodeTypeInference param_inf;
		object->method()->target_object()->accept(&param_inf);
		param_types.push_back(
				(CodeTypeDeclaration*) param_inf.result()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION));
	}

	for (auto p : *object->parameters()) {
		MLangCodeTypeInference param_inf;
		p->accept(&param_inf);
		param_types.push_back(
				(CodeTypeDeclaration*) param_inf.result()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION));
	}

	auto method = (CodeMemberMethod*)object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_METHOD); //object->resolve_method(object->method()->method_name(), &param_types);
	this->m_result = method->return_type();
}
void MLangCodeTypeInference::on_visit(CodeFileInclude* object) {
}
void MLangCodeTypeInference::on_visit(CodeArrayCreateExpression* object) {
	this->m_result = object->create_type();
}
void MLangCodeTypeInference::on_visit(CodeFieldReferenceExpression* object) {
	MLangCodeTypeInference exp_inf;
	object->target_object()->accept(&exp_inf);
	auto target_object_type = (CodeTypeDeclaration*) exp_inf.result()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);

	for (auto x : *target_object_type->members()) {
		if (x->name() == object->field_name()) {
			auto field = static_cast<CodeMemberField*>(x);
			this->m_result = field->type();
			break;
		}
	}
}
void MLangCodeTypeInference::on_visit(CodeArrayIndexerExpression* object) {
	MLangCodeTypeInference exp_inf;
	object->target_object()->accept(&exp_inf);
	this->m_result = exp_inf.result()->array_element_type();
}
void MLangCodeTypeInference::on_visit(CodeMethodReferenceExpression* object) {
}
void MLangCodeTypeInference::on_visit(CodeMethodReturnStatement* object) {
	MLangCodeTypeInference exp_inf;
	object->expression()->accept(&exp_inf);
	this->m_result = exp_inf.result();
}
void MLangCodeTypeInference::on_visit(CodeNamespace* object) {
}
void MLangCodeTypeInference::on_visit(CodeObject* object) {
}
void MLangCodeTypeInference::on_visit(CodeParameterDeclarationExpression* object) {
	this->m_result = object->type();
}
void MLangCodeTypeInference::on_visit(CodePrimitiveExpression* object) {
	this->m_result = object->type();
}
void MLangCodeTypeInference::on_visit(CodeStatement* object) {
}
void MLangCodeTypeInference::on_visit(CodeTypeDeclaration* object) {
}
void MLangCodeTypeInference::on_visit(CodeTypeMember* object) {
}
void MLangCodeTypeInference::on_visit(CodeTypeReference* object) {
	this->m_result = object;
}
void MLangCodeTypeInference::on_visit(CodeVariableDeclarationStatement* object) {
	this->m_result = object->type();
}
void MLangCodeTypeInference::on_visit(CodeVariableReferenceExpression* object) {
	auto res = object->resolve_variable(object->variable_name());

	MLangCodeTypeInference exp_inf;
	res->back()->accept(&exp_inf);
	this->m_result = exp_inf.result();
}

void MLangCodeTypeInference::on_visit(CodeAssignExpression* object) {
	MLangCodeTypeInference exp_inf;
	object->left()->accept(&exp_inf);
	this->m_result = exp_inf.result();
}
void MLangCodeTypeInference::on_visit(CodeCastExpression* object) {
	this->m_result = object->target_type();
}
void MLangCodeTypeInference::on_visit(CodeObjectCreateExpression* object) {
	this->m_result = object->create_type();
}
void MLangCodeTypeInference::on_visit(CodeIrBlockStatement* object) {
	auto res = new CodeTypeReference();
	res->base_type("Void");
	this->m_result = res;
}

void MLangCodeTypeInference::on_visit(CodeSizeOfExpression* object) {
	auto res = new CodeTypeReference();
	res->base_type("UInt64");
	this->m_result = res;
}

void MLangCodeTypeInference::on_visit(CodeAssemblyCallExpression* object) {
	auto res = new CodeTypeReference();
	res->base_type("Void");
	this->m_result = res;
}

void MLangCodeTypeInference::on_visit(CodeAttributeDeclaration* object) {

}

void MLangCodeTypeInference::on_visit(CodeAttributeArgument* object) {

}
