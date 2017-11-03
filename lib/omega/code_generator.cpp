/*
 * File:   MLangCodeGenerator.cpp
 * Author: mario
 *
 * Created on June 24, 2014, 11:26 PM
 */
#include <list>
#include <vector>
#include <iterator>
#include <stdint.h>
#include <iostream>
#include <string>

#include <llvm/AsmParser/Parser.h>
#include <llvm/Linker/Linker.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/IR/InlineAsm.h>
#include <llvm/Support/Host.h>

#include <omega.hh>

#include <easylogging++.hh>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Support/TargetRegistry.h>

namespace omega {

class LLVMUserData {
 public:
  static void set_l_value(CodeObject *obj, llvm::Value *value) {
    obj->user_data(UserDataKind::LLVM_L_VALUE, value);
  }

  static void set_r_value(CodeObject *obj, llvm::Value *value) {
    obj->user_data(UserDataKind::LLVM_R_VALUE, value);
  }

  static llvm::Value *get_r_value(CodeObject *obj) {
    if (obj->user_data(UserDataKind::LLVM_R_VALUE))
      return (llvm::Value *)obj->user_data(UserDataKind::LLVM_R_VALUE);
    return nullptr;
  }

  static llvm::Value *get_l_value(CodeObject *obj) {
    if (obj->user_data(UserDataKind::LLVM_L_VALUE))
      return (llvm::Value *)obj->user_data(UserDataKind::LLVM_L_VALUE);
    return nullptr;
  }

  static void set_llvm_type(CodeObject *obj, llvm::Type *value) {
    obj->user_data(UserDataKind::LLVM_TYPE, value);
  }

  static llvm::Type *get_llvm_type(CodeObject *obj) {
    if (obj->user_data(UserDataKind::LLVM_TYPE))
      return (llvm::Type *)obj->user_data(UserDataKind::LLVM_TYPE);

    if (obj->type_of(CodeObjectKind::CodeTypeReference)) {
      auto ret = code_type_reference_get_llvm_type((CodeTypeReference *)obj);
      if (ret != nullptr) LLVMUserData::set_llvm_type(obj, ret);
      return ret;
    }

    return nullptr;
  }

 private:
  static llvm::Type *code_type_reference_get_llvm_type(
      CodeTypeReference *code_type_reference) {
    llvm::Type *ret = nullptr;
    CodeTypeDeclaration *code_type_declaration =
        CodeResolver::resolve(code_type_reference);
    if (code_type_declaration->is_embedded() &&
        code_type_declaration->name() == "Array") {
      if (code_type_reference->array_element_type() != nullptr) {
        llvm::Type *element_type = LLVMUserData::get_llvm_type(
            code_type_reference->array_element_type());
        ret = llvm::PointerType::get(element_type, 0);
      }
    } else if (code_type_declaration->is_class()) {
      // this will probably have to move to get_llvm_type
      ret = llvm::PointerType::get(ret, 0);
    } else {
      return LLVMUserData::get_llvm_type(code_type_declaration);
    }

    return ret;
  }
};

class GenerationPass : public CodeObjectVisitorBase {
 private:
  std::vector<CompilerError *> &m_errors;

 public:
  GenerationPass(std::vector<CompilerError *> &errors) : m_errors(errors) {}

  virtual ~GenerationPass() {}

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

  inline std::vector<CompilerError *> &errors() { return this->m_errors; }
};

class LLVMTypeGenerationPass : public GenerationPass {
 private:
  llvm::Module *m_module;

 protected:
  using CodeObjectVisitorBase::on_visit;

 public:
  LLVMTypeGenerationPass(llvm::Module *module,
                         std::vector<CompilerError *> &errors)
      : GenerationPass(errors) {
    this->m_module = module;
  }

  virtual ~LLVMTypeGenerationPass() {}

  inline void on_visit(CodeCompileUnit *object) {
    for (auto x : *object->types()) {
      x->accept(this);
    }

    for (auto x : *object->namespaces()) {
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
  }

  inline static constexpr unsigned int str2int(const char *str, int h = 0) {
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
  }

  inline void on_visit(CodeTypeDeclaration *object) {
    llvm::LLVMContext &ctx = m_module->getContext();

    if (object->is_embedded()) {
      switch (str2int(object->name().c_str())) {
        case str2int("Int1"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getInt1Ty(ctx));
          break;
        case str2int("Bool"):
        case str2int("Char"):
        case str2int("SByte"):
        case str2int("Byte"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getInt8Ty(ctx));
          break;
        case str2int("Int16"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getInt16Ty(ctx));
          break;
        case str2int("UInt16"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getInt16Ty(ctx));
          break;
        case str2int("Int32"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getInt32Ty(ctx));
          break;
        case str2int("UInt32"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getInt32Ty(ctx));
          break;
        case str2int("Int64"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getInt64Ty(ctx));
          break;
        case str2int("UInt64"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getInt64Ty(ctx));
          break;
        case str2int("Single"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getFloatTy(ctx));
          break;
        case str2int("Double"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getDoubleTy(ctx));
          break;
        case str2int("Decimal"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getFP128Ty(ctx));
          break;
        case str2int("IntPtr"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getInt64PtrTy(ctx));
          break;
        case str2int("Void"):
          LLVMUserData::set_llvm_type(object, llvm::Type::getVoidTy(ctx));
          break;
        case str2int("Array"):
          LLVMUserData::set_llvm_type(object, nullptr);
          break;
      }
    } else if (object->is_struct()) {
      std::string struct_name = object->name();
      llvm::StructType *struct_type =
          llvm::StructType::create(ctx, struct_name);
      LLVMUserData::set_llvm_type(object, struct_type);
    } else if (object->is_class()) {
      std::string class_name = object->name();
      llvm::StructType *class_type = llvm::StructType::create(ctx, class_name);
      LLVMUserData::set_llvm_type(object, class_type);
    }
  }
};

class LLVMMethodPrototypeGenerationPass : public GenerationPass {
 private:
  llvm::Module *m_module;

