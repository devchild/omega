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
    class CodeFileImport;
    class CodeArrayCreateExpression;
    class CodeArrayIndexerExpression;
    class CodeFieldReferenceExpression;
    class CodeAssemblyCallExpression;

class CodeObjectVisitor {
    public:
    	virtual ~CodeObjectVisitor() {}
        virtual void visit(CodeBinaryOperatorExpression* object) = 0;
        virtual void visit(CodeCompileUnit* object) = 0;
        virtual void visit(CodeConditionStatement* object) = 0;
        virtual void visit(CodeExpression* object) = 0;
        virtual void visit(CodeExpressionStatement* object) = 0;
        virtual void visit(CodeIterationStatement* object) = 0;
        virtual void visit(CodeMemberField* object) = 0;
        virtual void visit(CodeMemberMethod* object) = 0;
        virtual void visit(CodeMemberProperty* object) = 0;
        virtual void visit(CodeMethodInvokeExpression* object) = 0;
        virtual void visit(CodeMethodReferenceExpression* object) = 0;
        virtual void visit(CodeMethodReturnStatement* object) = 0;
        virtual void visit(CodeNamespace* object) = 0;
        virtual void visit(CodeObject* object) = 0;
        virtual void visit(CodeParameterDeclarationExpression* object) = 0;
        virtual void visit(CodePrimitiveExpression* object) = 0;
        virtual void visit(CodeStatement* object) = 0;
        virtual void visit(CodeTypeDeclaration* object) = 0;
        virtual void visit(CodeTypeMember* object) = 0;
        virtual void visit(CodeTypeReference* object) = 0;
        virtual void visit(CodeVariableDeclarationStatement* object) = 0;
        virtual void visit(CodeVariableReferenceExpression* object) = 0;
        virtual void visit(CodeAssignExpression* object) = 0;
        virtual void visit(CodeCastExpression* object) = 0;
        virtual void visit(CodeObjectCreateExpression* object) = 0;
        virtual void visit(CodeIrBlockStatement* object) = 0;
        virtual void visit(CodeFileImport* object) = 0;
        virtual void visit(CodeArrayCreateExpression* object) = 0;
        virtual void visit(CodeArrayIndexerExpression* object) = 0;
        virtual void visit(CodeFieldReferenceExpression* object) = 0;
        virtual void visit(CodeAssemblyCallExpression* object) = 0;
    };
}
#endif	/* CODE_OBJECT_VISITOR_HH */

