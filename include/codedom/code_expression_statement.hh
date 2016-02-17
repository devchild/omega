/*
 * File:   code_expression_statement.hh
 * Author: mario
 *
 * Created on September 18, 2014, 7:16 PM
 */

#ifndef CODE_EXPRESSION_STATEMENT_HH
#define CODE_EXPRESSION_STATEMENT_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

#include "code_statement.hh"
#include "code_expression.hh"

namespace omega {
class CodeExpressionStatement : public CodeStatement {
 public:
  using CodeObject::scope;
  CodeExpressionStatement();
  ~CodeExpressionStatement();
  virtual void accept(ICodeObjectVisitor* visitor);

  CodeExpression* expression();
  void expression(CodeExpression* value);
  virtual bool type_of(CodeObjectKind kind);
  virtual void scope(CodeScope* scope);

 private:
  CodeExpression* m_expression;
};
}

#endif /* CODE_EXPRESSION_STATEMENT_HH */
