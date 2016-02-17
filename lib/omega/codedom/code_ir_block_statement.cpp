#include <mlang.hh>

namespace mlang {
CodeIrBlockStatement::CodeIrBlockStatement() : CodeStatement() {
  this->m_content = "";
}

CodeIrBlockStatement::~CodeIrBlockStatement() {}

void CodeIrBlockStatement::accept(ICodeObjectVisitor* visitor) {
  visitor->visit(this);
}

void CodeIrBlockStatement::content(std::string value) {
  this->m_content = value;
}

std::string CodeIrBlockStatement::content() { return this->m_content; }

bool CodeIrBlockStatement::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeIrBlockStatement ||
         CodeStatement::type_of(kind);
}

void CodeIrBlockStatement::scope(CodeScope* scope) {
  CodeStatement::scope(scope);
}
}
