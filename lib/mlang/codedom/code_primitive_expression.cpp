#include <mlang.hh>

namespace mlang {

CodePrimitiveExpression::CodePrimitiveExpression() :
		CodeExpression() {
	this->m_value = nullptr;
}

CodePrimitiveExpression::~CodePrimitiveExpression() {

}

void* CodePrimitiveExpression::value() {
	return this->m_value;
}

void CodePrimitiveExpression::value(void* value) {
	this->m_value = value;
}

void CodePrimitiveExpression::accept(ICodeObjectVisitor* visitor) {
	visitor->visit(this);
}

bool CodePrimitiveExpression::type_of(CodeObjectKind kind) {
	return kind == CodeObjectKind::CodePrimitiveExpression
			|| CodeExpression::type_of(kind);
}

void CodePrimitiveExpression::scope(CodeScope* scope) {
	CodeExpression::scope(scope);
	this->type()->scope(scope);
}

CodeTypeReference*
CodePrimitiveExpression::type() {
	return this->m_type;
}

std::string
CodePrimitiveExpression::value_as_string() {
	std::string v = *(std::string*) this->m_value;
	const char* strdata = v.c_str();
	std::string v_translated;
	for (int i = 1; i < v.length() - 1; ++i) {
		char c = strdata[i];
		if (c == '\\') {
			char next = strdata[i + 1];

			switch (next) {

			case '\\':
				c = '\\';
				i++;
				break;
			case '\'':
				c = '\'';
				i++;
				break;
			case '"':
				c = '"';
				i++;
				break;
			case 'n':
				c = '\n';
				i++;
				break;
			case 'r':
				c = '\r';
				i++;
				break;
			case 't':
				c = '\t';
				i++;
				break;
			case 'b':
				c = '\b';
				i++;
				break;
			case 'f':
				c = '\f';
				i++;
				break;
			case 'a':
				c = '\a';
				i++;
				break;
			}
		}

		v_translated += c;
	}
	v = v_translated;
	return v;
}

void CodePrimitiveExpression::type(CodeTypeReference* value) {
	this->m_type = value;
}
}

