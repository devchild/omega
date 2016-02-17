#include <mlang.hh>

namespace mlang {
CodeAssignExpression::CodeAssignExpression() : CodeExpression() {
  this->m_left = nullptr;
  this->m_right = nullptr;
}

CodeAssignExpression::~CodeAssignExpression() {}

void CodeAssignExpression::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

void CodeAssignExpression::left(CodeExpression* value) { this->m_left = value; }

CodeExpression* CodeAssignExpression::left() { return this->m_left; }

void CodeAssignExpression::right(CodeExpression* value) {
  this->m_right = value;
}

CodeExpression* CodeAssignExpression::right() { return this->m_right; }

void CodeAssignExpression::scope(CodeScope* scope) {
  CodeExpression::scope(scope);
  if (this->m_left != nullptr) this->m_left->scope(scope);
  if (this->m_right != nullptr) this->m_right->scope(scope);
}

bool CodeAssignExpression::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeAssignExpression ||
         CodeExpression::type_of(kind);
}
}
