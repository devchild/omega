#include <mlang.hh>

namespace mlang {
CodeMethodReturnStatement::~CodeMethodReturnStatement() {}

CodeMethodReturnStatement::CodeMethodReturnStatement() : CodeStatement() {
  this->m_expression = nullptr;
}

void CodeMethodReturnStatement::expression(CodeExpression* value) {
  this->m_expression = value;
}

CodeExpression* CodeMethodReturnStatement::expression() {
  return this->m_expression;
}

void CodeMethodReturnStatement::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

bool CodeMethodReturnStatement::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeMethodReturnStatement ||
         CodeStatement::type_of(kind);
}

void CodeMethodReturnStatement::scope(CodeScope* scope) {
  CodeStatement::scope(scope);

  if (this->m_expression != nullptr) this->m_expression->scope(scope);
}
}
