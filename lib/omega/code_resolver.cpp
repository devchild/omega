//
// Created by VANHECKE Mario on 09/09/15.
//

#include "omega.hh"

using namespace omega;

CodeObject *omega::CodeResolver::on_resolve(
    CodeVariableReferenceExpression *object) {
  CodeScope *current_scope = object->scope();

  while (current_scope != nullptr) {
    for (auto x : *current_scope->members()) {
      if (x->type_of(CodeObjectKind::CodeVariableDeclarationStatement)) {
        auto tmp = (CodeVariableDeclarationStatement *)x;
        if (tmp->name() == object->variable_name()) return tmp;
      }

      if (x->type_of(CodeObjectKind::CodeMemberField)) {
        auto tmp = (CodeMemberField *)x;
        if (tmp->name() == object->variable_name()) return tmp;
      }

      if (x->type_of(CodeObjectKind::CodeParameterDeclarationExpression)) {
        auto tmp = (CodeParameterDeclarationExpression *)x;
        if (tmp->name() == object->variable_name()) return tmp;
      }
    }
    current_scope = current_scope->parent();
  }

  return nullptr;
}

CodeObject *omega::CodeResolver::on_resolve(
    CodeFieldReferenceExpression *object) {
  auto target_type_reference =
      CodeTypeInference::get_type_reference(object->target_object());
  auto target_type_declaration = CodeResolver::resolve(target_type_reference);

  for (auto x : *target_type_declaration->members()) {
    if (x->type_of(CodeObjectKind::CodeMemberField)) {
      auto tmp = (CodeMemberField *)x;
      if (tmp->name() == object->field_name()) return tmp;
    }
  }

  return nullptr;
}

CodeTypeDeclaration *omega::CodeResolver::on_resolve(
    CodeTypeReference *code_type_reference) {
  CodeScope *current_scope = code_type_reference->scope();

  while (current_scope != nullptr) {
    for (auto x : *current_scope->members()) {
      if (x->type_of(CodeObjectKind::CodeTypeDeclaration)) {
        CodeTypeDeclaration *declaration = (CodeTypeDeclaration *)x;
        if (declaration->name() == code_type_reference->base_type()) {
          return declaration;
        }
      }
    }
    current_scope = current_scope->parent();
  }

  return nullptr;
}

CodeMemberMethod *omega::CodeResolver::on_resolve(
    CodeMethodInvokeExpression *object) {
  std::list<CodeMemberMethod *> methods;

  // method can be invoked using followinf syntax
  // invoke_something(1)
  // 1.invoke_something()
  //
  // method can be defines as
  // class MyClass:
  //    invoke_something(Int32 i):
  //        return 0
  //
  // invoke_something(Int32 i):
  //     return 0
  //

  //
  // Check for reachable methods in parent scopes
  //
  CodeScope *current_scope = object->scope();
  while (current_scope != nullptr) {
    for (auto x : *current_scope->members()) {
      if (x->type_of(CodeObjectKind::CodeMemberMethod)) {
        CodeMemberMethod *method = (CodeMemberMethod *)x;
        if (method->name() == object->method()->method_name()) {
          methods.push_back(method);
        }
      }
    }
    current_scope = current_scope->parent();
  }

  //
  // check for invoke_something inside class definitions
  //
  if (object->method()->target_object() != nullptr) {
    auto object_method_reference_target_type =
        CodeTypeInference::get_type_reference(
            object->method()->target_object());

    auto object_method_reference_target_type_declaration =
        resolve(object_method_reference_target_type);

    for (auto x : *object_method_reference_target_type_declaration->members()) {
      if (x->name() == object->method()->method_name()) {
        methods.push_back((CodeMemberMethod *)x);
      }
    }
  }

  std::list<CodeMemberMethod *> ret;

  for (auto method : methods) {
    CodeTypeDeclaration *method_owner_type = nullptr;
    CodeObject *tmp = method->parent();
    while (tmp != nullptr && method_owner_type == nullptr) {
      if (tmp->type_of(CodeObjectKind::CodeTypeDeclaration))
        method_owner_type = (CodeTypeDeclaration *)tmp;
      tmp = tmp->parent();
    }

    //
    // if we have a match on the CodeMethodReferenceExpression we just need to
    // validate the argument_types
    //
    auto method_declared_parameters = *method->parameters();
    auto passed_parameters = *object->parameters();
    // only method that are not part of a class definition can be called like
    // 1._invoke_something()
    if (method_owner_type == nullptr &&
        object->method()->target_object() != nullptr)
      passed_parameters.push_front(object->method()->target_object());

    CodeParameterDeclarationExpressionCollection::iterator
        it_method_declared_parameters = method_declared_parameters.begin();

    CodeExpressionCollection::iterator it_passed_parameters =
        passed_parameters.begin();

    bool ok = true;
    while (ok &&
           it_method_declared_parameters != method_declared_parameters.end() &&
           it_passed_parameters != passed_parameters.end()) {
      auto method_declared_parameter = *it_method_declared_parameters;
      auto passed_parameter = *it_passed_parameters;
      auto method_declared_parameter_type =
          CodeResolver::resolve(method_declared_parameter->type());
      auto passed_parameter_type = CodeResolver::resolve(
          CodeTypeInference::get_type_reference(passed_parameter));

      ok &= (method_declared_parameter_type != nullptr &&
             passed_parameter_type != nullptr &&
             method_declared_parameter_type == passed_parameter_type);
      ;

      it_method_declared_parameters++;
      it_passed_parameters++;
    }

    if (ok) ret.push_back(method);
  }

  if (ret.size() == 1) return ret.front();
  return nullptr;
}

