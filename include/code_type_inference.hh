/*
 * mlang_code_type_inference.hh
 *
 *  Created on: Nov 11, 2014
 *      Author: mario
 */

#ifndef MLANGCODETYPEINFERENCE_HH
#define MLANGCODETYPEINFERENCE_HH

#include "codedom/code_object_visitor.hh"

namespace mlang {

class CodeTypeInference : public CodeObjectVisitorBase {
 public:
  CodeTypeReference *result();

  CodeTypeInference();

  virtual ~CodeTypeInference();

  static CodeTypeReference *get_type_reference(CodeObject *object);

 protected:
  using CodeObjectVisitorBase::on_visit;

 private:
  /*CodeObjectVisitor*/
  virtual void on_visit(CodeBinaryOperatorExpression *object);

  virtual void on_visit(CodeCompileUnit *object);

  virtual void on_visit(CodeConditionStatement *object);

  virtual void on_visit(CodeExpression *object);

  virtual void on_visit(CodeExpressionStatement *object);

  virtual void on_visit(CodeIterationStatement *object);

  virtual void on_visit(CodeMemberField *object);

  virtual void on_visit(CodeMemberMethod *object);

  virtual void on_visit(CodeMemberProperty *object);

  virtual void on_visit(CodeMethodInvokeExpression *object);

  virtual void on_visit(CodeMethodReferenceExpression *object);

  virtual void on_visit(CodeMethodReturnStatement *object);

  virtual void on_visit(CodeNamespace *object);

  virtual void on_visit(CodeObject *object);

  virtual void on_visit(CodeParameterDeclarationExpression *object);

  virtual void on_visit(CodePrimitiveExpression *object);

  virtual void on_visit(CodeStatement *object);

  virtual void on_visit(CodeTypeDeclaration *object);

  virtual void on_visit(CodeTypeMember *object);

  virtual void on_visit(CodeTypeReference *object);

  virtual void on_visit(CodeVariableDeclarationStatement *object);

  virtual void on_visit(CodeVariableReferenceExpression *object);

  virtual void on_visit(CodeAssignExpression *object);

  virtual void on_visit(CodeCastExpression *object);

  virtual void on_visit(CodeObjectCreateExpression *object);

  virtual void on_visit(CodeIrBlockStatement *object);

  virtual void on_visit(CodeFileInclude *object);

  virtual void on_visit(CodeArrayCreateExpression *object);

  virtual void on_visit(CodeArrayIndexerExpression *object);

  virtual void on_visit(CodeFieldReferenceExpression *object);

  virtual void on_visit(CodeAssemblyCallExpression *object);

  virtual void on_visit(CodeAttributeArgument *object);

  virtual void on_visit(CodeAttributeDeclaration *object);

  virtual void on_visit(CodeSizeOfExpression *object);

  CodeTypeReference *m_result;
};
}

#endif /* INCLUDE_MLANG_CODE_TYPE_INFERENCE_HH_ */
