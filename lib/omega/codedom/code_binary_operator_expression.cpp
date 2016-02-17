#include "mlang.hh"

namespace mlang {
    CodeBinaryOperatorExpression::CodeBinaryOperatorExpression()
        : CodeExpression()
    {
        this->m_left = nullptr;
        this->m_right = nullptr;
        this->m_operator = mlang::CodeBinaryOperatorType::Add;
    }

    CodeBinaryOperatorExpression::~CodeBinaryOperatorExpression() {
    }
    
    CodeExpression* 
    CodeBinaryOperatorExpression::left() {
        return this->m_left;
    }
    
    CodeBinaryOperatorType
    CodeBinaryOperatorExpression::operator_() {
        return this->m_operator;
    }
    
    CodeExpression* 
    CodeBinaryOperatorExpression::right() {
        return this->m_right;
    }
       
    void
    CodeBinaryOperatorExpression::left(CodeExpression* value) {
        this->m_left = value;
    }
    
    void 
    CodeBinaryOperatorExpression::operator_(const CodeBinaryOperatorType value) {
        this->m_operator = value;
    }
    
    void 
    CodeBinaryOperatorExpression::right(CodeExpression* value) {
        this->m_right = value;
    }
    
    void
    CodeBinaryOperatorExpression::accept(ICodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
    
    bool CodeBinaryOperatorExpression::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeBinaryOperatorExpression || CodeExpression::type_of(kind);
    }
    
    void 
    CodeBinaryOperatorExpression::scope(CodeScope* scope) {
        CodeExpression::scope(scope);
           
        if (this->m_left != nullptr)
            this->m_left->scope(scope);
        if (this->m_right != nullptr)
            this->m_right->scope(scope);
    }
}

