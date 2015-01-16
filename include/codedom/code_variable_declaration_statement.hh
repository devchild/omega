/* 
 * File:   code_variable_declaration_statement.hh
 * Author: mario
 *
 * Created on September 9, 2014, 10:36 PM
 */

#ifndef CODE_VARIABLE_DECLARATION_STATEMENT_HH
#define	CODE_VARIABLE_DECLARATION_STATEMENT_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace mlang {
    class CodeVariableDeclarationStatement : public CodeStatement {
    public:
        using CodeObject::scope;
        using CodeObject::resolve_type;
        CodeVariableDeclarationStatement();
        ~CodeVariableDeclarationStatement();
        
        std::string name();
        CodeTypeReference* type();
        CodeExpression* init_expression();
        
        CodeMemberMethod* parent_method();
        
        void name(std::string value);
        void type(CodeTypeReference* value);
        void init_expression(CodeExpression* value);
        virtual void accept(CodeObjectVisitor* visitor);
        virtual bool type_of(CodeObjectKind kind);
        
        virtual void scope(CodeScope* scope);
        
    private:
        std::string m_name;
        CodeTypeReference* m_type;
        CodeExpression* m_init_expression;
    };
}

#endif	/* CODE_VARIABLE_DECLARATION_STATEMENT_HH */

