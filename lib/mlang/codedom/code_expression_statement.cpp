
/* 
 * File:   code_expression.cpp
 * Author: mario
 * 
 * Created on September 11, 2014, 9:34 AM
 */

#include "codedom.hh"

namespace mlang {
    CodeExpressionStatement::CodeExpressionStatement()
        : CodeStatement()
    {
    	this->m_expression = nullptr;
    }

    CodeExpressionStatement::~CodeExpressionStatement() {
    }
    
    CodeExpression* CodeExpressionStatement::expression(){
        return this->m_expression;
    }
        
    void CodeExpressionStatement::expression(CodeExpression* value){
        this->m_expression = value;
    }
    
    void CodeExpressionStatement::accept(CodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
    
    bool CodeExpressionStatement::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeExpressionStatement || CodeStatement::type_of(kind);
    }
    
    void 
    CodeExpressionStatement::scope(CodeScope* scope) {
        CodeObject::scope(scope);
        if (this->m_expression != nullptr)
            this->m_expression->scope(scope);
    }
}
