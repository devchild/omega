/* 
 * File:   code_method_invoke_expression.hh
 * Author: mario
 *
 * Created on September 18, 2014, 9:37 AM
 */

#ifndef CODE_METHOD_INVOKE_EXPRESSION_HH
#define	CODE_METHOD_INVOKE_EXPRESSION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

#include "code_expression.hh"
#include "code_method_reference_expression.hh"

namespace mlang {
    class CodeMethodInvokeExpression : public CodeExpression {    
    public:
        using CodeObject::scope;

        CodeMethodInvokeExpression();
        virtual ~CodeMethodInvokeExpression();
        virtual void accept(ICodeObjectVisitor* visitor);
        
        CodeExpressionCollection* parameters();
        CodeMethodReferenceExpression* method();
        void method(CodeMethodReferenceExpression* value);
        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);
    private:
        CodeExpressionCollection* m_parameters;
        CodeMethodReferenceExpression* m_method;
    };
}

#endif	/* CODE_METHOD_INVOKE_EXPRESSION_HH */

