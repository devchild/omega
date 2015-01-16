#include <codedom.hh>

namespace mlang {

    CodeArrayIndexerExpression::~CodeArrayIndexerExpression() {

    }

    CodeArrayIndexerExpression::CodeArrayIndexerExpression()
        : CodeExpression()
    {
    	this->m_indices = new CodeExpressionCollection();
    	this->m_target_object = nullptr;
    }

    void CodeArrayIndexerExpression::accept(CodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
    
    bool CodeArrayIndexerExpression::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeArrayIndexerExpression || CodeExpression::type_of(kind);
    }

    void
	CodeArrayIndexerExpression::scope(CodeScope* scope) {
        CodeExpression::scope(scope);

        if (this->m_target_object != nullptr)
        	this->m_target_object->scope(scope);

        for(auto item: *this->m_indices) {
        	item->scope(scope);
        }
    }

	CodeExpressionCollection* 
	CodeArrayIndexerExpression::indices() {
		return this->m_indices;
	}

    CodeExpression* 
	CodeArrayIndexerExpression::target_object() {
    	return this->m_target_object;
    }
        
    void 
	CodeArrayIndexerExpression::target_object(CodeExpression* value) {
    	this->m_target_object = value;
    }
}


