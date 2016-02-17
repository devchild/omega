/*
 * File:   code_parameter_declaration_expression.hh
 * Author: mario
 *
 * Created on September 3, 2014, 11:11 PM
 */

#ifndef CODE_PARAMETER_DECLARATION_EXPRESSION_HH
#define CODE_PARAMETER_DECLARATION_EXPRESSION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

#include "code_expression.hh"
#include "code_member_method.hh"

namespace omega {
class CodeParameterDeclarationExpression : public CodeExpression {
 public:
  using CodeObject::scope;
  CodeParameterDeclarationExpression();
  virtual ~CodeParameterDeclarationExpression();

  void type(CodeTypeReference* value);
  CodeTypeReference* type();

  std::string name();
  void name(std::string name);

  virtual void accept(ICodeObjectVisitor* visitor);

  CodeMemberMethod* parent_method();
  virtual bool type_of(CodeObjectKind kind);
  virtual void scope(CodeScope* scope);

 private:
  std::string m_name;
  CodeTypeReference* m_type;
};
}

#endif /* CODE_PARAMETER_DECLARATION_EXPRESSION_HH */
