
#include <codedom.hh>

namespace mlang {
    CodeConditionStatement::CodeConditionStatement()
        : CodeStatement()
    {
        this->m_condition = nullptr;
        this->m_true_statements = new CodeStatementCollection();
        this->m_false_statements = new CodeStatementCollection();
    }

    CodeConditionStatement::~CodeConditionStatement() {

    }

    CodeStatementCollection*
    CodeConditionStatement::true_statements() {
        return this->m_true_statements;
    }

    CodeStatementCollection*
    CodeConditionStatement::false_statements() {
        return this->m_false_statements;
    }

    CodeExpression*
    CodeConditionStatement::condition() {
        return this->m_condition;
    }

    void
    CodeConditionStatement::condition(CodeExpression* value) {
        this->m_condition = value;
    }
    
    bool 
    CodeConditionStatement::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeConditionStatement || CodeStatement::type_of(kind);
    }
    
    void
	CodeConditionStatement::accept(CodeObjectVisitor* visitor) {
        visitor->visit(this);
    }

    void 
    CodeConditionStatement::scope(CodeScope* scope) {
        CodeStatement::scope(scope);
        
        // condition_scope
        CodeScope* current_scope = scope->begin_scope();
        this->condition()->scope(current_scope);
        
        // begin true_statements
        current_scope = current_scope->begin_scope();
        for(auto x:*this->true_statements())
            x->scope(current_scope);
        current_scope = current_scope->end_scope();
        // end true_statements
        
        // begin false_statements
        current_scope = current_scope->begin_scope();
        for(auto x:*this->false_statements())
            x->scope(current_scope);
        current_scope = current_scope->end_scope();
        // end false_statements
        
        current_scope = current_scope->end_scope();
        // end condition_scope
    }
}
