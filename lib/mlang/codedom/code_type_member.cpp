#include <codedom.hh>

namespace mlang {
    CodeTypeMember::CodeTypeMember()
        : CodeObject()
    {
        
    }
    
    std::string
    CodeTypeMember::name() {
        return this->m_name;
    }
    
    void
    CodeTypeMember::name(std::string name) {
        this->m_name = name;
    }
    
    void
    CodeTypeMember::accept(CodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
    
    bool CodeTypeMember::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeTypeMember || CodeObject::type_of(kind);
    }
    
    void 
    CodeTypeMember::scope(CodeScope* scope) {
        CodeObject::scope(scope);
    }
}
