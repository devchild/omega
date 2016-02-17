/*
 * File:   code_binary_operator_expression.hh
 * Author: mario
 *
 * Created on September 10, 2014, 9:42 AM
 */

#ifndef CODE_BINARY_OPERATOR_EXPRESSION_HH
#define CODE_BINARY_OPERATOR_EXPRESSION_HH

#include "code_expression.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace omega {

enum class CodeBinaryOperatorType {
  None,
  Add,
  Subtract,
  IdentityEquality,
  IdentityInEquality,
  Modulus,
  GreaterThan,
  GreaterThanOrEqual,
  LessThan,
  LessThanOrEqual,
  Multiply,
  Divide,
  BitwiseAnd,
  BitwiseOr,
  ExlusiveOr,
  BooleanAnd,
  BooleanOr,
  ShiftLeft,
  ShiftRight

};

class CodeBinaryOperatorExpression : public CodeExpression {
 public:
  using CodeObject::scope;
  CodeBinaryOperatorExpression();
  ~CodeBinaryOperatorExpression();

  CodeExpression* left();
  CodeBinaryOperatorType operator_();
  CodeExpression* right();

  void left(CodeExpression* value);
  void operator_(const CodeBinaryOperatorType value);
  void right(CodeExpression* value);
  virtual void accept(ICodeObjectVisitor* visitor);

  virtual bool type_of(CodeObjectKind kind);
  virtual void scope(CodeScope* scope);

 private:
  CodeExpression* m_left;
  CodeBinaryOperatorType m_operator;
  CodeExpression* m_right;
};
}

#endif /* CODE_BINARY_OPERATOR_EXPRESSION_HH */
