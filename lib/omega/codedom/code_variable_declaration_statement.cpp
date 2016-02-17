#include <omega.hh>

namespace omega {

CodeVariableDeclarationStatement::CodeVariableDeclarationStatement()
    : CodeStatement() {
  this->m_init_expression = nullptr;
  this->m_type = nullptr;
  this->m_name = "";
}

CodeVariableDeclarationStatement::~CodeVariableDeclarationStatement() {}

CodeMemberMethod* CodeVariableDeclarationStatement::parent_method() {
  return (CodeMemberMethod*)this->parent();
}

std::string CodeVariableDeclarationStatement::name() { return this->m_name; }

CodeTypeReference* CodeVariableDeclarationStatement::type() {
  return this->m_type;
}

CodeExpression* CodeVariableDeclarationStatement::init_expression() {
  return this->m_init_expression;
}

void CodeVariableDeclarationStatement::name(std::string value) {
  this->m_name = value;
}

void CodeVariableDeclarationStatement::type(CodeTypeReference* value) {
  this->m_type = value;
}

void CodeVariableDeclarationStatement::init_expression(CodeExpression* value) {
  this->m_init_expression = value;
}

void CodeVariableDeclarationStatement::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

bool CodeVariableDeclarationStatement::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeVariableDeclarationStatement ||
         CodeStatement::type_of(kind);
}

void CodeVariableDeclarationStatement::scope(CodeScope* scope) {
  CodeStatement::scope(scope);

  if (this->m_type != nullptr) this->m_type->scope(scope);

  if (this->m_init_expression != nullptr) this->m_init_expression->scope(scope);
}
}
