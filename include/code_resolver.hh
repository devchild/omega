//
// Created by VANHECKE Mario on 09/09/15.
//

#ifndef MLANG_CODERESOLVER_HH
#define MLANG_CODERESOLVER_HH

#include <include/codedom/code_type_reference.hh>
#include <include/codedom/code_binary_operator_expression.hh>
#include <include/codedom/code_member_method.hh>

namespace mlang {
class CodeScope;
class CodeObject;
class CodeVariableReferenceExpression;
class CodeFieldReferenceExpression;
class CodeTypeReference;
class CodeMethodInvokeExpression;
class CodeTypeDeclaration;
class CodeMemberMethod;
class CodeExression;

class CodeResolver {
 private:
  static CodeObject *on_resolve(CodeVariableReferenceExpression *object);

  static CodeObject *on_resolve(CodeFieldReferenceExpression *object);

  static CodeTypeDeclaration *on_resolve(
      CodeTypeReference *code_type_reference);

  static CodeMemberMethod *on_resolve(CodeMethodInvokeExpression *object);

  static CodeMemberMethod *on_resolve(CodeBinaryOperatorExpression *object);

  static CodeBinaryOperatorType get_operator_type(CodeMemberMethod *object);

 public:
  static CodeTypeDeclaration *resolve(CodeTypeReference *code_type_reference);

  static CodeObject *resolve(CodeVariableReferenceExpression *object);

  static CodeObject *resolve(CodeFieldReferenceExpression *object);

  static CodeMemberMethod *resolve(CodeMethodInvokeExpression *object);

  static CodeMemberMethod *resolve(CodeBinaryOperatorExpression *object);
};
}

#endif  // MLANG_CODERESOLVER_HH
