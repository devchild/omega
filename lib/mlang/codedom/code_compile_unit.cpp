#include <codedom.hh>
#include <iostream>

using namespace std;

namespace mlang {
    
    CodeCompileUnit::CodeCompileUnit()
        : CodeObject()
    {
        m_namespaces = new CodeNamespaceCollection();
        m_methods = new CodeMemberMethodCollection();
        m_types = new CodeTypeDeclarationCollection();
    }
    
    CodeNamespaceCollection*
    CodeCompileUnit::namespaces() {
        return this->m_namespaces;
    }
    
    CodeMemberMethodCollection*
	CodeCompileUnit::methods() {
    	return this->m_methods;
    }

    CodeTypeDeclarationCollection*
	CodeCompileUnit::types() {
    	return this->m_types;
    }

    void
    CodeCompileUnit::accept(ICodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
    
    bool 
    CodeCompileUnit::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeCompileUnit || CodeObject::type_of(kind);
    }
    
    void 
    CodeCompileUnit::scope(CodeScope* scope) {
        CodeObject::scope(scope);
        auto current_scope = scope->begin_scope();
        for(auto x:*this->namespaces()) {
            x->scope(current_scope);
        }

        for(auto x:*this->types()) {
        	x->scope(current_scope);
        }

        for(auto x:*this->methods()) {
            cout << "setting method scope" << endl;
        	x->scope(current_scope);
        }
        current_scope = current_scope->end_scope();
    }
}
