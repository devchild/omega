/* 
 * File:   code_cast_expression.hh
 * Author: mario
 *
 * Created on October 16, 2014, 9:47 AM
 */

#ifndef CODE_CAST_EXPRESSION_HH
#define	CODE_CAST_EXPRESSION_HH

namespace mlang {
    class CodeExpression;
    class CodeTypeReference;
    class CodeScope;
    class ICodeObjectVisitor;
        
    class CodeCastExpression : public CodeExpression {
    public:
        using CodeObject::scope;
        CodeCastExpression();
        ~CodeCastExpression();
        virtual void accept(ICodeObjectVisitor* visitor);
        
        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);
        
        
        void expression(CodeExpression* value);
        CodeExpression* expression();
        
        void target_type(CodeTypeReference* value);
        CodeTypeReference* target_type();
        
    private:
        CodeTypeReference* m_target_type;
        CodeExpression* m_expression;
    };
}

#endif	/* CODE_CAST_EXPRESSION_HH */

