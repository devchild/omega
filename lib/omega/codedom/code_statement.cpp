#include <omega.hh>

namespace omega {

CodeStatement::CodeStatement() : CodeObject() {}

CodeStatement::~CodeStatement() {}

bool CodeStatement::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeStatement || CodeObject::type_of(kind);
}

void CodeStatement::scope(CodeScope* scope) { CodeObject::scope(scope); }
}
