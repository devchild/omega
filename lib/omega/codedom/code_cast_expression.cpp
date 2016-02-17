#include <mlang.hh>

namespace mlang {

CodeCastExpression::CodeCastExpression() : CodeExpression() {
  this->m_expression = nullptr;
  this->m_target_type = nullptr;
}

CodeCastExpression::~CodeCastExpression() {}

CodeTypeReference* CodeCastExpression::target_type() {
  return this->m_target_type;
}

void CodeCastExpression::target_type(CodeTypeReference* value) {
  this->m_target_type = value;
}

CodeExpression* CodeCastExpression::expression() { return this->m_expression; }

void CodeCastExpression::expression(CodeExpression* value) {
  this->m_expression = value;
}

void CodeCastExpression::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

bool CodeCastExpression::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeCastExpression ||
         CodeExpression::type_of(kind);
}

void CodeCastExpression::scope(CodeScope* scope) {
  CodeExpression::scope(scope);

  if (this->target_type() != nullptr) this->target_type()->scope(scope);

  if (this->expression() != nullptr) this->expression()->scope(scope);
}
}
