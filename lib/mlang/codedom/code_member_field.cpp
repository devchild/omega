#include <mlang.hh>

namespace mlang {
    CodeMemberField::CodeMemberField()
        : CodeTypeMember()
    {
        this->m_init_expression = nullptr;
        this->m_type = nullptr;
    }
    
    void
    CodeMemberField::accept(ICodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
    
    void 
    CodeMemberField::init_expression(CodeExpression* value){
        this->m_init_expression = value;
    }
    
    CodeExpression* 
    CodeMemberField::init_expression(){
        return this->m_init_expression;
    }
        
    void 
    CodeMemberField::type(CodeTypeReference* value){
        this->m_type = value;
    }
        
    CodeTypeReference* 
    CodeMemberField::type(){
        return this->m_type;
    }
    
    bool CodeMemberField::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeMemberField || CodeTypeMember::type_of(kind);
    }

    void 
    CodeMemberField::scope(CodeScope* scope) {
        CodeTypeMember::scope(scope);
        
        if (this->m_type != nullptr)
            this->m_type->scope(scope);
        
        if (this->m_init_expression != nullptr)
            this->m_init_expression->scope(scope);
    }
}