 protected:
  using CodeObjectVisitorBase::on_visit;

 public:
  LLVMMethodPrototypeGenerationPass(llvm::Module *module,
                                    std::vector<CompilerError *> &errors)
      : GenerationPass(errors) {
    this->m_module = module;
  }

  virtual ~LLVMMethodPrototypeGenerationPass() {}

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
    for (auto x : *object->members()) {
      x->accept(this);
    }
  }

  inline void on_visit(CodeMemberMethod *object) {
    llvm::Type *result_type = LLVMUserData::get_llvm_type(
        object
            ->return_type());  //  static_cast<llvm::Type*>(t->user_data(UserDataKind::LLVM_TYPE));

    std::vector<llvm::Type *> param_types;
    if (object->parameters()->size() > 0) {
      for (auto p : *object->parameters()) {
        auto llvm_type = LLVMUserData::get_llvm_type(p->type());
        param_types.push_back(llvm_type);
      }
    }

    llvm::FunctionType *function_type =
        llvm::FunctionType::get(result_type, param_types, false);

    if (object->name() == "start") object->attributes(MemberAttributes::Public);
    if (object->name() == "_start") object->attributes(MemberAttributes::Public);

    std::string method_name = object->id();
    auto function = llvm::Function::Create(
        function_type, llvm::GlobalValue::LinkageTypes::ExternalLinkage,
        method_name, m_module);
    function->setCallingConv(llvm::CallingConv::C);
  }
};
static llvm::LLVMContext TheContext;
CodeGenerator::CodeGenerator(const DomProvider &p)
    : m_provider(p), m_context(TheContext) {}

CodeGenerator::CodeGenerator(const CodeGenerator &orig)
    : m_provider(orig.m_provider), m_context(orig.m_context) {}

CodeGenerator::~CodeGenerator() {}

const DomProvider &CodeGenerator::provider() { return this->m_provider; }

static llvm::FunctionType *get_malloc_functiontype(llvm::Module *mod) {
  llvm::PointerType *PointerTy_3 =
      llvm::PointerType::get(llvm::IntegerType::get(mod->getContext(), 8), 0);
  std::vector<llvm::Type *> FuncTy_11_args;
  FuncTy_11_args.push_back(llvm::IntegerType::get(mod->getContext(), 32));
  llvm::FunctionType *FuncTy_11 = llvm::FunctionType::get(
      /*Result=*/PointerTy_3,
      /*Params=*/FuncTy_11_args,
      /*isVarArg=*/false);
  return FuncTy_11;
}

llvm::Module *CodeGenerator::GenerateCodeFromCompileUnit(
    omega::CodeCompileUnit *compile_unit) {
  llvm::Module *module = new llvm::Module("in_memory_module", m_context);

  std::vector<CompilerError *> err;
  LLVMTypeGenerationPass type_generator(module, err);
  compile_unit->accept(&type_generator);

  LLVMMethodPrototypeGenerationPass method_prototype_generator(module, err);
  compile_unit->accept(&method_prototype_generator);

  for (auto code_type_declaration : *compile_unit->types()) {
    auto bblock = llvm::BasicBlock::Create(m_context,
                                           code_type_declaration->name(), 0, 0);
    auto gen = new CodeEmitLLVM(bblock);
    code_type_declaration->accept(gen);
  }

  for (auto code_member_method : *compile_unit->methods()) {
    CreateFunction(module, code_member_method);
  }

  for (auto code_namespace : *compile_unit->namespaces()) {
    for (auto code_type_declaration : *code_namespace->types()) {
      auto bblock = llvm::BasicBlock::Create(
          m_context, code_type_declaration->name(), 0, 0);
      auto gen = new CodeEmitLLVM(bblock);
      code_type_declaration->accept(gen);
    }

    for (auto code_member_method : *code_namespace->methods()) {
      CreateFunction(module, code_member_method);
    }
  }

  return module;
}

/*
llvm::Value* load_if_needed(CodeObject* obj, llvm::Value* value,
                llvm::BasicBlock* block) {
        CodeTypeInference inf;
        obj->accept(&inf);
        auto obj_type = inf.result();

        auto obj_type_decl = (CodeTypeDeclaration*) obj_type->user_data(
                        UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
//obj->resolve_type(obj_type);

        llvm::Value* ret = value;
        if (obj_type_decl->is_class() &&
            (obj->type_of(CodeObjectKind::CodeVariableReferenceExpression)
                        ||
obj->type_of(CodeObjectKind::CodeArrayIndexerExpression)
                        ||
obj->type_of(CodeObjectKind::CodeFieldReferenceExpression)))
                ret = new llvm::LoadInst(value, "", block);
        return ret;
}
*/

llvm::Function *CodeGenerator::CreateFunction(llvm::Module *module,
                                              omega::CodeMemberMethod *method) {
  // Type *Result, ArrayRef<Type*> Params, bool IsVarArgs

  /*
auto function_type = GetFunctionType(method->return_type(),
  method->parameters(), false);

if (method->name() == "main" || method->name() == "_start")
method->attributes(MemberAttributes::Public);
*/
  std::string method_name = method->id();
  auto function = module->getFunction(method_name);
  /*
llvm::Function::Create(function_type,
llvm::GlobalValue::LinkageTypes::ExternalLinkage, method_name,
module);
*/

  if (method->attributes() != MemberAttributes::External) {
    auto bblock = llvm::BasicBlock::Create(m_context, "entry", function, 0);
    llvm::Function::arg_iterator args = function->arg_begin();

    for (auto p : *method->parameters()) {
      auto paramter_input = args++;
      paramter_input->setName(p->name());
      auto parameter_input_addr = CodeEmitLLVM::get_l_value(p, bblock);
      parameter_input_addr->setName(p->name() + ".addr");
      new llvm::StoreInst(&*paramter_input, parameter_input_addr, false,
                          bblock);
    }

    if (method->statements() != nullptr) {
      for (auto statement : *method->statements()) {
        bblock = CodeEmitLLVM::emit_code(statement, bblock);
      }
    }
  }

  for (auto attribute : method->custom_attributes()) {
    if (attribute->name() == "Inline" && attribute->arguments().size() == 0) {
      function->addFnAttr(llvm::Attribute::InlineHint);
      function->setLinkage(llvm::GlobalValue::PrivateLinkage);
    }
  }

  return function;
}

llvm::FunctionType *CodeGenerator::GetFunctionType(
    CodeTypeReference *code_type_reference,
    CodeParameterDeclarationExpressionCollection *params, bool is_var_args) {
  llvm::Type *result_type = LLVMUserData::get_llvm_type(code_type_reference);

  std::vector<llvm::Type *> param_types;
  if (params->size() > 0) {
    for (auto p : *params) {
      auto llvm_type = LLVMUserData::get_llvm_type(p->type());
      param_types.push_back(llvm_type);
    }
  }

  llvm::FunctionType *ret =
      llvm::FunctionType::get(result_type, param_types, is_var_args);
  return ret;
}

CodeEmitLLVM::CodeEmitLLVM(llvm::BasicBlock *block) {
  this->m_l_result = nullptr;
  this->m_r_result = nullptr;
  this->m_block = block;
}

llvm::BasicBlock *CodeEmitLLVM::emit_code(CodeObject *object,
                                          llvm::BasicBlock *block) {
  CodeEmitLLVM *em = new CodeEmitLLVM(block);
  object->accept(em);

  if (em->m_l_result && em->m_l_result != nullptr)
    LLVMUserData::set_l_value(object, em->m_l_result);

  if (em->m_r_result && em->m_r_result != nullptr)
    LLVMUserData::set_r_value(object, em->m_r_result);

  auto res = em->m_block;
  delete em;
  return res;
}

//
// --> a <-- = 2 + 2
//
llvm::Value *CodeEmitLLVM::get_l_value(CodeObject *object,
                                       llvm::BasicBlock *block) {
  auto l_val = LLVMUserData::get_l_value(object);

  if (l_val == nullptr) {
    CodeEmitLLVM::emit_code(object, block);
    return LLVMUserData::get_l_value(object);
  }
  return l_val;
}

//
// a = --> 2 + 2 <--
// In general a loadinst is aplied to the get_l_value
llvm::Value *CodeEmitLLVM::get_r_value(CodeObject *object,
                                       llvm::BasicBlock *block) {
  auto r_val = LLVMUserData::get_r_value(object);

  if (r_val == nullptr) {
    CodeEmitLLVM::emit_code(object, block);

    r_val = LLVMUserData::get_r_value(object);
    // if tmp is empty we can take the l_value and load from the pointer
    if (r_val == nullptr) {
      auto tmp = LLVMUserData::get_l_value(object);
      if (tmp && tmp != nullptr) {
        r_val = new llvm::LoadInst(tmp, "", block);
        LLVMUserData::set_r_value(object, r_val);
      }
    }
  }
  return r_val;
}

CodeEmitLLVM::~CodeEmitLLVM() {}

void CodeEmitLLVM::on_visit(CodeBinaryOperatorExpression *object) {
  llvm::Function *parent_function = this->m_block->getParent();
  llvm::Module *mod = parent_function->getParent();

  auto expression_left = object->left();
  auto expression_right = object->right();
  std::vector<llvm::Value *> method_args;

  if (expression_left != nullptr) {
    method_args.push_back(
        CodeEmitLLVM::get_r_value(expression_left, this->m_block));
  }

  if (expression_right != nullptr) {
    method_args.push_back(
        CodeEmitLLVM::get_r_value(expression_right, this->m_block));
  }

  auto resolved_method = CodeResolver::resolve(object);
  auto f = mod->getFunction(resolved_method->id());
  this->m_r_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
}

void CodeEmitLLVM::on_visit(CodeCompileUnit *object) {
  // std::cout << ">> CodeCompileUnit" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeExpression *object) {
  // std::cout << ">> CodeExpression" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeMemberField *object) {
  // std::cout << ">> CodeMemberField" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeMemberMethod *object) {
  // std::cout << ">> CodeMemberMethod" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeMemberProperty *object) {
  // std::cout << ">> CodeMemberProperty" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeMethodReturnStatement *object) {
  auto expression = object->expression();
  if (expression != nullptr) {
    auto return_val = CodeEmitLLVM::get_r_value(expression, this->m_block);
    m_l_result = llvm::ReturnInst::Create(this->m_block->getContext(),
                                          return_val, this->m_block);

  } else {
    m_l_result = llvm::ReturnInst::Create(this->m_block->getContext(), m_block);
  }
}

void CodeEmitLLVM::on_visit(CodeNamespace *object) {
  // std::cout << ">> CodeNamespace" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeObject *object) {
  // std::cout << ">> CodeObject" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeParameterDeclarationExpression *object) {
  auto llvm_type = LLVMUserData::get_llvm_type(object->type());
  auto name = object->name();

  llvm::AllocaInst *alloc =
      new llvm::AllocaInst(llvm_type, NULL, name, this->m_block);
  this->m_l_result = alloc;
}

void CodeEmitLLVM::on_visit(CodePrimitiveExpression *object) {
  // std::cout << ">> CodePrimitiveExpression" << std::endl;

  auto module = this->m_block->getParent()->getParent();
  llvm::LLVMContext &ctx = this->m_block->getContext();

  // auto type_reference = object->type();

  CodeTypeDeclaration *td =
      (CodeTypeDeclaration *)CodeResolver::resolve(object->type());
  llvm::Type *type = LLVMUserData::get_llvm_type(object->type());

  // static_cast<llvm::Type*>(td->user_data(
  // UserDataKind::LLVM_TYPE)); //td->llvm_type();

  if (td->name() == "Int32") {
    uint64_t v = (uint64_t)(uint64_t *)object->value();
    m_r_result = llvm::ConstantInt::get(
        llvm::Type::getInt32Ty(m_block->getContext()), v, true);

    // LLVMUserData::set_r_value(object, m_r_result);
  }

  if (td->is_embedded() && object->type()->base_type() == "Array" &&
      object->type()->array_element_type()->base_type() == "Char") {
    auto element_Type =
        LLVMUserData::get_llvm_type(object->type()->array_element_type());
    std::string v = object->value_as_string();
    // not used
    llvm::Constant *str_val = llvm::ConstantDataArray::getString(ctx, v);
    // llvm::Type *element_type =
    // LLVMUserData::get_llvm_type(object->type()->array_element_type());

    llvm::GlobalVariable *str_var = new llvm::GlobalVariable(
        *module, llvm::ArrayType::get(element_Type, (uint64_t)v.size() + 1),
        true, llvm::GlobalValue::PrivateLinkage, str_val, "");

    str_var->setInitializer(str_val);
    
    llvm::Constant *zero =
        llvm::Constant::getNullValue(llvm::IntegerType::getInt64Ty(ctx));

    std::vector<llvm::Constant *> indices;
    indices.push_back(zero);
    indices.push_back(zero);
    llvm::Constant *var_ref = llvm::ConstantExpr::getGetElementPtr(
        str_var->getValueType(), str_var, indices);
    m_r_result = var_ref;

    // LLVMUserData::set_r_value(object, m_r_result);
  }

  // std::cout << "<< CodePrimitiveExpression" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeStatement *object) {
  // std::cout << ">> CodeStatement" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeTypeDeclaration *object) {
  llvm::LLVMContext &ctx = this->m_block->getContext();
  // auto module = this->m_block->getParent()->getParent();

  if (object->is_embedded()) {
  } else if (object->is_struct()) {
    llvm::StructType *struct_type =
        (llvm::StructType *)object->user_data(UserDataKind::LLVM_TYPE);

    std::vector<llvm::Type *> struct_type_fields;
    for (auto field_decl : *object->members()) {
      auto field = static_cast<CodeMemberField *>(field_decl);
      if (field != nullptr) {
        llvm::Type *field_type = LLVMUserData::get_llvm_type(field->type());
        struct_type_fields.push_back(field_type);
      }
    }

    if (struct_type_fields.size() > 0 && struct_type->isOpaque()) {
      struct_type->setBody(struct_type_fields, /*isPacked=*/false);
    }

  } else if (object->is_class()) {
    llvm::StructType *struct_type =
        (llvm::StructType *)object->user_data(UserDataKind::LLVM_TYPE);

    std::vector<llvm::Type *> class_type_fields;
    for (auto field_decl : *object->members()) {
      auto field = static_cast<CodeMemberField *>(field_decl);
      if (field != nullptr) {
        llvm::Type *field_type = LLVMUserData::get_llvm_type(field->type());
        class_type_fields.push_back(field_type);
      }
    }

    if (class_type_fields.size() > 0 && struct_type->isOpaque()) {
      struct_type->setBody(class_type_fields, /*isPacked=*/false);
    }
  }
}

void CodeEmitLLVM::on_visit(CodeTypeMember *object) {
  // std::cout << ">> CodeTypeMember" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeTypeReference *object) {
  // std::cout << ">> CodeTypeReference" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeVariableDeclarationStatement *object) {
  auto name = object->name();
  auto llvm_type = LLVMUserData::get_llvm_type(object->type());

  llvm::AllocaInst *alloc =
      new llvm::AllocaInst(llvm_type, NULL, name, this->m_block);
  this->m_l_result = alloc;
  if (object->init_expression() != nullptr) {
    auto expr_res =
        CodeEmitLLVM::get_r_value(object->init_expression(), this->m_block);
    new llvm::StoreInst(expr_res, alloc, false, this->m_block);
    this->m_r_result = expr_res;
  }
}

void CodeEmitLLVM::on_visit(CodeVariableReferenceExpression *object) {
  auto resolved_variable_reference = CodeResolver::resolve(object);

  if (resolved_variable_reference == nullptr) return;

  this->m_l_result =
      CodeEmitLLVM::get_l_value(resolved_variable_reference, this->m_block);
}

void CodeEmitLLVM::on_visit(CodeCastExpression *object) {
  // std::cout << ">> CodeCastExpression" << std::endl;

  llvm::LLVMContext &ctx = this->m_block->getContext();
  llvm::Constant *zero =
      llvm::Constant::getNullValue(llvm::IntegerType::getInt32Ty(ctx));

  llvm::Function *parent_function = this->m_block->getParent();
  llvm::Module *mod = parent_function->getParent();

  std::list<CodeTypeDeclaration *> method_arg_types;
  std::vector<llvm::Value *> method_args;

  // infer the type of the target_expression
  auto expression_type =
      CodeTypeInference::get_type_reference(object->expression());
  auto expression_type_decl = CodeResolver::resolve(expression_type);
  method_arg_types.push_back(expression_type_decl);

  // I'll need the return type of the method to resolve
  auto td_return = CodeResolver::resolve(object->target_type());
  // object->target_type());

  std::string method_name = "cast";
  /*auto resolved_method = object->resolve_method(method_name, td_return,
                                                                                            &method_arg_types);
                                                                                            */

  // generate the code for the target_expression
  auto tp_gen = new CodeEmitLLVM(this->m_block);
  object->expression()->accept(tp_gen);
  auto expression_value = tp_gen->m_l_result;

  // prepare a list of parameters i need to pass to the target method
  expression_value = LLVMUserData::get_r_value(object->expression());
  /*
                  if (resolved_method != nullptr) {
                          method_args.push_back(expression_value);
                          auto f = mod->getFunction(resolved_method->id());
                          this->m_l_result = llvm::CallInst::Create(f,
     method_args, "",
                                                                                                          this->m_block);
                  } else {
                          auto create_type = static_cast<llvm::Type
     *>(td_return->user_data(
                                          UserDataKind::LLVM_TYPE));
                          this->m_l_result = new
     llvm::BitCastInst(expression_value, create_type,
                                                                                                     "", this->m_block);
                  }
                  */
}

void CodeEmitLLVM::on_visit(CodeObjectCreateExpression *object) {
  // std::cout << ">> CodeObjectCreateExpression" << std::endl;
  auto resolved =
      (CodeTypeDeclaration *)CodeResolver::resolve(object->create_type());

  if (resolved->is_class()) {
    auto create_type =
        (llvm::PointerType *)LLVMUserData::get_llvm_type(object->create_type());
    auto element_type =
        (llvm::Type *)resolved->user_data(UserDataKind::LLVM_TYPE);

    auto module = this->m_block->getParent()->getParent();
    llvm::LLVMContext &context = module->getContext();

    llvm::DataLayout l = llvm::DataLayout(module);
    llvm::ConstantInt *const_int64_14 = llvm::ConstantInt::get(
        context, llvm::APInt(64, l.getTypeAllocSize(element_type)));

    llvm::Function *func_malloc = module->getFunction("malloc");
    llvm::CallInst *ptr_19 =
        llvm::CallInst::Create(func_malloc, const_int64_14, "", this->m_block);
    this->m_l_result =
        new llvm::BitCastInst(ptr_19, create_type, "", this->m_block);
  } else {
    this->m_l_result = nullptr;
  }
}

void CodeEmitLLVM::on_visit(CodeFileInclude *object) {
  // std::cout << ">> CodeFileImport" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeFieldReferenceExpression *object) {
  auto target_object_l_value =
      CodeEmitLLVM::get_l_value(object->target_object(), this->m_block);
  auto target_object_type_declaration = CodeResolver::resolve(
      CodeTypeInference::get_type_reference(object->target_object()));
  auto target_object_type_declaration_type =
      LLVMUserData::get_llvm_type(target_object_type_declaration);

  if (target_object_type_declaration->is_class()) {
    target_object_l_value =
        new llvm::LoadInst(target_object_l_value, "", this->m_block);
  }

  int index = 0;
  for (auto x : *target_object_type_declaration->members()) {
    if (x->name() == object->field_name()) break;

    if (x->type_of(CodeObjectKind::CodeMemberField)) index++;
  }

  llvm::ConstantInt *const_int32_0 = llvm::ConstantInt::get(
      this->m_block->getContext(), llvm::APInt(32, llvm::StringRef("0"), 10));
  llvm::ConstantInt *const_int32_i = llvm::ConstantInt::get(
      this->m_block->getContext(), llvm::APInt(32, index));

  std::vector<llvm::Value *> ptr_a_indices;
  ptr_a_indices.push_back(const_int32_0);
  ptr_a_indices.push_back(const_int32_i);

  this->m_l_result = llvm::GetElementPtrInst::Create(
      target_object_type_declaration_type, target_object_l_value, ptr_a_indices,
      object->field_name(), this->m_block);
}

void CodeEmitLLVM::on_visit(CodeArrayIndexerExpression *object) {
  llvm::Value *ptr_29 =
      CodeEmitLLVM::get_r_value(object->target_object(), this->m_block);
  auto ptr_29_type = LLVMUserData::get_llvm_type(object->target_object());

  std::vector<llvm::Value *> indices;
  for (auto x : *object->indices()) {
    indices.push_back(CodeEmitLLVM::get_r_value(x, this->m_block));
  }

  this->m_l_result = llvm::GetElementPtrInst::Create(
      ptr_29_type, ptr_29, indices, "", this->m_block);
}

void CodeEmitLLVM::on_visit(CodeArrayCreateExpression *object) {
  auto m_func = this->m_block->getParent();
  auto m_module = m_func->getParent();
  llvm::LLVMContext &m_context = m_module->getContext();

  auto size_expression =
      CodeEmitLLVM::get_r_value(object->size_expression(), this->m_block);
  auto llvm_type = LLVMUserData::get_llvm_type(object->create_type());

  llvm::DataLayout l = llvm::DataLayout(m_module);
  llvm::ConstantInt *const_int64_14 = llvm::ConstantInt::get(
      m_context, llvm::APInt(32, l.getTypeAllocSize(llvm_type), /* isSigned = */
                             false));

  size_expression = llvm::BinaryOperator::CreateMul(
      size_expression, const_int64_14, "", this->m_block);

  auto func_malloc = m_module->getOrInsertFunction(
      "malloc", get_malloc_functiontype(m_module));
  llvm::CallInst *ptr_55 =
      llvm::CallInst::Create(func_malloc, size_expression, "", this->m_block);

  this->m_r_result =
      llvm::BitCastInst::Create(llvm::Instruction::CastOps::BitCast, ptr_55,
                                llvm_type, "", this->m_block);
}

void CodeEmitLLVM::on_visit(CodeSizeOfExpression *object) {
  auto m_func = this->m_block->getParent();
  auto m_module = m_func->getParent();
  llvm::LLVMContext &m_context = m_module->getContext();

  auto resolved = CodeResolver::resolve(
      CodeTypeInference::get_type_reference(object->type()));
  auto create_type =
      static_cast<llvm::Type *>(resolved->user_data(UserDataKind::LLVM_TYPE));

  if (create_type->isPointerTy())
    create_type = ((llvm::PointerType *)create_type)->getElementType();

  llvm::DataLayout l = llvm::DataLayout(m_module);
  llvm::ConstantInt *const_int64_14 = llvm::ConstantInt::get(
      m_context,
      llvm::APInt(64, l.getTypeAllocSize(create_type), /* isSigned = */
                  false));

  // LLVMUserData::set_r_value(object, const_int64_14);
  this->m_r_result = const_int64_14;
}

void CodeEmitLLVM::on_visit(CodeAssemblyCallExpression *object) {
  // std::cout << ">> CodeAsmBlockStatement" << std::endl;

  auto m_func = this->m_block->getParent();
  auto m_module = m_func->getParent();
  llvm::LLVMContext &m_context = m_module->getContext();

  std::vector<llvm::Value *> args;
  std::vector<llvm::Type *> parameter_llvm_types;
  auto cv = llvm::InlineAsm::ParseConstraints(object->constraints());

  llvm::Type *return_type = llvm::Type::getVoidTy(m_context);
  if (object->return_type() != nullptr) {
    return_type = LLVMUserData::get_llvm_type(
        CodeResolver::resolve(object->return_type()));
  }

  for (auto p_arg : *object->parameters()) {
    auto res = CodeEmitLLVM::get_r_value(p_arg, this->m_block);
    args.push_back(res);
    parameter_llvm_types.push_back(res->getType());
  }

  auto FT = llvm::FunctionType::get(return_type, parameter_llvm_types, false);
  llvm::InlineAsm *ia =
      llvm::InlineAsm::get(FT, object->content(), object->constraints(), true);
  llvm::CallInst *call_inst =
      llvm::CallInst::Create(ia, args, "", this->m_block);
  call_inst->setCallingConv(llvm::CallingConv::C);
  call_inst->setTailCall(false);

  this->m_l_result = call_inst;
}

void CodeEmitLLVM::on_visit(CodeIrBlockStatement *object) {
  // std::cout << ">> CodeIrBlockStatement" << std::endl;

  auto m_func = this->m_block->getParent();
  auto m_module = m_func->getParent();

  llvm::LLVMContext &m_context = m_module->getContext();

  std::string str;
  llvm::raw_string_ostream stream(str);
  stream << "define "
         << "void"
         << " @_" << object->id() << "(";
  int i = 0;

  std::vector<llvm::Value *> params;
  CodeScope *parent = object->scope();
  while (parent != nullptr) {
    for (auto m : *parent->members()) {
      if (m->type_of(CodeObjectKind::CodeVariableDeclarationStatement)) {
        auto var = (CodeVariableDeclarationStatement *)m;
        if (i > 0) stream << ", ";
        auto l_value = CodeEmitLLVM::get_l_value(
            var,
            this->m_block);  //  static_cast<llvm::Value
                             //  *>(var->user_data(UserDataKind::LLVM_L_VALUE));
                             //  //
        l_value->getType()->print(stream);
        stream << " ";
        stream << "%" << var->name();
        params.push_back(l_value);
        i++;
      }

      if (m->type_of(CodeObjectKind::CodeParameterDeclarationExpression)) {
        auto var = (CodeParameterDeclarationExpression *)m;
        if (i > 0) stream << ", ";

        auto l_value = CodeEmitLLVM::get_l_value(
            var,
            this->m_block);  //  static_cast<llvm::Value
                             //  *>(var->user_data(UserDataKind::LLVM_L_VALUE));
                             //  //
        l_value->getType()->print(stream);
        stream << " ";
        stream << "%" << var->name();
        params.push_back(l_value);
        i++;
      }
    }

    parent = parent->parent();
  }

  // stream 	<< 1. generate parameters
  stream << ")\n{\n" << object->content() << "\nret void\n}";

  auto s = stream.str().c_str();
  llvm::SMDiagnostic err;
  auto m = llvm::parseAssemblyString(s, err, m_context);
  std::string errstr = err.getMessage();
  if (errstr != "")
    std::cout << "can't parse inline LLVM IR:\n"
              << err.getLineContents().str().c_str() << "\n"
              << (std::string(err.getColumnNo(), ' ') + '^').c_str()
              << errstr.c_str() << "\nThe input string was: \n"
              << stream.str().c_str();

  std::string errstr2 = "";
  if (m_module->getModuleIdentifier() != m->getModuleIdentifier()) {
    llvm::Linker(*m_module).linkInModule(std::move(m));
  }

  llvm::Function *fun = m_module->getFunction("_" + object->id());
  fun->setLinkage(llvm::GlobalValue::LinkOnceODRLinkage);
  fun->addFnAttr(llvm::Attribute::AlwaysInline);
  this->m_l_result = llvm::CallInst::Create(fun, params, "", this->m_block);
}

void CodeEmitLLVM::on_visit(CodeAssignExpression *object) {
  auto left = CodeEmitLLVM::get_l_value(object->left(), this->m_block);
  auto right = CodeEmitLLVM::get_r_value(object->right(), this->m_block);
  auto st = new llvm::StoreInst(right, left, false, this->m_block);
  this->m_l_result = left;
}

void CodeEmitLLVM::on_visit(CodeExpressionStatement *object) {
  CodeEmitLLVM::emit_code(object->expression(), this->m_block);
}

void CodeEmitLLVM::on_visit(CodeMethodInvokeExpression *object) {
  // std::cout << ">> CodeMethodInvokeExpression" << std::endl;
  auto method_name = object->method()->method_name();
  auto parent_function = this->m_block->getParent();
  auto module = parent_function->getParent();
  llvm::LLVMContext &ctx = module->getContext();

  std::vector<llvm::Value *> args;
  if (object->method()->target_object() != nullptr) {
    auto res = CodeEmitLLVM::get_r_value(object->method()->target_object(),
                                         this->m_block);
    args.push_back(res);
  }

  for (auto p_arg : *object->parameters()) {
    auto res = CodeEmitLLVM::get_r_value(p_arg, this->m_block);
    args.push_back(res);
  }

  auto resolved_method = CodeResolver::resolve(object);
  llvm::Function *f = module->getFunction(resolved_method->id());
  this->m_r_result = llvm::CallInst::Create(f, args, "", this->m_block);
}

void CodeEmitLLVM::on_visit(CodeConditionStatement *object) {
  // std::cout << ">> CodeConditionStatement" << std::endl;

  bool has_false_block = object->false_statements()->size();
  llvm::LLVMContext &context = this->m_block->getContext();
  auto parent_function = this->m_block->getParent();
  

  llvm::BasicBlock *label_if_end =
      llvm::BasicBlock::Create(context, "if.end", parent_function, 0);
  llvm::BasicBlock *label_if_true =
      llvm::BasicBlock::Create(context, "if.then", parent_function, 0);

  llvm::BasicBlock *label_if_false = nullptr;
  if (has_false_block)
    label_if_false =
        llvm::BasicBlock::Create(context, "if.else", parent_function, 0);

  // condition
  /*
  CodeEmitLLVM *gen_condition =
                          new CodeEmitLLVM(this->m_block);
          object->condition()->accept(gen_condition);
   */

  auto tmp = CodeEmitLLVM::get_r_value(object->condition(), this->m_block);
  llvm::CmpInst *compare_instr = static_cast<llvm::CmpInst *>(tmp);
  llvm::CmpInst *result_tobool = nullptr;
  if (compare_instr == nullptr)
  {
    auto true_val = llvm::ConstantInt::get(
      context, llvm::APInt(32, llvm::StringRef("0"), 10));
    result_tobool = new llvm::ICmpInst(*this->m_block, llvm::ICmpInst::ICMP_NE,
                                       tmp, true_val, "tobool");
  }
  else
  {
    auto true_val = llvm::ConstantInt::get(
      context, llvm::APInt(8, llvm::StringRef("0"), 10));
    result_tobool = new llvm::ICmpInst(*this->m_block, llvm::ICmpInst::ICMP_NE,
      tmp, true_val, "tobool");
  }

  if (has_false_block)
    this->m_l_result = llvm::BranchInst::Create(label_if_true, label_if_false,
                                                result_tobool, this->m_block);
  else
  {
    this->m_l_result = llvm::BranchInst::Create(label_if_true, label_if_end,
                                                result_tobool, this->m_block);
  }
  // true
  this->m_block = label_if_true;
  for (auto statement : *object->true_statements()) {
    /*
    CodeEmitLLVM *gen_true = new CodeEmitLLVM(
                                this->m_block);
                statement->accept(gen_true);
                this->m_block = gen_true->m_block;
     */
    this->m_block = CodeEmitLLVM::emit_code(statement, this->m_block);
  }
  if (this->m_block->getTerminator() == nullptr)
    llvm::BranchInst::Create(label_if_end, this->m_block);

  // false
  if (has_false_block) {
    this->m_block = label_if_false;
    for (auto statement : *object->false_statements()) {
      /*
      CodeEmitLLVM *gen_false =
                                      new CodeEmitLLVM(this->m_block);
                      statement->accept(gen_false);
                      this->m_block = gen_false->m_block;
       */
      this->m_block = CodeEmitLLVM::emit_code(statement, this->m_block);
    }
    if (this->m_block->getTerminator() == nullptr)
      llvm::BranchInst::Create(label_if_end, this->m_block);
  }

  this->m_block = label_if_end;
}

void CodeEmitLLVM::on_visit(CodeMethodReferenceExpression *object) {
  // std::cout << ">> CodeMethodReferenceExpression" << std::endl;
}

void CodeEmitLLVM::on_visit(CodeAttributeArgument *object) {}

void CodeEmitLLVM::on_visit(CodeAttributeDeclaration *object) {}

void CodeEmitLLVM::on_visit(CodeIterationStatement *object) {
  // std::cout << ">> CodeIterationStatement" << std::endl;

  llvm::LLVMContext &context = this->m_block->getContext();
  auto parent_function = this->m_block->getParent();

  llvm::BasicBlock *label_entry = this->m_block;
  llvm::BasicBlock *label_for_end =
      llvm::BasicBlock::Create(context, "for.end", parent_function);
  llvm::BasicBlock *label_for_cond =
      llvm::BasicBlock::Create(context, "for.cond", parent_function);
  llvm::BasicBlock *label_for_body =
      llvm::BasicBlock::Create(context, "for.body", parent_function);
  llvm::BasicBlock *label_for_inc =
      llvm::BasicBlock::Create(context, "for.inc", parent_function);

  // not used??
  // llvm::BasicBlock* final_jumpblock = label_for_end;

  // label_init
  if (object->init_statement() != nullptr) {
    auto gen_init_statement = new CodeEmitLLVM(label_entry);
    object->init_statement()->accept(gen_init_statement);
  }
  this->m_l_result = llvm::BranchInst::Create(label_for_cond, label_entry);

  // label_cond
  if (object->test_expression() != nullptr) {
    
    /*
    CodeEmitLLVM *gen_condition =
                                new CodeEmitLLVM(label_for_cond);
                auto test_expression = object->test_expression();
                test_expression->accept(gen_condition);
    */

    auto tmp =
        CodeEmitLLVM::get_r_value(object->test_expression(), label_for_cond);

    llvm::CmpInst *compare_instr = static_cast<llvm::CmpInst *>(tmp);
    llvm::CmpInst *result_tobool = nullptr;
    if (compare_instr == nullptr)
    {
      auto true_val = llvm::ConstantInt::get(
        context, llvm::APInt(32, llvm::StringRef("0"), 10));
      result_tobool = new llvm::ICmpInst(*label_for_cond, llvm::ICmpInst::ICMP_NE, tmp, true_val, "tobool");
    }
    else
    {
      auto true_val = llvm::ConstantInt::get(
        context, llvm::APInt(8, llvm::StringRef("0"), 10));
      result_tobool = new llvm::ICmpInst(*label_for_cond, llvm::ICmpInst::ICMP_NE, tmp, true_val, "tobool");

      //result_tobool = compare_instr;
    }

    llvm::BranchInst::Create(label_for_body, label_for_end, result_tobool, label_for_cond);
  } else {
    llvm::BranchInst::Create(label_for_cond, label_for_body);
  }

  // label_body
  if (object->statements()->size() > 0) {
    for (auto statement : *object->statements()) {
      /*
      CodeEmitLLVM *gen_s =
                                      new CodeEmitLLVM(label_for_body);
                      statement->accept(gen_s);
       */

      label_for_body = CodeEmitLLVM::emit_code(statement, label_for_body);
    }
  }
  llvm::BranchInst::Create(label_for_inc, label_for_body);

  // label_inc
  if (object->increment_statement() != nullptr) {
    auto gen_increment_statement = new CodeEmitLLVM(label_for_inc);
    object->increment_statement()->accept(gen_increment_statement);
  }
  llvm::BranchInst::Create(label_for_cond, label_for_inc);

  this->m_block = label_for_end;
}
}
