/*
 * File:   code_asm_block_statement.hh
 * Author: mario
 *
 * Created on September 21, 2014, 8:57 PM
 */

#ifndef CODE_ASSEMBLY_CALL_EXPRESSION_HH
#define CODE_ASSEMBLY_CALL_EXPRESSION_HH

#include "code_expression.hh"

namespace omega {
class CodeScope;
class CodeExpression;
class ICodeObjectVisitor;

class CodeAssemblyCallExpression : public CodeExpression {
 public:
  using CodeObject::scope;
  CodeAssemblyCallExpression();
  ~CodeAssemblyCallExpression();
  virtual void accept(ICodeObjectVisitor* visitor) override;

  void content(std::string value);
  std::string content();

  void constraints(std::string value);
  std::string constraints();

  CodeTypeReference* return_type();
  void return_type(CodeTypeReference* value);

  CodeExpressionCollection* parameters();

  virtual bool type_of(CodeObjectKind kind) override;
  void scope(CodeScope* scope) override;

 private:
  CodeTypeReference* m_return_type;
  std::string m_content;
  std::string m_constraints;
  CodeExpressionCollection* m_parameters;
};
}

#endif /* CODE_ASSEMBLY_CALL_EXPRESSION_HH */
