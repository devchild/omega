/*
 * code_object_create_expression.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: mario
 */
#include <mlang.hh>

namespace mlang {

CodeObjectCreateExpression::CodeObjectCreateExpression()
    : CodeExpression()
{
	this->m_parameters = new CodeExpressionCollection();
	this->m_create_type = nullptr;
}

CodeObjectCreateExpression::~CodeObjectCreateExpression() {
	// TODO Auto-generated destructor stub
}

CodeExpressionCollection *
CodeObjectCreateExpression::parameters() {
	return this->m_parameters;
}

void
CodeObjectCreateExpression::create_type(CodeTypeReference* value) {
	this->m_create_type = value;
}

CodeTypeReference*
CodeObjectCreateExpression::create_type(){
	return this->m_create_type;
}

bool
CodeObjectCreateExpression::type_of(CodeObjectKind kind) {
	return kind == CodeObjectKind::CodeObjectCreateExpression || CodeExpression::type_of(kind);
}

void
CodeObjectCreateExpression::accept(ICodeObjectVisitor* visitor) {
    visitor->visit(this);
}

void
CodeObjectCreateExpression::scope(CodeScope* scope) {
	CodeExpression::scope(scope);

	if (this->create_type() != nullptr)
		this->create_type()->scope(scope);

	for(auto x:*this->parameters()){
		x->scope(scope);
	}
}

} /* namespace mlang */
