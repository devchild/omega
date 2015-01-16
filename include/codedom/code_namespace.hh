/* 
 * File:   code_namespace.hh
 * Author: mario
 *
 * Created on August 25, 2014, 10:42 PM
 */

#ifndef CODE_NAMESPACE_HH
#define	CODE_NAMESPACE_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

#include <list>

namespace mlang {
    
    class CodeNamespace : public CodeObject {
    public:
        using CodeObject::scope;
        CodeNamespace();
        virtual ~CodeNamespace();
        
        std::string name();
        void name(std::string value);
        CodeTypeDeclarationCollection* types();
        CodeMemberMethodCollection* methods();
        virtual void accept(CodeObjectVisitor* visitor);
        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);
    private:
        CodeTypeDeclarationCollection* m_types;
        CodeMemberMethodCollection* m_methods;
        std::string m_name;
    };
}

#endif	/* CODE_NAMESPACE_HH */

