/* 
 * File:   code_condition_statement.hh
 * Author: mario
 *
 * Created on September 22, 2014, 9:31 AM
 */

#ifndef CODE_CONDITION_STATEMENT_HH
#define	CODE_CONDITION_STATEMENT_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

#include "code_statement.hh"
#include "code_expression.hh"

namespace mlang {
    class CodeConditionStatement : public CodeStatement {
    public:
        using CodeObject::scope;
        CodeConditionStatement();
        ~CodeConditionStatement();
        virtual void accept(CodeObjectVisitor* visitor);

        CodeStatementCollection* true_statements();
        CodeStatementCollection* false_statements();
        CodeExpression* condition();
        void condition(CodeExpression* value);
        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);
    private:
        CodeExpression* m_condition;
        CodeStatementCollection * m_true_statements;
        CodeStatementCollection * m_false_statements;
    };
}

#endif	/* CODE_CONDITION_STATEMENT_HH */

