/*
 * mlang_semantic_analysis.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: mario
 */
#include <map>
#include <vector>
#include <iostream>

#include <mlang.hh>

#include <easylogging++.hh>

namespace mlang {

class SemanticPass : public CodeObjectVisitorBase {
 private:
  vector<CompilerError *> &m_errors;

 public:
  SemanticPass(vector<CompilerError *> &errors) : m_errors(errors) {}

  virtual ~SemanticPass() {}

  void error(Location *location, std::string msg) {
    CompilerError *err = new CompilerError();
    err->location(location);
    err->message(msg);
    m_errors.push_back(err);
  }

  void error(CodeObject *object, std::string msg) {
    CompilerError *err = new CompilerError();
    err->location(object->location());
    err->message(msg);
    m_errors.push_back(err);
  }

  inline vector<CompilerError *> &errors() { return this->m_errors; }
};

class LoadTypes : public SemanticPass {
 private:
  std::string current_namespace;
  std::string current_type_name;

  std::map<std::string, CodeTypeDeclaration *> m_type_declarations;

 protected:
  using CodeObjectVisitorBase::on_visit;

 public:
  std::map<std::string, CodeTypeDeclaration *> type_declarations() {
    return m_type_declarations;
  }

  LoadTypes(vector<CompilerError *> &errors) : SemanticPass(errors) {}

  virtual ~LoadTypes() {}

  inline void on_visit(CodeCompileUnit *object) {
    current_namespace = "global";
    current_type_name = "global";

    for (auto x : *object->namespaces()) {
      x->accept(this);
    }

    for (auto x : *object->types()) {
      x->accept(this);
    }

    current_type_name = "";
    current_namespace = "";
  }

  inline void on_visit(CodeNamespace *object) {
    std::string orig = current_namespace;
    if (current_namespace == "global")
      current_namespace = "global::" + object->name();
    else
      current_namespace = current_namespace + "." + object->name();

    for (auto x : *object->types()) {
      x->accept(this);
    }

    for (auto x : *object->methods()) {
      x->accept(this);
    }

    current_namespace = orig;
  }

  inline void on_visit(CodeTypeDeclaration *object) {
    std::string orig = current_type_name;

    current_type_name = "";
    if (current_namespace == "global")
      current_type_name = "global::" + object->name();
    else
      current_type_name = current_namespace + "." + object->name();

    std::map<std::string, CodeTypeDeclaration *>::iterator it =
        m_type_declarations.find(current_type_name);
    if (it != m_type_declarations.end()) {
      error(object, "The namespace `" + current_namespace +
                        "' already contains a definition for `" +
                        object->name() + "'.");
    } else {
      m_type_declarations.insert(
          std::map<std::string, CodeTypeDeclaration *>::value_type(
              current_type_name, object));
    }

    current_type_name = orig;
  }
};

class ResolveReferences : public SemanticPass {
 private:
 protected:
  using SemanticPass::on_visit;

 public:
  ResolveReferences(vector<CompilerError *> &errors) : SemanticPass(errors) {}

  inline void on_visit(CodeCompileUnit *object) {
    for (auto x : *object->namespaces()) {
      x->accept(this);
    }

    for (auto x : *object->types()) {
      x->accept(this);
    }

    for (auto x : *object->methods()) {
      std::cout << x->name() << std::endl;
      x->accept(this);
    }
  }

  inline void on_visit(CodeNamespace *object) {
    for (auto x : *object->types()) {
      x->accept(this);
    }

    for (auto x : *object->methods()) {
      x->accept(this);
    }
  }

  inline void on_visit(CodeTypeDeclaration *object) {
    for (auto x : *object->members()) {
      x->accept(this);
    }
  }

  inline void on_visit(CodeMemberMethod *object) {
    for (auto x : *object->parameters()) {
      x->accept(this);
    }

    for (auto x : *object->statements()) {
      x->accept(this);
    }

    if (object->return_type() != nullptr) {
      object->return_type()->accept(this);
    } else {
      // if this is null, then we should try to infer the type from the
      // return_statements
      // not forgetting to create a TypeReference object and set it as
      // return_type
    }
  }

  inline void on_visit(CodeArrayCreateExpression *object) {
    if (object->size_expression() != nullptr)
      object->size_expression()->accept(this);

    if (object->create_type() != nullptr) object->create_type()->accept(this);
  }

