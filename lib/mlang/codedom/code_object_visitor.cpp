/*
 * code_object_visitor.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: mario
 */

#include <codedom.hh>

namespace mlang {
ICodeObjectVisitor::ICodeObjectVisitor() {
}


ICodeObjectVisitor::~ICodeObjectVisitor() {
}


void ICodeObjectVisitor::visit(CodeBinaryOperatorExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeCompileUnit* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeConditionStatement* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeExpressionStatement* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeIterationStatement* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeMemberField* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeMemberMethod* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeMemberProperty* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeMethodInvokeExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeMethodReferenceExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeMethodReturnStatement* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeNamespace* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeObject* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeParameterDeclarationExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodePrimitiveExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeStatement* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeTypeDeclaration* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeTypeMember* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeTypeReference* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeVariableDeclarationStatement* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeVariableReferenceExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeAssignExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeCastExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeObjectCreateExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeIrBlockStatement* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeFileInclude* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeArrayCreateExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeArrayIndexerExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeFieldReferenceExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeAssemblyCallExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeSizeOfExpression* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeAttributeDeclaration* object) {
	this->on_visit(object);
}

void ICodeObjectVisitor::visit(CodeAttributeArgument* object) {
	this->on_visit(object);
}


/*
 *         CodeObjectVisitorBase
 */
CodeObjectVisitorBase::CodeObjectVisitorBase() {
}
CodeObjectVisitorBase::~CodeObjectVisitorBase() {
}

void CodeObjectVisitorBase::on_visit(CodeBinaryOperatorExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeCompileUnit* object) {
}

void CodeObjectVisitorBase::on_visit(CodeConditionStatement* object) {
}

void CodeObjectVisitorBase::on_visit(CodeExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeExpressionStatement* object) {
}

void CodeObjectVisitorBase::on_visit(CodeIterationStatement* object) {
}

void CodeObjectVisitorBase::on_visit(CodeMemberField* object) {
}

void CodeObjectVisitorBase::on_visit(CodeMemberMethod* object) {
}

void CodeObjectVisitorBase::on_visit(CodeMemberProperty* object) {
}

void CodeObjectVisitorBase::on_visit(CodeMethodInvokeExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeMethodReferenceExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeMethodReturnStatement* object) {
}

void CodeObjectVisitorBase::on_visit(CodeNamespace* object) {
}

void CodeObjectVisitorBase::on_visit(CodeObject* object) {
}

void CodeObjectVisitorBase::on_visit(CodeParameterDeclarationExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodePrimitiveExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeStatement* object) {
}

void CodeObjectVisitorBase::on_visit(CodeTypeDeclaration* object) {
}

void CodeObjectVisitorBase::on_visit(CodeTypeMember* object) {
}

void CodeObjectVisitorBase::on_visit(CodeTypeReference* object) {
}

void CodeObjectVisitorBase::on_visit(CodeVariableDeclarationStatement* object) {
}

void CodeObjectVisitorBase::on_visit(CodeVariableReferenceExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeAssignExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeCastExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeObjectCreateExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeIrBlockStatement* object) {
}

void CodeObjectVisitorBase::on_visit(CodeFileInclude* object) {
}

void CodeObjectVisitorBase::on_visit(CodeArrayCreateExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeArrayIndexerExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeFieldReferenceExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeAssemblyCallExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeSizeOfExpression* object) {
}

void CodeObjectVisitorBase::on_visit(CodeAttributeDeclaration* object) {
}

void CodeObjectVisitorBase::on_visit(CodeAttributeArgument* object) {
}

}