CodeTypeDeclaration *omega::CodeResolver::resolve(
    CodeTypeReference *code_type_reference) {
  CodeTypeDeclaration *ret =
      (CodeTypeDeclaration *)code_type_reference->user_data(
          UserDataKind::MLANG_RESOLVED_TYPE);
  if (ret != nullptr)
    return ret;
  else {
    ret = on_resolve(code_type_reference);
    code_type_reference->user_data(UserDataKind::MLANG_RESOLVED_TYPE, ret);
    return ret;
  }
}

CodeObject *omega::CodeResolver::resolve(
    CodeVariableReferenceExpression *object) {
  auto ret =
      (CodeObject *)object->user_data(UserDataKind::MLANG_RESOLVED_VARIABLE);
  if (ret != nullptr)
    return ret;
  else {
    ret = on_resolve(object);
    object->user_data(UserDataKind::MLANG_RESOLVED_VARIABLE, ret);
    return ret;
  }
}

CodeObject *omega::CodeResolver::resolve(CodeFieldReferenceExpression *object) {
  auto ret =
      (CodeObject *)object->user_data(UserDataKind::MLANG_RESOLVED_VARIABLE);
  if (ret != nullptr)
    return ret;
  else {
    ret = on_resolve(object);
    object->user_data(UserDataKind::MLANG_RESOLVED_VARIABLE, ret);
    return ret;
  }
}

CodeMemberMethod *omega::CodeResolver::resolve(
    CodeMethodInvokeExpression *object) {
  auto ret = (CodeMemberMethod *)object->user_data(
      UserDataKind::MLANG_RESOLVED_METHOD);
  if (ret != nullptr)
    return ret;
  else {
    ret = on_resolve(object);
    object->user_data(UserDataKind::MLANG_RESOLVED_METHOD, ret);
    return ret;
  }
}

CodeBinaryOperatorType omega::CodeResolver::get_operator_type(
    CodeMemberMethod *object) {
  for (auto attr : object->custom_attributes()) {
    if (attr->arguments().size() != 1) return CodeBinaryOperatorType::None;

    if (attr->name() != "Operator") return CodeBinaryOperatorType::None;

    if (!attr->arguments().front()->value()->type_of(
            CodeObjectKind::CodePrimitiveExpression))
      return CodeBinaryOperatorType::None;

    auto argument =
        ((CodePrimitiveExpression *)attr->arguments().front()->value());
    std::string operator_name = argument->value_as_string();
    if (operator_name == "+") return CodeBinaryOperatorType::Add;
    if (operator_name == "-") return CodeBinaryOperatorType::Subtract;
    if (operator_name == "*") return CodeBinaryOperatorType::Multiply;
    if (operator_name == "/") return CodeBinaryOperatorType::Divide;
    if (operator_name == "|") return CodeBinaryOperatorType::BitwiseOr;
    if (operator_name == "||") return CodeBinaryOperatorType::BooleanOr;
    if (operator_name == "&") return CodeBinaryOperatorType::BitwiseAnd;
    if (operator_name == "&&") return CodeBinaryOperatorType::BooleanAnd;
    if (operator_name == "<") return CodeBinaryOperatorType::LessThan;
    if (operator_name == "<<") return CodeBinaryOperatorType::ShiftLeft;
    if (operator_name == ">") return CodeBinaryOperatorType::GreaterThan;
    if (operator_name == ">>") return CodeBinaryOperatorType::ShiftRight;
    if (operator_name == "<=") return CodeBinaryOperatorType::LessThanOrEqual;
    if (operator_name == ">=")
      return CodeBinaryOperatorType::GreaterThanOrEqual;
    if (operator_name == "%") return CodeBinaryOperatorType::Modulus;
    if (operator_name == "==") return CodeBinaryOperatorType::IdentityEquality;
    if (operator_name == "!=")
      return CodeBinaryOperatorType::IdentityInEquality;
    if (operator_name == "^") return CodeBinaryOperatorType::ExlusiveOr;
  }

  return CodeBinaryOperatorType::None;
}

CodeMemberMethod *omega::CodeResolver::on_resolve(
    CodeBinaryOperatorExpression *object) {
  CodeScope *current_scope = object->scope();
  while (current_scope != nullptr) {
    for (auto x : *current_scope->members()) {
      if (x->type_of(CodeObjectKind::CodeMemberMethod)) {
        auto method = (CodeMemberMethod *)x;
        if (method->parameters()->size() != 2) continue;

        CodeBinaryOperatorType operatorType =
            CodeResolver::get_operator_type(method);
        if (operatorType == object->operator_()) {
          auto left_t = CodeResolver::resolve(
              CodeTypeInference::get_type_reference(object->left()));
          auto right_t = CodeResolver::resolve(
              CodeTypeInference::get_type_reference(object->right()));

          auto first_t =
              CodeResolver::resolve(CodeTypeInference::get_type_reference(
                  method->parameters()->front()));

          auto last_t =
              CodeResolver::resolve(CodeTypeInference::get_type_reference(
                  method->parameters()->back()));

          if (left_t == first_t && right_t == last_t) return method;
        }
      }
    }
    current_scope = current_scope->parent();
  }

  return nullptr;
}

CodeMemberMethod *omega::CodeResolver::resolve(
    CodeBinaryOperatorExpression *object) {
  auto ret = (CodeMemberMethod *)object->user_data(
      UserDataKind::MLANG_RESOLVED_METHOD);
  if (ret != nullptr)
    return ret;
  else {
    ret = on_resolve(object);
    object->user_data(UserDataKind::MLANG_RESOLVED_METHOD, ret);
    return ret;
  }
}
