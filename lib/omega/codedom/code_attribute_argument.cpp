#include <omega.hh>

namespace omega {
CodeAttributeArgument::CodeAttributeArgument() : CodeObject() {
  this->m_name = "";
}

CodeAttributeArgument::~CodeAttributeArgument() {}

void CodeAttributeArgument::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

void CodeAttributeArgument::scope(CodeScope* scope) {
  CodeObject::scope(scope);
}

bool CodeAttributeArgument::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeAttributeArgument ||
         CodeObject::type_of(kind);
}

std::string CodeAttributeArgument::name() { return this->m_name; }

void CodeAttributeArgument::name(std::string value) { this->m_name = value; }

CodeExpression* CodeAttributeArgument::value() { return this->m_value; }

void CodeAttributeArgument::value(CodeExpression* value) {
  this->m_value = value;
}
}
