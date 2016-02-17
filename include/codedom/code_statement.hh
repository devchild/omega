/*
 * File:   code_statement.hh
 * Author: mario
 *
 * Created on September 3, 2014, 10:59 PM
 */

#ifndef CODE_STATEMENT_HH
#define CODE_STATEMENT_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"
#include "code_scope.hh"

namespace mlang {
class CodeStatement : public CodeObject {
 public:
  using CodeObject::scope;
  CodeStatement();
  ~CodeStatement();
  virtual void scope(CodeScope* scope);
  virtual bool type_of(CodeObjectKind kind);
  virtual void accept(ICodeObjectVisitor* visitor) = 0;
};
}

#endif /* CODE_STATEMENT_HH */
