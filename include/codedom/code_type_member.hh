/* 
 * File:   code_type_member.hh
 * Author: mario
 *
 * Created on August 25, 2014, 10:45 PM
 */

#ifndef CODE_TYPE_MEMBER_HH
#define	CODE_TYPE_MEMBER_HH
#include <string>

#include "code_scope.hh"
#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace mlang {    
    class CodeTypeMember : public CodeObject {
    public:
        using CodeObject::scope;
        CodeTypeMember();
        std::string name();
        void name(std::string name);
        CodeAttributeDeclarationCollection& custom_attributes();

        virtual void accept(CodeObjectVisitor* visitor);
        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);
    private:
        std::string m_name;
        CodeAttributeDeclarationCollection m_custom_attributes;
    };
}

#endif	/* CODE_TYPE_MEMBER_HH */

