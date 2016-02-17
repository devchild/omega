/*
 * File:   code_method_return_statement.hh
 * Author: mario
 *
 * Created on September 3, 2014, 11:33 PM
 */

#ifndef CODE_METHOD_RETURN_STATEMENT_HH
#define CODE_METHOD_RETURN_STATEMENT_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace omega {
class CodeMethodReturnStatement : public CodeStatement {
 public:
  using CodeObject::scope;
  CodeMethodReturnStatement();
  ~CodeMethodReturnStatement();
  CodeExpression* expression();
  void expression(CodeExpression* value);
  virtual void accept(ICodeObjectVisitor* visitor);
  virtual bool type_of(CodeObjectKind kind);
  virtual void scope(CodeScope* scope);

 private:
  CodeExpression* m_expression;
};
}

#endif /* CODE_METHOD_RETURN_STATEMENT_HH */
