#include <omega.hh>

namespace omega {
CodeTypeDeclaration::CodeTypeDeclaration() : CodeTypeMember() {
  this->m_is_class = false;
  this->m_is_struct = false;
  this->m_name = "";
  this->m_members = new CodeTypeMemberCollection();
}

CodeTypeMemberCollection *CodeTypeDeclaration::members() {
  return this->m_members;
}

std::string CodeTypeDeclaration::name() { return this->m_name; }

void CodeTypeDeclaration::name(std::string value) { this->m_name = value; }

bool CodeTypeDeclaration::is_class() { return this->m_is_class; }

void CodeTypeDeclaration::is_class(bool value) { this->m_is_class = value; }

bool CodeTypeDeclaration::is_embedded() { return this->m_is_embedded; }

void CodeTypeDeclaration::is_embedded(bool value) {
  this->m_is_embedded = value;
}

bool CodeTypeDeclaration::is_struct() { return this->m_is_struct; }

void CodeTypeDeclaration::is_struct(bool value) { this->m_is_struct = value; }

void CodeTypeDeclaration::accept(ICodeObjectVisitor *visitor) {
  visitor->visit(this);
}

bool CodeTypeDeclaration::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeTypeDeclaration ||
         CodeTypeMember::type_of(kind);
}

void CodeTypeDeclaration::scope(CodeScope *scope) {
  CodeTypeMember::scope(scope);
  auto current_scope = scope->begin_scope();
  for (auto x : *this->members()) {
    x->scope(current_scope);
  }
  current_scope = current_scope->end_scope();
}
}
