/*
 * File:   code_array_creation_expression.hh
 * Author: mario
 *
 * Created on September 21, 2014, 8:57 PM
 */

#ifndef CODE_ARRAY_INDEXER_EXPRESSION_HH
#define CODE_ARRAY_INDEXER_EXPRESSION_HH

#include "code_expression.hh"

namespace omega {
class CodeScope;
class ICodeObjectVisitor;

class CodeArrayIndexerExpression : public CodeExpression {
 public:
  using CodeObject::scope;
  CodeArrayIndexerExpression();
  ~CodeArrayIndexerExpression();
  virtual void accept(ICodeObjectVisitor* visitor) override;

  virtual bool type_of(CodeObjectKind kind) override;
  void scope(CodeScope* scope) override;

  CodeExpressionCollection* indices();

  CodeExpression* target_object();
  void target_object(CodeExpression* value);

 private:
  CodeExpressionCollection* m_indices;
  CodeExpression* m_target_object;
};
}

#endif /* CODE_ARRAY_INDEXER_EXPRESSION_HH */
