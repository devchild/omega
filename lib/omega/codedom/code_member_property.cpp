#include <omega.hh>

namespace omega {
CodeMemberProperty::CodeMemberProperty() : CodeTypeMember() {}
CodeMemberProperty::~CodeMemberProperty() {}
void CodeMemberProperty::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}
bool CodeMemberProperty::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeMemberProperty ||
         CodeTypeMember::type_of(kind);
}
void CodeMemberProperty::scope(CodeScope* scope) {
  CodeTypeMember::scope(scope);

  CodeScope* current_scope = scope->begin_scope();
  for (auto x : this->get_statements()) x->scope(current_scope);
  current_scope = current_scope->end_scope();

  current_scope = scope->begin_scope();
  for (auto x : this->set_statements()) x->scope(current_scope);
  current_scope = current_scope->end_scope();
}

CodeStatementCollection& CodeMemberProperty::get_statements() {
  return this->m_get_statements;
}
CodeStatementCollection& CodeMemberProperty::set_statements() {
  return this->m_set_statements;
}
}
