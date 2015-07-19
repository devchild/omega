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

    class ICodeObjectResolver {
    protected:
        // allow construction for child classes only
    	ICodeObjectResolver();
    public:
        virtual ~ICodeObjectResolver();

        // forbid copying
        ICodeObjectResolver(ICodeObjectResolver const &) = delete;
        ICodeObjectResolver & operator=(ICodeObjectResolver const &) = delete;
        virtual std::list<CodeObject*>* resolve() = 0;
    };
    
    class VariableFieldOrParameterResolver : public CodeObjectVisitorBase, public ICodeObjectResolver
    {
    public:
        VariableFieldOrParameterResolver(CodeScope* scope, std::string name);
        ~VariableFieldOrParameterResolver();
        virtual std::list<CodeObject*>* resolve();

    private:
    	using CodeObjectVisitorBase::on_visit;

        virtual void on_visit(CodeParameterDeclarationExpression* object);
        virtual void on_visit(CodeVariableDeclarationStatement* object);
        virtual void on_visit(CodeMemberField* object);

        std::string m_name;
        CodeScope* m_scope;
        std::list<CodeObject*> * m_result;
        std::vector<std::string> m_tokens;
        int token_index;
    };
    
    class CodeTypeDeclarationResolver : public CodeObjectVisitorBase, public ICodeObjectResolver
    {
    public:
        CodeTypeDeclarationResolver(CodeScope* scope, std::string name, std::string namespace_name);
        ~CodeTypeDeclarationResolver();
        virtual std::list<CodeObject*>* resolve();

    private:
    	using CodeObjectVisitorBase::on_visit;

        virtual void on_visit(CodeTypeDeclaration* object);
        virtual void on_visit(CodeNamespace* object);
        virtual void on_visit(CodeCompileUnit* object);
        std::string m_name;
        CodeScope* m_scope;
        std::list<CodeObject*> * m_result;
        std::string m_namespace_name;
    };

    class CodeMemberMethodResolver : public CodeObjectVisitorBase, public ICodeObjectResolver
    {
    public:
    	CodeMemberMethodResolver(CodeScope* scope, std::string name, CodeTypeDeclarationCollection* parameter_types);
    	CodeMemberMethodResolver(CodeScope* scope, CodeTypeDeclaration* return_type, std::string name, CodeTypeDeclarationCollection* parameter_types);
    	~CodeMemberMethodResolver();
    	virtual std::list<CodeObject*>* resolve();

    private:
    	using CodeObjectVisitorBase::on_visit;

    	virtual void on_visit(CodeMemberMethod* object);
    	CodeTypeDeclaration* m_return_type;
    	std::string m_name;
    	CodeScope* m_scope;
    	CodeTypeDeclarationCollection* m_parameter_types;
    	std::list<CodeObject*> * m_result;
    };
}
#endif	/* CODE_OBJECT_RESOLVER_HH */

