#include <codedom.hh>

namespace mlang {

    CodeMethodReferenceExpression::~CodeMethodReferenceExpression() {

    }

    CodeMethodReferenceExpression::CodeMethodReferenceExpression()
        : CodeExpression()
    {
    	this->m_method_name = "";
    	this->m_target_object = nullptr;
    	this->m_type_arguments = new CodeTypeReferenceCollection();
    }

    std::string CodeMethodReferenceExpression::method_name() {
        return this->m_method_name;
    }

    void CodeMethodReferenceExpression::method_name(std::string value) {
        this->m_method_name = value;
    }

    CodeExpression* CodeMethodReferenceExpression::target_object() {
        return this->m_target_object;
    }

    CodeTypeReferenceCollection&
	CodeMethodReferenceExpression::type_arguments() {
    	return *this->m_type_arguments;
    }

    void CodeMethodReferenceExpression::target_object(CodeExpression* value) {
        this->m_target_object = value;
    }

    void CodeMethodReferenceExpression::accept(CodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
    
    bool CodeMethodReferenceExpression::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeMethodReferenceExpression || CodeExpression::type_of(kind);
    }

    void 
    CodeMethodReferenceExpression::scope(CodeScope* scope) {
        CodeExpression::scope(scope);
        if (this->target_object() != nullptr)
            this->target_object()->scope(scope);

        for(auto x:this->type_arguments())
            x->scope(scope);
    }
}

