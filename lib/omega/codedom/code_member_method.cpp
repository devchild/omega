#include <mlang.hh>

namespace mlang {
CodeMemberMethod::CodeMemberMethod() : CodeTypeMember() {
  this->m_return_type = nullptr;
  this->m_parameters = new CodeParameterDeclarationExpressionCollection();
  this->m_statements = new CodeStatementCollection();
  this->m_attributes = MemberAttributes::Private;
}

CodeMemberMethod::~CodeMemberMethod() {}

CodeStatementCollection* CodeMemberMethod::statements() {
  return this->m_statements;
}

CodeParameterDeclarationExpressionCollection* CodeMemberMethod::parameters() {
  return this->m_parameters;
}

void CodeMemberMethod::return_type(CodeTypeReference* value) {
  this->m_return_type = value;
}

CodeTypeReference* CodeMemberMethod::return_type() {
  return this->m_return_type;
}

void CodeMemberMethod::attributes(MemberAttributes value) {
  this->m_attributes = value;
}

MemberAttributes CodeMemberMethod::attributes() { return this->m_attributes; }

std::string CodeMemberMethod::id() {
  if (this->m_attributes == MemberAttributes::External ||
      this->m_attributes == MemberAttributes::Public)
    return this->name();
  else
    return CodeObject::id();
}

void CodeMemberMethod::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

bool CodeMemberMethod::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeMemberMethod ||
         CodeTypeMember::type_of(kind);
}

void CodeMemberMethod::scope(CodeScope* scope) {
  CodeTypeMember::scope(scope);

  if (this->m_return_type != nullptr) this->m_return_type->scope(scope);

  // method_scope
  CodeScope* current_scope = scope->begin_scope();
  for (auto x : *this->parameters()) x->scope(current_scope);

  // body_scope
  current_scope = current_scope->begin_scope();
  for (auto x : *this->statements()) x->scope(current_scope);
  current_scope = current_scope->end_scope();
  // end body_scope

  current_scope = current_scope->end_scope();
  // end method_scope
}
}
