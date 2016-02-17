#include <mlang.hh>

namespace mlang {
    CodeParameterDeclarationExpression::CodeParameterDeclarationExpression()
        : CodeExpression()
    {
        this->m_name = "";
        this->m_type = nullptr;
    }
        
    CodeParameterDeclarationExpression::~CodeParameterDeclarationExpression(){
            
    }
        
    std::string
    CodeParameterDeclarationExpression::name() {
        return this->m_name;
    }
    
    void
    CodeParameterDeclarationExpression::name(std::string name) {
        this->m_name = name;
    }
    
    CodeTypeReference*
    CodeParameterDeclarationExpression::type() {
        return this->m_type;
    }
    
    void
    CodeParameterDeclarationExpression::type(CodeTypeReference* value) {
        this->m_type = value;
    }
    
    void
    CodeParameterDeclarationExpression::accept(ICodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
    
    CodeMemberMethod * 
    CodeParameterDeclarationExpression::parent_method() {
        auto ret = static_cast<CodeMemberMethod*>(this->parent());
        return ret;
    }
    
    bool CodeParameterDeclarationExpression::type_of(CodeObjectKind kind) {
        return kind ==  CodeObjectKind::CodeParameterDeclarationExpression || CodeExpression::type_of(kind);
    }
    
    void 
    CodeParameterDeclarationExpression::scope(CodeScope* scope) {
        CodeExpression::scope(scope);
        if (this->m_type != nullptr)
            this->m_type->scope(scope);
    }
}