  inline void on_visit(CodeArrayIndexerExpression *object) {
    CodeResolver::resolve(CodeTypeInference::get_type_reference(object));
    // resolve_type(object);
    if (object->target_object() != nullptr)
      object->target_object()->accept(this);

    for (auto x : *object->indices()) {
      x->accept(this);
    }
  }

  inline void on_visit(CodeAssemblyCallExpression *object) {
    if (object->return_type() != nullptr) {
      object->return_type()->accept(this);
    }

    for (auto x : *object->parameters()) x->accept(this);
  }

  inline void on_visit(CodeAssignExpression *object) {
    if (object->left() != nullptr) {
      object->left()->accept(this);
    }

    if (object->right() != nullptr) object->right()->accept(this);
  }

  inline void on_visit(CodeAttributeArgument *object) {
    object->value()->accept(this);
  }

  inline void on_visit(CodeAttributeDeclaration *object) {
    for (auto x : object->arguments()) {
      x->accept(this);
    }
  }

  inline void on_visit(CodeCastExpression *object) {
    object->target_type()->accept(this);
    object->expression()->accept(this);

    // validate if method can be found
    /*
     * auto target_type = resolve_type(object->target_type());
    auto expression_type = resolve_type(object->expression());
    auto res = resolve_cast_expression(object);
     */
    // if (res == nullptr)
    //	error(object->location(),
    //		"There's no cast operator defined that can convert`" +
    //expression_type->name() + "' to `" + target_type->name() + "'.");
  }

  inline void on_visit(CodeConditionStatement *object) {
    object->condition()->accept(this);
    for (auto x : *object->true_statements()) {
      x->accept(this);
    }

    for (auto x : *object->false_statements()) {
      x->accept(this);
    }
  }

  inline void on_visit(CodeExpressionStatement *object) {
    object->expression()->accept(this);
  }

  inline void on_visit(CodeExpression *object) {}

  inline void on_visit(CodeFieldReferenceExpression *object) {
    if (object->target_object() != nullptr)
      object->target_object()->accept(this);

    // validate if method can be found
    auto res = CodeResolver::resolve(object);
    if (res == nullptr)
      error(object->location(),
            "The field `" + object->field_name() + "' could not be found.");
  }

  inline void on_visit(CodeFileInclude *object) {}

  inline void on_visit(CodeIrBlockStatement *object) {}

  inline void on_visit(CodeIterationStatement *object) {
    if (object->increment_statement() != nullptr)
      object->increment_statement()->accept(this);
    if (object->init_statement() != nullptr)
      object->init_statement()->accept(this);
    if (object->test_expression() != nullptr)
      object->test_expression()->accept(this);

    for (auto x : *object->statements()) x->accept(this);
  }

  inline void on_visit(CodeMemberField *object) {
    if (object->type() != nullptr) {
      object->type()->accept(this);
    }
    if (object->init_expression() != nullptr)
      object->init_expression()->accept(this);
  }

  inline void on_visit(CodeMemberProperty *object) {}

  inline void on_visit(CodeMethodReturnStatement *object) {
    if (object->expression() != nullptr) object->expression()->accept(this);
  }

  inline void on_visit(CodeObjectCreateExpression *object) {
    if (object->create_type() != nullptr) {
      object->create_type()->accept(this);
    }
    for (auto x : *object->parameters()) x->accept(this);
  }

  inline void on_visit(CodeParameterDeclarationExpression *object) {
    if (object->type() != nullptr) {
      object->type()->accept(this);
    }
  }

  inline void on_visit(CodePrimitiveExpression *object) {
    if (object->type() != nullptr) {
      object->type()->accept(this);
    }
  }

  inline void on_visit(CodeSizeOfExpression *object) {
    if (object->type() != nullptr) object->type()->accept(this);
  }

  inline void on_visit(CodeStatement *object) {}

  inline void on_visit(CodeVariableDeclarationStatement *object) {
    if (object->type() != nullptr) object->type()->accept(this);
    if (object->init_expression() != nullptr)
      object->init_expression()->accept(this);
  }

  inline void on_visit(CodeMethodInvokeExpression *object) {
    if (object->method() != nullptr) {
      object->method()->accept(this);
    }

    // validate if method can be found
    auto res = CodeResolver::resolve(object);
    if (res == nullptr)
      error(object->location(),
            "The method name `" + object->method()->method_name() +
                "' could not be found. Are you missing an assembly reference?");
  }

