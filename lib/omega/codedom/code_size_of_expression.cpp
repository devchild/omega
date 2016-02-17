#include <omega.hh>

namespace omega {

CodeSizeOfExpression::CodeSizeOfExpression() : CodeExpression() {
  this->m_type = nullptr;
}

CodeSizeOfExpression::~CodeSizeOfExpression() {}

CodeTypeReference* CodeSizeOfExpression::type() { return this->m_type; }

void CodeSizeOfExpression::type(CodeTypeReference* value) {
  this->m_type = value;
}

void CodeSizeOfExpression::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

bool CodeSizeOfExpression::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeSizeOfExpression ||
         CodeExpression::type_of(kind);
}

void CodeSizeOfExpression::scope(CodeScope* scope) {
  CodeExpression::scope(scope);

  if (this->type() != nullptr) this->type()->scope(scope);
}
}
