/*
 * File:   code_asm_block_statement.hh
 * Author: mario
 *
 * Created on September 21, 2014, 8:57 PM
 */

#ifndef CODE_SIZE_OF_EXPRESSION_HH
#define CODE_SIZE_OF_EXPRESSION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace omega {
class CodeScope;
class CodeExpression;
class ICodeObjectVisitor;

class CodeSizeOfExpression : public CodeExpression {
 public:
  using CodeObject::scope;
  CodeSizeOfExpression();
  ~CodeSizeOfExpression();
  virtual void accept(ICodeObjectVisitor* visitor) override;

  void type(CodeTypeReference* value);
  CodeTypeReference* type();

  virtual bool type_of(CodeObjectKind kind) override;
  void scope(CodeScope* scope) override;

 private:
  CodeTypeReference* m_type;
};
}

#endif /* CODE_ASSEMBLY_CALL_EXPRESSION_HH */
