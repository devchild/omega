/*
 * code_object_create_expression.h
 *
 *  Created on: Oct 27, 2014
 *      Author: mario
 */

#ifndef CODE_OBJECT_CREATE_EXPRESSION_HH
#define CODE_OBJECT_CREATE_EXPRESSION_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace mlang {

class CodeNamespace;
class CodeTypeReference;

class CodeObjectCreateExpression: public CodeExpression {
public:
    using CodeObject::scope;
	CodeObjectCreateExpression();
	virtual ~CodeObjectCreateExpression();

	CodeExpressionCollection * parameters();
	void create_type(CodeTypeReference* value);
	CodeTypeReference* create_type();

	bool type_of(CodeObjectKind kind);
	void accept(ICodeObjectVisitor* visitor);
	void scope(CodeScope* scope);
private:
	CodeExpressionCollection * m_parameters;
	CodeTypeReference* m_create_type;
};

} /* namespace mlang */

#endif /* INCLUDE_CODEDOM_CODE_OBJECT_CREATE_EXPRESSION_HH_ */
