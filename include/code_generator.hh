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

#include "codedom/code_object_visitor.hh"
#include "codedom/code_object_collections.hh"

namespace mlang {

    class DomProvider;

    class CodeGenerator {
    public:
        CodeGenerator(const DomProvider &p);

        CodeGenerator(const CodeGenerator &orig);

        virtual ~CodeGenerator();

        llvm::Module *GenerateCodeFromCompileUnit(mlang::CodeCompileUnit *compile_unit);

        /*
            CodeCompileUnit e,
            TextWriter w,
            CodeGeneratorOptions o
         */
        llvm::Type *
                get_llvm_type(CodeTypeReference *code_type_reference);

        const DomProvider &provider();

    private:
        llvm::Function *CreateFunction(llvm::Module *module, mlang::CodeMemberMethod *method);

        llvm::FunctionType *GetFunctionType(CodeTypeReference *code_type_reference,
                                            CodeParameterDeclarationExpressionCollection *params, bool is_var_args);

        llvm::Type *GetType(CodeTypeReference *code_type_reference);

        const DomProvider &m_provider;
        llvm::LLVMContext &m_context;
    };

    class CodeStatementGenerator : public CodeObjectVisitorBase {
    public:
        llvm::Value *result();

        llvm::BasicBlock *block();

        CodeStatementGenerator(llvm::BasicBlock *block);

        virtual ~CodeStatementGenerator();
        /*CodeObjectVisitor*/
    private:

        llvm::Type *get_llvm_type(CodeTypeReference *code_type_reference);

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

        virtual void on_visit(CodeSizeOfExpression *object);

        virtual void on_visit(CodeAttributeArgument *object);

        virtual void on_visit(CodeAttributeDeclaration *object);

        llvm::BasicBlock *m_block;
        llvm::Value *m_result;
    };
}

#endif	/* MLANGCODEGENERATOR_HH */

