#include <omega.hh>

namespace omega {

CodeFieldReferenceExpression::CodeFieldReferenceExpression()
    : CodeExpression() {
  this->m_field_name = "";
  this->m_target_object = nullptr;
}

CodeFieldReferenceExpression::~CodeFieldReferenceExpression() {}

std::string CodeFieldReferenceExpression::field_name() {
  return this->m_field_name;
}

void CodeFieldReferenceExpression::field_name(std::string name) {
  this->m_field_name = name;
}

CodeExpression* CodeFieldReferenceExpression::target_object() {
  return this->m_target_object;
}

void CodeFieldReferenceExpression::target_object(
    CodeExpression* target_object) {
  this->m_target_object = target_object;
}

void CodeFieldReferenceExpression::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

bool CodeFieldReferenceExpression::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeFieldReferenceExpression ||
         CodeExpression::type_of(kind);
}

void CodeFieldReferenceExpression::scope(CodeScope* scope) {
  CodeExpression::scope(scope);
  if (this->m_target_object != nullptr) this->m_target_object->scope(scope);
}
}
