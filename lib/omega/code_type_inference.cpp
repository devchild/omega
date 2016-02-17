#include "omega.hh"
#include "code_type_inference.hh"

#include <iostream>

namespace omega {
CodeTypeInference::CodeTypeInference() { this->m_result = nullptr; }

CodeTypeInference::~CodeTypeInference() {}

void CodeTypeInference::on_visit(CodeBinaryOperatorExpression *object) {
  auto ret = CodeResolver::resolve(object);
  if (ret != nullptr)
    this->m_result = ret->return_type();
  else
    this->m_result = nullptr;
}

void CodeTypeInference::on_visit(CodeCompileUnit *object) {}

void CodeTypeInference::on_visit(CodeConditionStatement *object) {}

void CodeTypeInference::on_visit(CodeExpression *object) {}

void CodeTypeInference::on_visit(CodeExpressionStatement *object) {}

void CodeTypeInference::on_visit(CodeIterationStatement *object) {}

void CodeTypeInference::on_visit(CodeMemberField *object) {
  this->m_result = object->type();
}

void CodeTypeInference::on_visit(CodeMemberMethod *object) {
  this->m_result = object->return_type();
  if (this->m_result == nullptr) {
    for (auto x : *object->statements()) {
      if (x->type_of(CodeObjectKind::CodeMethodReturnStatement)) {
        CodeMethodReturnStatement *return_statement =
            (CodeMethodReturnStatement *)x;

        this->m_result =
            CodeTypeInference::get_type_reference(return_statement);
      }
    }
  }
}

void CodeTypeInference::on_visit(CodeMemberProperty *object) {}

void CodeTypeInference::on_visit(CodeMethodInvokeExpression *object) {
  auto method = CodeResolver::resolve(object);
  this->m_result = method->return_type();
}

void CodeTypeInference::on_visit(CodeFileInclude *object) {}

void CodeTypeInference::on_visit(CodeArrayCreateExpression *object) {
  this->m_result = object->create_type();
}

void CodeTypeInference::on_visit(CodeFieldReferenceExpression *object) {
  auto field_declaration = (CodeMemberField *)CodeResolver::resolve(object);
  this->m_result = field_declaration->type();
}

void CodeTypeInference::on_visit(CodeArrayIndexerExpression *object) {
  auto tmp = CodeTypeInference::get_type_reference(object->target_object());
  if (tmp != nullptr) {
    this->m_result = tmp->array_element_type();
  }
}

void CodeTypeInference::on_visit(CodeMethodReferenceExpression *object) {}

void CodeTypeInference::on_visit(CodeMethodReturnStatement *object) {
  auto type = CodeTypeInference::get_type_reference(object->expression());
  this->m_result = type;
}

void CodeTypeInference::on_visit(CodeNamespace *object) {}

void CodeTypeInference::on_visit(CodeObject *object) {}

void CodeTypeInference::on_visit(CodeParameterDeclarationExpression *object) {
  this->m_result = object->type();
}

void CodeTypeInference::on_visit(CodePrimitiveExpression *object) {
  this->m_result = object->type();
}

void CodeTypeInference::on_visit(CodeStatement *object) {}

void CodeTypeInference::on_visit(CodeTypeDeclaration *object) {}

void CodeTypeInference::on_visit(CodeTypeMember *object) {}

void CodeTypeInference::on_visit(CodeTypeReference *object) {
  this->m_result = object;
}

void CodeTypeInference::on_visit(CodeVariableDeclarationStatement *object) {
  this->m_result = object->type();
}

void CodeTypeInference::on_visit(CodeVariableReferenceExpression *object) {
  auto res = CodeResolver::resolve(object);

  if (res->type_of(CodeObjectKind::CodeMemberField))
    this->m_result = ((CodeMemberField *)res)->type();

  if (res->type_of(CodeObjectKind::CodeVariableDeclarationStatement))
    this->m_result = ((CodeVariableDeclarationStatement *)res)->type();

  if (res->type_of(CodeObjectKind::CodeParameterDeclarationExpression))
    this->m_result = ((CodeParameterDeclarationExpression *)res)->type();
}

void CodeTypeInference::on_visit(CodeAssignExpression *object) {
  this->m_result = CodeTypeInference::get_type_reference(object->left());
}

void CodeTypeInference::on_visit(CodeCastExpression *object) {
  this->m_result = object->target_type();
}

void CodeTypeInference::on_visit(CodeObjectCreateExpression *object) {
  this->m_result = object->create_type();
}

void CodeTypeInference::on_visit(CodeIrBlockStatement *object) {
  auto res = new CodeTypeReference();
  res->base_type("Void");
  res->scope(object->scope());
  this->m_result = res;
}

void CodeTypeInference::on_visit(CodeSizeOfExpression *object) {
  auto res = new CodeTypeReference();
  res->base_type("UInt64");
  res->scope(object->scope());
  this->m_result = res;
}

void CodeTypeInference::on_visit(CodeAssemblyCallExpression *object) {
  auto res = new CodeTypeReference();
  res->base_type("Void");
  res->scope(object->scope());
  this->m_result = res;
}

void CodeTypeInference::on_visit(CodeAttributeDeclaration *object) {}

void CodeTypeInference::on_visit(CodeAttributeArgument *object) {}

CodeTypeReference *CodeTypeInference::get_type_reference(CodeObject *object) {
  // if the result is known in the cache then just return this value
  CodeTypeReference *ret = (CodeTypeReference *)object->user_data(
      UserDataKind::MLANG_INFERRED_TYPE_REFERENCE);
  if (ret != nullptr) return ret;

  CodeTypeInference *ti = new CodeTypeInference();
  object->accept(ti);
  ret = ti->m_result;
  delete ti;

  // store the result for in case a second call is made.
  object->user_data(UserDataKind::MLANG_INFERRED_TYPE_REFERENCE, ret);
  return ret;
}
}
