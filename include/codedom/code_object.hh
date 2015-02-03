/* 
 * File:   code_object.hh
 * Author: mario
 *
 * Created on August 25, 2014, 10:36 PM
 */

#ifndef CODE_OBJECT_HH
#define	CODE_OBJECT_HH

#include <string>
#include <list>
#include <map>

namespace mlang {
	class Location;
    class CodeScope;
    class CodeObjectVisitor;
    class CodeCompileUnit;    
    class CodeTypeDeclaration;
    class CodeMemberMethod;
    class CodeTypeReference;
    
	class UserDataKind {
	public:
		static const std::string LLVM_TYPE;
		static const std::string LLVM_L_VALUE;
		static const std::string LLVM_R_VALUE;
	};

    enum class CodeObjectKind {
        CodeAssignExpression,
        CodeBinaryOperatorExpression,
        CodeCompileUnit,
        CodeConditionStatement,
        CodeExpression,
        CodeExpressionStatement,
        CodeMemberField,
        CodeMemberMethod,
        CodeMemberProperty,
        CodeNamespace,
        CodeObject,
        CodeTypeDeclaration,
        CodeTypeMember,
        CodeTypeReference,
        CodeStatement,
        CodeParameterDeclarationExpression,
        CodeVariableDeclarationStatement,
        CodeVariableReferenceExpression,
        CodePrimitiveExpression,
        CodeMethodReturnStatement,
        CodeMethodInvokeExpression,
        CodeMethodReferenceExpression,
        CodeIterationStatement,
        CodeCastExpression,
		CodeObjectCreateExpression,
		CodeIrBlockStatement,
		CodeAssemblyCallExpression,
		CodeFileInclude,
		CodeArrayCreateExpression,
		CodeArrayIndexerExpression,
		CodeFieldReferenceExpression,
		CodeSizeOfExpression,
		CodeAttributeArgument,
		CodeAttributeDeclaration
    };

    class CodeObject {
    public:
        CodeObject();
        virtual ~CodeObject();
        /*
         * the parent of this code_object
         */
        CodeObject * parent();
        void parent(CodeObject * parent);
        CodeScope* scope();
        virtual std::string id();
        virtual void scope(CodeScope* scope);
        virtual bool type_of(CodeObjectKind type);
        virtual void accept(CodeObjectVisitor* visitor) = 0;
        virtual CodeCompileUnit* code_compile_unit();
        CodeTypeDeclaration* resolve_type(std::string type_name);
        CodeTypeDeclaration* resolve_type(CodeTypeReference* type_reference);
        std::list<CodeObject*>* resolve_variable(std::string variable_name);
        CodeMemberMethod* resolve_method(std::string method_name, std::list<CodeTypeDeclaration*>* parameter_types);
        CodeMemberMethod* resolve_method(std::string method_name, CodeTypeDeclaration* return_type, std::list<CodeTypeDeclaration*>* parameter_types);
        std::map<std::string, void*>& user_data();
        virtual Location* location();
        virtual void location(Location* value);
    private:
        // the parent of this code_object
        CodeObject * m_parent;
        CodeScope* m_scope;
        std::string m_id;
        Location* m_location;
        std::map<std::string, void*>* m_user_data;
    };
}

#endif	/* CODE_OBJECT_HH */

