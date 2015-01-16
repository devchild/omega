#include <codedom.hh>

namespace mlang {

    CodeVariableReferenceExpression::CodeVariableReferenceExpression()
        : CodeExpression()
    {
        this->m_variable_name = "";
    }
    
    CodeVariableReferenceExpression::~CodeVariableReferenceExpression() {
    
    }
    
    std::string
    CodeVariableReferenceExpression::variable_name()  {
        return this->m_variable_name;
    }
    
    void
    CodeVariableReferenceExpression::variable_name(std::string name) {
        this->m_variable_name = name;
    }
    
    void
    CodeVariableReferenceExpression::accept(CodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
    
    bool CodeVariableReferenceExpression::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeVariableReferenceExpression || CodeExpression::type_of(kind);
    }
    
    void 
    CodeVariableReferenceExpression::scope(CodeScope* scope) {
        CodeExpression::scope(scope);
    }
}
