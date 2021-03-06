/*
 * File:   code_variable_reference_expression.hh
 * Author: mario
 *
 * Created on September 12, 2014, 9:31 AM
 */

#ifndef CODE_VARIABLE_REFERENCE_EXPRESSION_HH
#define CODE_VARIABLE_REFERENCE_EXPRESSION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace omega {
class CodeVariableReferenceExpression : public CodeExpression {
 public:
  using CodeObject::scope;

  CodeVariableReferenceExpression();
  ~CodeVariableReferenceExpression();

  std::string variable_name();
  void variable_name(std::string name);
  virtual void accept(ICodeObjectVisitor* visitor) override;
  virtual bool type_of(CodeObjectKind kind) override;
  void scope(CodeScope* scope) override;

 private:
  std::string m_variable_name;
};
}

#endif /* CODE_VARIABLE_REFERENCE_EXPRESSION_HH */
