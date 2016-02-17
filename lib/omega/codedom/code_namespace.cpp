#include <mlang.hh>

namespace mlang {
    CodeNamespace::CodeNamespace()
        : CodeObject()
    {
        this->m_name = "";
        this->m_types = new CodeTypeDeclarationCollection();
        this->m_methods = new CodeMemberMethodCollection();
    }
    
    CodeNamespace::~CodeNamespace() {

    }

    std::string CodeNamespace::name() {
        return this->m_name;
    }
    
    void CodeNamespace::name(std::string value) {
        this->m_name = value;
    }
    
    CodeTypeDeclarationCollection*
    CodeNamespace::types() {
        return this->m_types;
    }
    
    CodeMemberMethodCollection*
    CodeNamespace::methods() {
        return this->m_methods;
    }
    
    void
    CodeNamespace::accept(ICodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
    
    bool 
    CodeNamespace::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeNamespace || CodeObject::type_of(kind);
    }
    
    void 
    CodeNamespace::scope(CodeScope* scope) {
        CodeObject::scope(scope);
        auto current_scope = scope->begin_scope();
        for(auto x:*this->types()) {
            x->scope(current_scope);
        }
        
        for(auto x:*this->methods()) {
            x->scope(current_scope);
        }
        current_scope = current_scope->end_scope();
    }
}
