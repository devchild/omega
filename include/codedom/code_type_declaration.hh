/* 
 * File:   code_type_declaration.hh
 * Author: mario
 *
 * Created on August 25, 2014, 10:51 PM
 */

#ifndef CODE_TYPE_DECLARATION_HH
#define	CODE_TYPE_DECLARATION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace mlang {    
    class CodeTypeDeclaration : public CodeTypeMember {
    public:
        using CodeTypeMember::scope;
        CodeTypeDeclaration();
        
        std::string name();
        void name(std::string value);
        
        CodeTypeMemberCollection* members();
        virtual void accept(ICodeObjectVisitor* visitor);
        
        bool is_struct();
        void is_struct(bool value);
        
        bool is_class();
        void is_class(bool value);
        
        bool is_embedded();
        void is_embedded(bool value);

        virtual bool type_of(CodeObjectKind kind);
        
        virtual void scope(CodeScope* scope);
    private:
        bool m_is_struct;
        bool m_is_class;
        bool m_is_embedded;
        std::string m_name;
        CodeTypeMemberCollection* m_members;
    };
}

#endif	/* CODE_TYPE_DECLARATION_HH */

