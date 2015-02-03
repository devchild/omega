/* 
 * File:   code_object_resolver.hh
 * Author: mario
 *
 * Created on October 5, 2014, 1:19 PM
 */

#ifndef CODE_OBJECT_RESOLVER_HH
#define	CODE_OBJECT_RESOLVER_HH

#include <vector>

#include "code_type_declaration.hh"
#include "code_namespace.hh"
#include "code_variable_reference_expression.hh"


namespace mlang {

    class CodeObjectResolver : public CodeObjectVisitor {
    public:
        using CodeObjectVisitor::visit;
                
        CodeObjectResolver();
        virtual ~CodeObjectResolver();
        virtual std::list<CodeObject*>* resolve() = 0;
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
        virtual void visit(CodeFileInclude* object);
        virtual void visit(CodeArrayCreateExpression* object);
        virtual void visit(CodeArrayIndexerExpression* object);
        virtual void visit(CodeFieldReferenceExpression* object);
        virtual void visit(CodeAssemblyCallExpression* object);
        virtual void visit(CodeSizeOfExpression* object);
        virtual void visit(CodeAttributeArgument* object);
        virtual void visit(CodeAttributeDeclaration* object);
    };
    
    class VariableFieldOrParameterResolver : public CodeObjectResolver
    {
    public:
        using CodeObjectResolver::visit;
        
        VariableFieldOrParameterResolver(CodeScope* scope, std::string name);
        ~VariableFieldOrParameterResolver();
        virtual std::list<CodeObject*>* resolve();
        virtual void visit(CodeParameterDeclarationExpression* object);
        virtual void visit(CodeVariableDeclarationStatement* object);
        virtual void visit(CodeMemberField* object);
    private:
        std::string m_name;
        CodeScope* m_scope;
        std::list<CodeObject*> * m_result;
        std::vector<std::string> m_tokens;
        uint token_index;
    };
    
    class CodeTypeDeclarationResolver : public CodeObjectResolver
    {
    public:
        using CodeObjectResolver::visit;
        
        CodeTypeDeclarationResolver(CodeScope* scope, std::string name, std::string namespace_name);
        ~CodeTypeDeclarationResolver();
        virtual std::list<CodeObject*>* resolve();
        virtual void visit(CodeTypeDeclaration* object);
        virtual void visit(CodeNamespace* object);
        virtual void visit(CodeCompileUnit* object);
    private:
        std::string m_name;
        CodeScope* m_scope;
        std::list<CodeObject*> * m_result;
        std::string m_namespace_name;
    };

    class CodeMemberMethodResolver : public CodeObjectResolver
    {
    public:
    	using CodeObjectResolver::visit;
    	CodeMemberMethodResolver(CodeScope* scope, std::string name, CodeTypeDeclarationCollection* parameter_types);
    	CodeMemberMethodResolver(CodeScope* scope, CodeTypeDeclaration* return_type, std::string name, CodeTypeDeclarationCollection* parameter_types);
    	~CodeMemberMethodResolver();
    	virtual std::list<CodeObject*>* resolve();
    	virtual void visit(CodeMemberMethod* object);
    private:
    	CodeTypeDeclaration* m_return_type;
    	std::string m_name;
    	CodeScope* m_scope;
    	CodeTypeDeclarationCollection* m_parameter_types;
    	std::list<CodeObject*> * m_result;
    };
}
#endif	/* CODE_OBJECT_RESOLVER_HH */

