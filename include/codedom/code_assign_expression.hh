/* 
 * File:   code_assign_statement.hh
 * Author: mario
 *
 * Created on September 21, 2014, 8:57 PM
 */

#ifndef CODE_ASSIGN_EXPRESSION_HH
#define	CODE_ASSIGN_EXPRESSION_HH

#include "code_expression.hh"
#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace mlang {
    class CodeAssignExpression : public CodeExpression {

    public:
        using CodeObject::scope;

        CodeAssignExpression();
        ~CodeAssignExpression();
        virtual void accept(CodeObjectVisitor* visitor);
        
        void left(CodeExpression* value);
        CodeExpression* left();
        
        void right(CodeExpression* value);
        CodeExpression* right();
        
        virtual bool type_of(CodeObjectKind kind);
        void scope(CodeScope* scope) override;
    private:
        CodeExpression * m_left;
        CodeExpression * m_right;
    };
}


#endif	/* CODE_ASSIGN_EXPRESSION_HH */
