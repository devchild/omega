/*
 * File:   code_expression.cpp
 * Author: mario
 *
 * Created on September 11, 2014, 9:34 AM
 */

#include "omega.hh"

namespace omega {
CodeExpression::CodeExpression() : CodeObject() {}

CodeExpression::~CodeExpression() {}

bool CodeExpression::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeExpression || CodeObject::type_of(kind);
}

void CodeExpression::scope(CodeScope* scope) { CodeObject::scope(scope); }
}
