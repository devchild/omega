/*
 * File:   code_object.hh
 * Author: mario
 *
 * Created on August 25, 2014, 10:36 PM
 */

#ifndef CODE_OBJECT_HH
#define CODE_OBJECT_HH

#include <string>
#include <list>
#include <map>

namespace omega {
class Location;
class CodeScope;
class ICodeObjectVisitor;
class CodeCompileUnit;
class CodeTypeDeclaration;
class CodeMemberMethod;
class CodeTypeReference;

class UserDataKind {
 public:
  static const std::string MLANG_INFERRED_TYPE_REFERENCE;
  static const std::string MLANG_INFERRED_METHOD_REFERENCE;

  static const std::string MLANG_RESOLVED_TYPE;
  static const std::string MLANG_RESOLVED_VARIABLE;
  static const std::string MLANG_RESOLVED_METHOD;

  static const std::string MLANG_RESOLVED_MEMBER_FIELD;
  static const std::string MLANG_RESOLVED_VARIABLE_DECLARATION_STATEMENT;
  static const std::string MLANG_RESOLVED_PARAMETER_DECLARATION_EXPRESSION;
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
  CodeObject* parent();
  void parent(CodeObject* parent);
  CodeScope* scope();
  virtual std::string id();
  virtual void scope(CodeScope* scope);
  virtual bool type_of(CodeObjectKind type);
  virtual void accept(ICodeObjectVisitor* visitor) = 0;
  virtual CodeCompileUnit* code_compile_unit();

  void* user_data(std::string key);
  void user_data(std::string key, void* value);

  virtual Location* location();
  virtual void location(Location* value);

 private:
  // the parent of this code_object
  CodeObject* m_parent;
  CodeScope* m_scope;
  std::string m_id;
  Location* m_location;
  std::map<std::string, void*> m_user_data;
};
}

#endif /* CODE_OBJECT_HH */
