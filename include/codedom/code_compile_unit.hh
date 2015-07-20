/* 
 * File:   code_compilation_unit.hh
 * Author: mario
 *
 * Created on August 25, 2014, 10:38 PM
 */

#ifndef CODE_COMPILATION_UNIT_HH
#define	CODE_COMPILATION_UNIT_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace mlang {    
    class CodeScope;
    
    class CodeCompileUnit : public CodeObject {
    public:
        using CodeObject::scope;
        CodeCompileUnit();
        CodeNamespaceCollection* namespaces();
        virtual void accept(ICodeObjectVisitor* visitor);
        
        CodeMemberMethodCollection* methods();
        CodeTypeDeclarationCollection* types();

        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);
        void merge(mlang::CodeCompileUnit* unit);    
    private:
        CodeNamespaceCollection* m_namespaces;
        CodeMemberMethodCollection* m_methods;
        CodeTypeDeclarationCollection* m_types;
    };
}

#endif	/* CODE_COMPILATION_UNIT_HH */

