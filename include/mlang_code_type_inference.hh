/*
 * mlang_code_type_inference.hh
 *
 *  Created on: Nov 11, 2014
 *      Author: mario
 */

#ifndef MLANGCODETYPEINFERENCE_HH
#define	MLANGCODETYPEINFERENCE_HH

#include "codedom.hh"

using namespace mlang;

class MLangCodeTypeInference: public CodeObjectVisitor {
private:
	CodeTypeReference* m_result;
public:
	CodeTypeReference* result();

	MLangCodeTypeInference();
	virtual ~MLangCodeTypeInference();
	/*CodeObjectVisitor*/
	virtual void visit(CodeBinaryOperatorExpression* object);
	virtual void visit(CodeCompileUnit* object);
	virtual void visit(CodeConditionStatement* object);
	virtual void visit(CodeExpression* object);
	virtual void visit(CodeExpressionStatement* object);
	virtual void visit(CodeIterationStatement* object);
	virtual void visit(CodeMemberField* object);
	virtual void visit(CodeMemberMethod* object);
	virtual void visit(CodeMemberProperty* object);
	virtual void visit(CodeMethodInvokeExpression* object);
	virtual void visit(CodeMethodReferenceExpression* object);
	virtual void visit(CodeMethodReturnStatement* object);
	virtual void visit(CodeNamespace* object);
	virtual void visit(CodeObject* object);
	virtual void visit(CodeParameterDeclarationExpression* object);
	virtual void visit(CodePrimitiveExpression* object);
	virtual void visit(CodeStatement* object);
	virtual void visit(CodeTypeDeclaration* object);
	virtual void visit(CodeTypeMember* object);
	virtual void visit(CodeTypeReference* object);
	virtual void visit(CodeVariableDeclarationStatement* object);
	virtual void visit(CodeVariableReferenceExpression* object);
	virtual void visit(CodeAssignExpression* object);
	virtual void visit(CodeCastExpression* object);
	virtual void visit(CodeObjectCreateExpression* object);
	virtual void visit(CodeIrBlockStatement* object);
	virtual void visit(CodeFileInclude* object);
	virtual void visit(CodeArrayCreateExpression* object);
	virtual void visit(CodeArrayIndexerExpression* object);
	virtual void visit(CodeFieldReferenceExpression* object);
	virtual void visit(CodeAssemblyCallExpression* object);

    virtual void visit(CodeAttributeArgument* object);
    virtual void visit(CodeAttributeDeclaration* object);
	virtual void visit(CodeSizeOfExpression* object);

};

#endif /* INCLUDE_MLANG_CODE_TYPE_INFERENCE_HH_ */
