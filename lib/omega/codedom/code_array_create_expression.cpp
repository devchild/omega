/* Copyright 2016 DevChild BVBA */

#include <omega.hh>

namespace omega {

CodeArrayCreateExpression::~CodeArrayCreateExpression() {}

CodeArrayCreateExpression::CodeArrayCreateExpression() : CodeExpression() {
  this->m_create_type = nullptr;
  this->m_size_expression = nullptr;
}

void CodeArrayCreateExpression::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

bool CodeArrayCreateExpression::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeArrayCreateExpression ||
         CodeExpression::type_of(kind);
}

void CodeArrayCreateExpression::scope(CodeScope* scope) {
  CodeExpression::scope(scope);
  if (this->m_create_type != nullptr) this->m_create_type->scope(scope);

  if (this->m_size_expression != nullptr) this->m_size_expression->scope(scope);
}

CodeExpression* CodeArrayCreateExpression::size_expression() {
  return this->m_size_expression;
}

void CodeArrayCreateExpression::size_expression(CodeExpression* value) {
  this->m_size_expression = value;
}

CodeTypeReference* CodeArrayCreateExpression::create_type() {
  return this->m_create_type;
}

void CodeArrayCreateExpression::create_type(CodeTypeReference* value) {
  this->m_create_type = value;
}
}  // namespace omega
