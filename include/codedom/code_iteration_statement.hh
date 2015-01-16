/* 
 * File:   code_iteration_statement.hh
 * Author: mario
 *
 * Created on September 24, 2014, 7:01 PM
 */

#ifndef CODE_ITERATION_STATEMENT_HH
#define	CODE_ITERATION_STATEMENT_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

#include "code_statement.hh"
#include "code_expression.hh"

namespace mlang {    
    class CodeIterationStatement : public CodeStatement {
    public:
        using CodeObject::scope;
        CodeIterationStatement();
        ~CodeIterationStatement();
        virtual void accept(CodeObjectVisitor* visitor);
        
        CodeStatement* increment_statement();
        CodeStatement* init_statement();
        CodeStatementCollection* statements();
        
        
        void increment_statement(CodeStatement* value);
        void init_statement(CodeStatement* value);
        
        CodeExpression* test_expression();
        void test_expression(CodeExpression* value);
        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);
        
    private:
        CodeStatement* m_increment_statement;
        CodeStatement* m_init_statement;
        CodeStatementCollection* m_statements;
        CodeExpression* m_test_expression;
    };
}

#endif	/* CODE_ITERATION_STATEMENT_HH */