  inline void on_visit(CodeVariableReferenceExpression *object) {
    CodeObject *res = CodeResolver::resolve(object);

    if (res == nullptr)
      error(object->location(),
            "The variable `" + object->variable_name() +
                "' could not be found. Are you missing an assembly reference?");
  }

  inline void on_visit(CodeTypeReference *object) {
    auto res = CodeResolver::resolve(object);
    if (res == nullptr)
      error(object->location(),
            "The type `" + object->base_type() +
                "' could not be found. Are you missing an assembly reference?");
  }

  inline void on_visit(CodeMethodReferenceExpression *object) {}

  inline void on_visit(CodeBinaryOperatorExpression *object) {
    auto res = CodeResolver::resolve(object);
    if (res == nullptr)
      error(object->location(), "There's no definition for this operator.");
  }
};

class DetectCyclicStructures : public SemanticPass {
 protected:
  using SemanticPass::on_visit;

 public:
  DetectCyclicStructures(vector<CompilerError *> &errors)
      : SemanticPass(errors) {}

  inline void on_visit(CodeCompileUnit *object) {
    for (auto x : *object->namespaces()) {
      x->accept(this);
    }

    for (auto x : *object->types()) {
      x->accept(this);
    }

    for (auto x : *object->methods()) {
      x->accept(this);
    }
  }

  inline void on_visit(CodeNamespace *object) {
    for (auto x : *object->types()) {
      x->accept(this);
    }

    for (auto x : *object->methods()) {
      x->accept(this);
    }
  }

  inline void on_visit(CodeTypeDeclaration *object) {
    if (object->is_struct()) {
      for (auto member : *object->members()) {
        if (member->type_of(CodeObjectKind::CodeMemberField)) {
          CodeMemberField *field = (CodeMemberField *)member;
          if (is_cyclic_member_field(object, field)) {
            error(field->location(),
                  "Struct member `" + object->name() + "." + member->name() +
                      "' of type `" + field->type()->base_type() +
                      "' causes a cycle in the struct layout");
          } else {
            CodeTypeDeclaration *field_type = CodeResolver::resolve(
                CodeTypeInference::get_type_reference(field->type()));

            if (field_type != nullptr &&
                has_cyclic_members(object, field_type->members())) {
              error(field->location(),
                    "Struct member `" + object->name() + "." + member->name() +
                        "' of type `" + field->type()->base_type() +
                        "' causes a cycle in the struct layout");
            }
          }
        }
      }
    }
  }

  inline bool has_cyclic_members(CodeTypeDeclaration *root,
                                 CodeTypeMemberCollection *members) {
    bool ret = false;
    for (auto member : *members) {
      if (member->type_of(CodeObjectKind::CodeMemberField)) {
        CodeMemberField *field = (CodeMemberField *)member;
        if (is_cyclic_member_field(root, field)) {
          ret = true;
        } else {
          CodeTypeDeclaration *field_type =
              CodeResolver::resolve(field->type());
          ret = has_cyclic_members(root, field_type->members());
        }
      }
    }
    return ret;
  }

  inline bool is_cyclic_member_field(CodeTypeDeclaration *root,
                                     CodeMemberField *field) {
    CodeTypeDeclaration *field_type = CodeResolver::resolve(
        CodeTypeInference::get_type_reference(field->type()));
    return root == field_type;
  }
};
}

mlang::SemanticAnalysis::SemanticAnalysis(const DomProvider &p)
    : m_provider(p) {}

mlang::SemanticAnalysis::SemanticAnalysis(const SemanticAnalysis &orig)
    : m_provider(orig.m_provider) {}

mlang::SemanticAnalysis::~SemanticAnalysis() {}

void mlang::SemanticAnalysis::analyse(CodeCompileUnit *compile_unit) {
  LoadTypes types(this->errors());
  compile_unit->accept(&types);

  auto b = types.type_declarations();
  ResolveReferences resolve_references(this->errors());
  compile_unit->accept(&resolve_references);

  DetectCyclicStructures detect_cyclic_structures(this->errors());
  compile_unit->accept(&detect_cyclic_structures);
}

vector<mlang::CompilerError *> &mlang::SemanticAnalysis::errors() {
  return this->m_errors;
}
