#include <codedom.hh>

namespace mlang {
	CodeAssemblyCallExpression::CodeAssemblyCallExpression()
		: CodeExpression()
	{
		this->m_content = "";
		this->m_constraints = "";
		this->m_parameters = new CodeExpressionCollection();
	}

    CodeExpressionCollection* CodeAssemblyCallExpression::parameters() {
        return this->m_parameters;
    }

	CodeAssemblyCallExpression::~CodeAssemblyCallExpression() {

	}

	void
	CodeAssemblyCallExpression::accept(CodeObjectVisitor* visitor) {
		visitor->visit(this);
	}

	void
	CodeAssemblyCallExpression::content(std::string value) {
		this->m_content = value;
	}

	std::string
	CodeAssemblyCallExpression::content() {
		return this->m_content;
	}

	void
	CodeAssemblyCallExpression::constraints(std::string value) {
		this->m_constraints = value;
	}

	std::string
	CodeAssemblyCallExpression::constraints() {
		return this->m_constraints;
	}

	bool
	CodeAssemblyCallExpression::type_of(CodeObjectKind kind) {
		return kind == CodeObjectKind::CodeAssemblyCallExpression || CodeExpression::type_of(kind);
	}

	void
	CodeAssemblyCallExpression::scope(CodeScope* scope) {
		CodeExpression::scope(scope);

        for(auto x:*this->m_parameters)
            x->scope(scope);
	}
}
