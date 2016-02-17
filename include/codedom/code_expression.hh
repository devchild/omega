/*
 * File:   code_expression.hh
 * Author: mario
 *
 * Created on September 3, 2014, 11:12 PM
 */

#ifndef CODE_EXPRESSION_HH
#define CODE_EXPRESSION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace omega {
class CodeExpression : public CodeObject {
 public:
  using CodeObject::scope;
  CodeExpression();
  ~CodeExpression();
  virtual void accept(ICodeObjectVisitor* visitor) = 0;
  virtual bool type_of(CodeObjectKind kind);
  virtual void scope(CodeScope* scope);
};
}

#endif /* CODE_EXPRESSION_HH */
