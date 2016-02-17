/*
 * code_field_reference_expression.hh
 *
 *  Created on: Dec 16, 2014
 *      Author: mario
 */

#ifndef INCLUDE_CODEDOM_CODE_FIELD_REFERENCE_EXPRESSION_HH
#define INCLUDE_CODEDOM_CODE_FIELD_REFERENCE_EXPRESSION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace omega {
class CodeFieldReferenceExpression : public CodeExpression {
 public:
  using CodeObject::scope;

  CodeFieldReferenceExpression();
  ~CodeFieldReferenceExpression();

  std::string field_name();
  void field_name(std::string field_name);

  CodeExpression* target_object();
  void target_object(CodeExpression* target_object);

  virtual void accept(ICodeObjectVisitor* visitor) override;
  virtual bool type_of(CodeObjectKind kind) override;
  void scope(CodeScope* scope) override;

 private:
  CodeExpression* m_target_object;
  std::string m_field_name;
};
}

#endif /* INCLUDE_CODEDOM_CODE_FIELD_REFERENCE_EXPRESSION_HH_ */
