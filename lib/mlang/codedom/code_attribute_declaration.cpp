#include <codedom.hh>

namespace mlang {
    CodeAttributeDeclaration::CodeAttributeDeclaration()
        : CodeObject() {
    	this->m_name = "";
    }

    CodeAttributeDeclaration::~CodeAttributeDeclaration() {
    }

    void
	CodeAttributeDeclaration::accept(ICodeObjectVisitor* visitor) {
        visitor->visit(this);
    }

    void
	CodeAttributeDeclaration::scope(CodeScope* scope) {
    	CodeObject::scope(scope);
    }

    bool
	CodeAttributeDeclaration::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeAttributeDeclaration || CodeObject::type_of(kind);
    }

    std::string
	CodeAttributeDeclaration::name() {
    	return this->m_name;
    }

    void
	CodeAttributeDeclaration::name(std::string value) {
    	this->m_name = value;
    }

    CodeAttributeArgumentCollection&
	CodeAttributeDeclaration::arguments() {
    	return this->m_arguments;
    }
}
