/*
 * File:   code_attribute_argument.hh
 * Author: mario
 *
 * Created on September 21, 2014, 8:57 PM
 */

#ifndef CODE_ATTRIBUTE_ARGUMENT_HH
#define	CODE_ATTRIBUTE_ARGUMENT_HH

#include "code_object.hh"

namespace mlang {
    class CodeExpression;
    class ICodeObjectVisitor;

    class CodeAttributeArgument : public CodeObject {

    public:
        using CodeObject::scope;

        CodeAttributeArgument();
        ~CodeAttributeArgument();
        virtual void accept(ICodeObjectVisitor* visitor);

        virtual bool type_of(CodeObjectKind kind);
        void scope(CodeScope* scope) override;

        std::string name();
        void name(std::string value);

        CodeExpression* value();
        void value(CodeExpression* value);

    private:
        std::string m_name;
        CodeExpression* m_value;
    };
}


#endif	/* CODE_ASSIGN_EXPRESSION_HH */

