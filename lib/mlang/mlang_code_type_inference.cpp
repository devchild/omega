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
void MLangCodeTypeInference::visit(CodeBinaryOperatorExpression* object) {
	std::list<CodeTypeDeclaration*> params;

	MLangCodeTypeInference inf_left;
	object->left()->accept(&inf_left);
	params.push_back(object->resolve_type(inf_left.result()));

	MLangCodeTypeInference inf_right;
	object->right()->accept(&inf_right);
	params.push_back(object->resolve_type(inf_right.result()));

	std::string method_name = "";
	switch(object->operator_()) {
	case CodeBinaryOperatorType::Add:
		method_name = "add";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::Divide:
		method_name = "divide";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::Subtract:
		method_name = "subtract";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::Multiply:
		method_name = "multiply";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::BitwiseOr:
		method_name = "bitwise_or";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::BooleanOr:
		method_name = "boolean_or";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::BitwiseAnd:
		method_name = "bitwise_and";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::BooleanAnd:
		method_name = "boolean_or";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::ExlusiveOr:
		method_name = "exclusive_or";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::IdentityEquality:
		method_name = "equals";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::IdentityInEquality:
		method_name = "not_equals";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::LessThan:
		method_name = "not_equals";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::LessThanOrEqual:
		method_name = "not_equals";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::GreaterThan:
		method_name = "not_equals";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::GreaterThanOrEqual:
		method_name = "not_equals";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::Modulus:
		method_name = "modulus";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::ShiftLeft:
		method_name = "shift_left";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	case CodeBinaryOperatorType::ShiftRight:
		method_name = "shift_right";
		this->m_result = object->resolve_method(method_name, &params)->return_type();
		break;
	}
}
void MLangCodeTypeInference::visit(CodeCompileUnit* object) {
}
void MLangCodeTypeInference::visit(CodeConditionStatement* object) {
}
void MLangCodeTypeInference::visit(CodeExpression* object) {
}
void MLangCodeTypeInference::visit(CodeExpressionStatement* object) {
}
void MLangCodeTypeInference::visit(CodeIterationStatement* object) {
}
void MLangCodeTypeInference::visit(CodeMemberField* object) {
	this->m_result = object->type();
}
void MLangCodeTypeInference::visit(CodeMemberMethod* object) {
	this->m_result = object->return_type();
}
void MLangCodeTypeInference::visit(CodeMemberProperty* object) {
}
void MLangCodeTypeInference::visit(CodeMethodInvokeExpression* object) {
	std::list<CodeTypeDeclaration*> param_types;

	if (object->method()->target_object() != nullptr) {
		MLangCodeTypeInference param_inf;
		object->method()->target_object()->accept(&param_inf);
		param_types.push_back(object->resolve_type(param_inf.result()));
	}

	for (auto p: *object->parameters()) {
		MLangCodeTypeInference param_inf;
		p->accept(&param_inf);
		param_types.push_back(object->resolve_type(param_inf.result()));
	}

	auto method = object->resolve_method(object->method()->method_name(), &param_types);
	this->m_result = method->return_type();
}
void MLangCodeTypeInference::visit(CodeFileImport* object) {
}
void MLangCodeTypeInference::visit(CodeArrayCreateExpression* object) {
	this->m_result = object->create_type();
}
void MLangCodeTypeInference::visit(CodeFieldReferenceExpression* object) {
	MLangCodeTypeInference exp_inf;
	object->target_object()->accept(&exp_inf);
	auto target_object_type = object->resolve_type(exp_inf.result());


	for (auto x : *target_object_type->members()) {
		if (x->name() == object->field_name())
		{
			auto field = static_cast<CodeMemberField*>(x);
			this->m_result = field->type();
			break;
		}
	}
}
void MLangCodeTypeInference::visit(CodeArrayIndexerExpression* object) {
	MLangCodeTypeInference exp_inf;
	object->target_object()->accept(&exp_inf);
	this->m_result = exp_inf.result()->array_element_type();
}
void MLangCodeTypeInference::visit(CodeMethodReferenceExpression* object) {
}
void MLangCodeTypeInference::visit(CodeMethodReturnStatement* object) {
	MLangCodeTypeInference exp_inf;
	object->expression()->accept(&exp_inf);
	this->m_result = exp_inf.result();
}
void MLangCodeTypeInference::visit(CodeNamespace* object) {
}
void MLangCodeTypeInference::visit(CodeObject* object) {
}
void MLangCodeTypeInference::visit(CodeParameterDeclarationExpression* object) {
	this->m_result = object->type();
}
void MLangCodeTypeInference::visit(CodePrimitiveExpression* object) {
	this->m_result = object->type();
}
void MLangCodeTypeInference::visit(CodeStatement* object) {
}
void MLangCodeTypeInference::visit(CodeTypeDeclaration* object) {
}
void MLangCodeTypeInference::visit(CodeTypeMember* object) {
}
void MLangCodeTypeInference::visit(CodeTypeReference* object) {
	this->m_result = object;
}
void MLangCodeTypeInference::visit(CodeVariableDeclarationStatement* object) {
	this->m_result = object->type();
}
void MLangCodeTypeInference::visit(CodeVariableReferenceExpression* object) {
	auto res = object->resolve_variable(object->variable_name());

	MLangCodeTypeInference exp_inf;
	res->back()->accept(&exp_inf);
	this->m_result = exp_inf.result();
}

void MLangCodeTypeInference::visit(CodeAssignExpression* object) {
	MLangCodeTypeInference exp_inf;
	object->left()->accept(&exp_inf);
	this->m_result = exp_inf.result();
}
void MLangCodeTypeInference::visit(CodeCastExpression* object) {
	this->m_result = object->target_type();
}
void MLangCodeTypeInference::visit(CodeObjectCreateExpression* object) {
	this->m_result = object->create_type();
}
void MLangCodeTypeInference::visit(CodeIrBlockStatement* object) {
	auto res = new CodeTypeReference();
	res->base_type("Void");
	this->m_result = res;
}

void MLangCodeTypeInference::visit(CodeAssemblyCallExpression* object) {
	auto res = new CodeTypeReference();
	res->base_type("Void");
	this->m_result = res;
}
