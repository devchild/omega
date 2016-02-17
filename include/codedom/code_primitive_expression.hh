/*
 * File:   code_primitive_expression.hh
 * Author: mario
 *
 * Created on September 12, 2014, 9:46 AM
 */

#ifndef CODE_PRIMITIVE_EXPRESSION_HH
#define CODE_PRIMITIVE_EXPRESSION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace mlang {
class CodeTypeReference;

class CodePrimitiveExpression : public CodeExpression {
 public:
  using CodeObject::scope;
  CodePrimitiveExpression();
  virtual ~CodePrimitiveExpression();

  void* value();
  void value(void* value);
  virtual bool type_of(CodeObjectKind kind);
  virtual void accept(ICodeObjectVisitor* visitor);
  virtual void scope(CodeScope* scope);

  CodeTypeReference* type();
  void type(CodeTypeReference* value);

  std::string value_as_string();

 private:
  CodeTypeReference* m_type;
  void* m_value;
};
}

#endif /* CODE_PRIMITIVE_EXPRESSION_HH */
