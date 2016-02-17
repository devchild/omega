#include <omega.hh>

namespace omega {
CodeIterationStatement::CodeIterationStatement() : CodeStatement() {
  this->m_increment_statement = nullptr;
  this->m_init_statement = nullptr;
  this->m_test_expression = nullptr;
  this->m_statements = new CodeStatementCollection();
}

CodeIterationStatement::~CodeIterationStatement() {}

void CodeIterationStatement::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

CodeStatement* CodeIterationStatement::increment_statement() {
  return this->m_increment_statement;
}

CodeStatement* CodeIterationStatement::init_statement() {
  return this->m_init_statement;
}

CodeStatementCollection* CodeIterationStatement::statements() {
  return this->m_statements;
}

void CodeIterationStatement::increment_statement(CodeStatement* value) {
  this->m_increment_statement = value;
}

void CodeIterationStatement::init_statement(CodeStatement* value) {
  this->m_init_statement = value;
}

CodeExpression* CodeIterationStatement::test_expression() {
  return this->m_test_expression;
}

void CodeIterationStatement::test_expression(CodeExpression* value) {
  this->m_test_expression = value;
}

bool CodeIterationStatement::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeIterationStatement ||
         CodeStatement::type_of(kind);
}

void CodeIterationStatement::scope(CodeScope* scope) {
  CodeStatement::scope(scope);

  CodeScope* current_scope = scope->begin_scope();

  if (this->m_init_statement != nullptr)
    this->m_init_statement->scope(current_scope);

  if (this->m_test_expression != nullptr)
    this->m_test_expression->scope(current_scope);

  if (this->m_increment_statement != nullptr)
    this->m_increment_statement->scope(current_scope);

  for (auto x : *this->statements()) x->scope(current_scope);

  current_scope = current_scope->end_scope();
}
}
