/* 
 * File:   code_object_visitor.hh
 * Author: mario
 *
 * Created on September 15, 2014, 6:55 PM
 */

#ifndef CODE_OBJECT_VISITOR_HH
#define	CODE_OBJECT_VISITOR_HH

namespace mlang {
	class CodeObject;

	class CodeBinaryOperatorExpression;

	class CodeCompileUnit;

	class CodeConditionStatement;

	class CodeExpression;

	class CodeExpressionStatement;

	class CodeIterationStatement;

	class CodeMemberField;

	class CodeMemberMethod;

	class CodeMemberProperty;

	class CodeMethodInvokeExpression;

	class CodeMethodReferenceExpression;

	class CodeMethodReturnStatement;

	class CodeNamespace;

	class CodeParameterDeclarationExpression;

	class CodePrimitiveExpression;

	class CodeStatement;

	class CodeTypeDeclaration;

	class CodeTypeMember;

	class CodeTypeReference;

	class CodeVariableDeclarationStatement;

	class CodeVariableReferenceExpression;

	class CodeAssignExpression;

	class CodeCastExpression;

	class CodeObjectCreateExpression;

	class CodeIrBlockStatement;

	class CodeFileInclude;

	class CodeArrayCreateExpression;

	class CodeArrayIndexerExpression;

	class CodeFieldReferenceExpression;

	class CodeAssemblyCallExpression;

	class CodeSizeOfExpression;

	class CodeAttributeArgument;

	class CodeAttributeDeclaration;

	class ICodeObjectVisitor {
	public:
		virtual ~ICodeObjectVisitor();

		// forbid copying
		ICodeObjectVisitor(ICodeObjectVisitor const &) = delete;

		ICodeObjectVisitor &operator=(ICodeObjectVisitor const &) = delete;

		void visit(CodeBinaryOperatorExpression *object);

		void visit(CodeCompileUnit *object);

		void visit(CodeConditionStatement *object);

		void visit(CodeExpression *object);

		void visit(CodeExpressionStatement *object);

		void visit(CodeIterationStatement *object);

		void visit(CodeMemberField *object);

		void visit(CodeMemberMethod *object);

		void visit(CodeMemberProperty *object);

		void visit(CodeMethodInvokeExpression *object);

		void visit(CodeMethodReferenceExpression *object);

		void visit(CodeMethodReturnStatement *object);

		void visit(CodeNamespace *object);

		void visit(CodeObject *object);

		void visit(CodeParameterDeclarationExpression *object);

		void visit(CodePrimitiveExpression *object);

		void visit(CodeStatement *object);

		void visit(CodeTypeDeclaration *object);

		void visit(CodeTypeMember *object);

		void visit(CodeTypeReference *object);

		void visit(CodeVariableDeclarationStatement *object);

		void visit(CodeVariableReferenceExpression *object);

		void visit(CodeAssignExpression *object);

		void visit(CodeCastExpression *object);

		void visit(CodeObjectCreateExpression *object);

		void visit(CodeIrBlockStatement *object);

		void visit(CodeFileInclude *object);

		void visit(CodeArrayCreateExpression *object);

		void visit(CodeArrayIndexerExpression *object);

		void visit(CodeFieldReferenceExpression *object);

		void visit(CodeAssemblyCallExpression *object);

		void visit(CodeSizeOfExpression *object);

		void visit(CodeAttributeDeclaration *object);

		void visit(CodeAttributeArgument *object);

	protected:
		ICodeObjectVisitor();

		virtual void on_visit(CodeBinaryOperatorExpression *object) = 0;

		virtual void on_visit(CodeCompileUnit *object) = 0;

		virtual void on_visit(CodeConditionStatement *object) = 0;

		virtual void on_visit(CodeExpression *object) = 0;

		virtual void on_visit(CodeExpressionStatement *object) = 0;

		virtual void on_visit(CodeIterationStatement *object) = 0;

		virtual void on_visit(CodeMemberField *object) = 0;

		virtual void on_visit(CodeMemberMethod *object) = 0;

		virtual void on_visit(CodeMemberProperty *object) = 0;

