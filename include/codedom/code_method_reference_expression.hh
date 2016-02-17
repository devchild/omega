/*
 * File:   code_method_reference_expression.hh
 * Author: mario
 *
 * Created on September 18, 2014, 9:42 AM
 */

#ifndef CODE_METHOD_REFERENCE_EXPRESSION_HH
#define CODE_METHOD_REFERENCE_EXPRESSION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

#include "code_expression.hh"

namespace omega {
class CodeMethodReferenceExpression : public CodeExpression {
 public:
  using CodeObject::scope;
  CodeMethodReferenceExpression();
  virtual ~CodeMethodReferenceExpression();

  std::string method_name();
  void method_name(std::string value);

  CodeExpression* target_object();
  void target_object(CodeExpression* value);

  CodeTypeReferenceCollection& type_arguments();

  virtual void accept(ICodeObjectVisitor* visitor);
  virtual bool type_of(CodeObjectKind kind);
  virtual void scope(CodeScope* scope);

 private:
  std::string m_method_name;
  CodeExpression* m_target_object;
  CodeTypeReferenceCollection* m_type_arguments;
};
}

#endif /* CODE_METHOD_REFERENCE_EXPRESSION_HH */
