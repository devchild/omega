/*
 * File:   code_array_creation_expression.hh
 * Author: mario
 *
 * Created on September 21, 2014, 8:57 PM
 */

#ifndef CODE_ARRAY_CREATE_EXPRESSION_HH
#define	CODE_ARRAY_CREATE_EXPRESSION_HH

#include "code_expression.hh"

namespace mlang {
    class CodeScope;
    class ICodeObjectVisitor;

    class CodeArrayCreateExpression : public CodeExpression {
    public:
        using CodeObject::scope;
        CodeArrayCreateExpression();
        ~CodeArrayCreateExpression();
        virtual void accept(ICodeObjectVisitor* visitor) override;

        virtual bool type_of(CodeObjectKind kind) override;
        void scope(CodeScope* scope) override;

        CodeExpression* size_expression();
        void size_expression(CodeExpression* value);

        CodeTypeReference* create_type();
        void create_type(CodeTypeReference* value);

    private:
        CodeExpression* m_size_expression;
        CodeTypeReference* m_create_type;
    };
}


#endif	/* CODE_ARRAY_CREATION_EXPRESSION_HH */

