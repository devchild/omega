/* 
 * File:   MLangCodeGenerator.hh
 * Author: mario
 *
 * Created on June 24, 2014, 11:26 PM
 */

#ifndef MLANGCODEGENERATOR_HH
#define	MLANGCODEGENERATOR_HH

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Support/raw_ostream.h>

#include <codedom.hh>

using namespace mlang;

class MLangDomProvider;

class MLangCodeGenerator {
public:
    MLangCodeGenerator(const MLangDomProvider& p);
    MLangCodeGenerator(const MLangCodeGenerator& orig);
    virtual ~MLangCodeGenerator();
    llvm::Module* GenerateCodeFromCompileUnit(mlang::CodeCompileUnit* compile_unit);
    /*
        CodeCompileUnit e,
        TextWriter w,
        CodeGeneratorOptions o
     */

    const MLangDomProvider& provider();
private:
    llvm::Function* CreateFunction(llvm::Module * module, mlang::CodeMemberMethod* method);
    llvm::FunctionType* GetFunctionType(CodeTypeReference* code_type_reference,  CodeParameterDeclarationExpressionCollection* params, bool is_var_args);
    llvm::Type* GetType(CodeTypeReference* code_type_reference);

    const MLangDomProvider& m_provider;
    llvm::LLVMContext& m_context;
};

class MLangCodeStatementGenerator : public CodeObjectVisitor {
private:
    llvm::BasicBlock* m_block;
    llvm::Value* m_result;

public:
    llvm::Value* result();
    llvm::BasicBlock* block();
    
    MLangCodeStatementGenerator(llvm::BasicBlock* block);
    virtual ~MLangCodeStatementGenerator();
    /*CodeObjectVisitor*/
    virtual void visit(CodeBinaryOperatorExpression* object);
    virtual void visit(CodeCompileUnit* object);
    virtual void visit(CodeConditionStatement* object);
    virtual void visit(CodeExpression* object);
    virtual void visit(CodeExpressionStatement* object);
    virtual void visit(CodeIterationStatement* object);
    virtual void visit(CodeMemberField* object);
    virtual void visit(CodeMemberMethod* object);
    virtual void visit(CodeMemberProperty* object);
    virtual void visit(CodeMethodInvokeExpression* object);
    virtual void visit(CodeMethodReferenceExpression* object);
    virtual void visit(CodeMethodReturnStatement* object);
    virtual void visit(CodeNamespace* object);
    virtual void visit(CodeObject* object);
    virtual void visit(CodeParameterDeclarationExpression* object);
    virtual void visit(CodePrimitiveExpression* object);
    virtual void visit(CodeStatement* object);
    virtual void visit(CodeTypeDeclaration* object);
    virtual void visit(CodeTypeMember* object);
    virtual void visit(CodeTypeReference* object);
    virtual void visit(CodeVariableDeclarationStatement* object);
    virtual void visit(CodeVariableReferenceExpression* object);
    virtual void visit(CodeAssignExpression* object);
    virtual void visit(CodeCastExpression* object);
    virtual void visit(CodeObjectCreateExpression* object);
    virtual void visit(CodeIrBlockStatement* object);
    virtual void visit(CodeFileImport* object);
    virtual void visit(CodeArrayCreateExpression* object);
    virtual void visit(CodeArrayIndexerExpression* object);
    virtual void visit(CodeFieldReferenceExpression* object);
    virtual void visit(CodeAssemblyCallExpression* object);
};

#endif	/* MLANGCODEGENERATOR_HH */