		virtual void on_visit(CodeMethodInvokeExpression *object) = 0;

		virtual void on_visit(CodeMethodReferenceExpression *object) = 0;

		virtual void on_visit(CodeMethodReturnStatement *object) = 0;

		virtual void on_visit(CodeNamespace *object) = 0;

		virtual void on_visit(CodeObject *object) = 0;

		virtual void on_visit(CodeParameterDeclarationExpression *object) = 0;

		virtual void on_visit(CodePrimitiveExpression *object) = 0;

		virtual void on_visit(CodeStatement *object) = 0;

		virtual void on_visit(CodeTypeDeclaration *object) = 0;

		virtual void on_visit(CodeTypeMember *object) = 0;

		virtual void on_visit(CodeTypeReference *object) = 0;

		virtual void on_visit(CodeVariableDeclarationStatement *object) = 0;

		virtual void on_visit(CodeVariableReferenceExpression *object) = 0;

		virtual void on_visit(CodeAssignExpression *object) = 0;

		virtual void on_visit(CodeCastExpression *object) = 0;

		virtual void on_visit(CodeObjectCreateExpression *object) = 0;

		virtual void on_visit(CodeIrBlockStatement *object) = 0;

		virtual void on_visit(CodeFileInclude *object) = 0;

		virtual void on_visit(CodeArrayCreateExpression *object) = 0;

		virtual void on_visit(CodeArrayIndexerExpression *object) = 0;

		virtual void on_visit(CodeFieldReferenceExpression *object) = 0;

		virtual void on_visit(CodeAssemblyCallExpression *object) = 0;

		virtual void on_visit(CodeSizeOfExpression *object) = 0;

		virtual void on_visit(CodeAttributeDeclaration *object) = 0;

		virtual void on_visit(CodeAttributeArgument *object) = 0;
	};

	class CodeObjectVisitorBase : public ICodeObjectVisitor {
	protected:
		CodeObjectVisitorBase();

		virtual ~CodeObjectVisitorBase();

		virtual void on_visit(CodeBinaryOperatorExpression *object);

		virtual void on_visit(CodeCompileUnit *object);

		virtual void on_visit(CodeConditionStatement *object);

		virtual void on_visit(CodeExpression *object);

		virtual void on_visit(CodeExpressionStatement *object);

		virtual void on_visit(CodeIterationStatement *object);

		virtual void on_visit(CodeMemberField *object);

		virtual void on_visit(CodeMemberMethod *object);

		virtual void on_visit(CodeMemberProperty *object);

		virtual void on_visit(CodeMethodInvokeExpression *object);

		virtual void on_visit(CodeMethodReferenceExpression *object);

		virtual void on_visit(CodeMethodReturnStatement *object);

		virtual void on_visit(CodeNamespace *object);

		virtual void on_visit(CodeObject *object);

		virtual void on_visit(CodeParameterDeclarationExpression *object);

		virtual void on_visit(CodePrimitiveExpression *object);

		virtual void on_visit(CodeStatement *object);

		virtual void on_visit(CodeTypeDeclaration *object);

		virtual void on_visit(CodeTypeMember *object);

		virtual void on_visit(CodeTypeReference *object);

		virtual void on_visit(CodeVariableDeclarationStatement *object);

		virtual void on_visit(CodeVariableReferenceExpression *object);

		virtual void on_visit(CodeAssignExpression *object);

		virtual void on_visit(CodeCastExpression *object);

		virtual void on_visit(CodeObjectCreateExpression *object);

		virtual void on_visit(CodeIrBlockStatement *object);

		virtual void on_visit(CodeFileInclude *object);

		virtual void on_visit(CodeArrayCreateExpression *object);

		virtual void on_visit(CodeArrayIndexerExpression *object);

		virtual void on_visit(CodeFieldReferenceExpression *object);

		virtual void on_visit(CodeAssemblyCallExpression *object);

		virtual void on_visit(CodeSizeOfExpression *object);

		virtual void on_visit(CodeAttributeDeclaration *object);

		virtual void on_visit(CodeAttributeArgument *object);
	};

}
#endif	/* CODE_OBJECT_VISITOR_HH */

