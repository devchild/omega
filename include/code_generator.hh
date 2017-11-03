/*
 * File:   MLangCodeGenerator.hh
 * Author: mario
 *
 * Created on June 24, 2014, 11:26 PM
 */

#ifndef MLANGCODEGENERATOR_HH
#define MLANGCODEGENERATOR_HH

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Instructions.h>

#include "codedom/code_object_visitor.hh"
#include "codedom/code_object_collections.hh"

namespace omega {

class DomProvider;

class CodeGenerator {
 public:
  CodeGenerator(const DomProvider &p);

  CodeGenerator(const CodeGenerator &orig);

  virtual ~CodeGenerator();

  llvm::Module *GenerateCodeFromCompileUnit(
      omega::CodeCompileUnit *compile_unit);

  /*
      CodeCompileUnit e,
      TextWriter w,
      CodeGeneratorOptions o
   */
  llvm::Type *get_llvm_type(CodeTypeReference *code_type_reference);

  const DomProvider &provider();

 private:
  llvm::Function *CreateFunction(llvm::Module *module,
                                 omega::CodeMemberMethod *method);

  llvm::FunctionType *GetFunctionType(
      CodeTypeReference *code_type_reference,
      CodeParameterDeclarationExpressionCollection *params, bool is_var_args);

  llvm::Type *GetType(CodeTypeReference *code_type_reference);

  const DomProvider &m_provider;
  llvm::LLVMContext &m_context;
};

class CodeEmitLLVM : public CodeObjectVisitorBase {
 public:
  static llvm::BasicBlock *emit_code(CodeObject *object,
                                     llvm::BasicBlock *block);

  //
  // --> a <-- = 2 + 2
  //
  static llvm::Value *get_l_value(CodeObject *object, llvm::BasicBlock *block);

  //
  // a = --> 2 + 2 <--
  // In general a loadinst is aplied to the get_l_value
  static llvm::Value *get_r_value(CodeObject *object, llvm::BasicBlock *block);

  virtual ~CodeEmitLLVM();

  CodeEmitLLVM(llvm::BasicBlock *block);

  llvm::BasicBlock *m_block;
  llvm::Value *m_l_result;
  llvm::Value *m_r_result;
  /*CodeObjectVisitor*/
 private:
  virtual void on_visit(CodeBinaryOperatorExpression *object) override;

  virtual void on_visit(CodeCompileUnit *object) override;

  virtual void on_visit(CodeConditionStatement *object) override;

  virtual void on_visit(CodeExpression *object) override;

  virtual void on_visit(CodeExpressionStatement *object) override;

  virtual void on_visit(CodeIterationStatement *object) override;

  virtual void on_visit(CodeMemberField *object) override;

  virtual void on_visit(CodeMemberMethod *object) override;

  virtual void on_visit(CodeMemberProperty *object) override;

  virtual void on_visit(CodeMethodInvokeExpression *object) override;

  virtual void on_visit(CodeMethodReferenceExpression *object) override;

  virtual void on_visit(CodeMethodReturnStatement *object) override;

  virtual void on_visit(CodeNamespace *object) override;

  virtual void on_visit(CodeObject *object) override;

  virtual void on_visit(CodeParameterDeclarationExpression *object) override;

  virtual void on_visit(CodePrimitiveExpression *object) override;

  virtual void on_visit(CodeStatement *object) override;

  virtual void on_visit(CodeTypeDeclaration *object) override;

  virtual void on_visit(CodeTypeMember *object) override;

  virtual void on_visit(CodeTypeReference *object) override;

  virtual void on_visit(CodeVariableDeclarationStatement *object) override;

  virtual void on_visit(CodeVariableReferenceExpression *object) override;

  virtual void on_visit(CodeAssignExpression *object) override;

  virtual void on_visit(CodeCastExpression *object) override;

  virtual void on_visit(CodeObjectCreateExpression *object) override;

  virtual void on_visit(CodeIrBlockStatement *object) override;

  virtual void on_visit(CodeFileInclude *object) override;

  virtual void on_visit(CodeArrayCreateExpression *object) override;

  virtual void on_visit(CodeArrayIndexerExpression *object) override;

  virtual void on_visit(CodeFieldReferenceExpression *object) override;

  virtual void on_visit(CodeAssemblyCallExpression *object) override;

  virtual void on_visit(CodeSizeOfExpression *object) override;

  virtual void on_visit(CodeAttributeArgument *object) override;

  virtual void on_visit(CodeAttributeDeclaration *object) override;
};
}

#endif /* MLANGCODEGENERATOR_HH */
