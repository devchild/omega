#include <mlang.hh>

namespace mlang {

CodeTypeReference::CodeTypeReference() : CodeObject() {
  this->m_base_type = "";
  this->m_array_rank = 0;
  this->m_array_element_type = nullptr;
}

std::string CodeTypeReference::base_type() { return this->m_base_type; }

void CodeTypeReference::base_type(std::string value) {
  this->m_base_type = value;
}

void CodeTypeReference::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

bool CodeTypeReference::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeTypeReference || CodeObject::type_of(kind);
}

void CodeTypeReference::scope(CodeScope* scope) {
  CodeObject::scope(scope);

  if (this->m_array_element_type != nullptr)
    this->m_array_element_type->scope(scope);
}

void CodeTypeReference::array_element_type(CodeTypeReference* value) {
  this->m_array_element_type = value;
}

CodeTypeReference* CodeTypeReference::array_element_type() {
  return this->m_array_element_type;
}

int CodeTypeReference::array_rank() { return this->m_array_rank; }

void CodeTypeReference::array_rank(int value) { this->m_array_rank = value; }
}
