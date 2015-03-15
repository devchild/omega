/*
 * File:   code_attribute_declaration.hh
 * Author: mario
 *
 * Created on September 21, 2014, 8:57 PM
 */

#ifndef CODE_ATTRIBUTE_DECLARATION_HH
#define	CODE_ATTRIBUTE_DECLARATION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace mlang {
    class CodeAttributeDeclaration : public CodeObject {

    public:
        using CodeObject::scope;

        CodeAttributeDeclaration();
        ~CodeAttributeDeclaration();
        virtual void accept(ICodeObjectVisitor* visitor);

        virtual bool type_of(CodeObjectKind kind);
        void scope(CodeScope* scope) override;

        std::string name();
        void name(std::string name);

        CodeAttributeArgumentCollection& arguments();

    private:
        CodeAttributeArgumentCollection m_arguments;
        std::string m_name;
    };
}


#endif	/* CODE_ASSIGN_EXPRESSION_HH */

