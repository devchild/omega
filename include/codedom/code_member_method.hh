/* 
 * File:   code_member_method.hh
 * Author: mario
 *
 * Created on August 25, 2014, 10:48 PM
 */

#ifndef CODE_MEMBER_METHOD_HH
#define	CODE_MEMBER_METHOD_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

#include "code_type_member.hh"

namespace mlang {
    
    class CodeNamespace;
    class CodeTypeReference;
    
    enum class MemberAttributes {
    	Public,
		Private,
		External
    };

    class CodeMemberMethod : public CodeTypeMember {
    public:
        using CodeObject::scope;
        using CodeObject::id;
        CodeMemberMethod();
        virtual ~CodeMemberMethod();
        
        void return_type(CodeTypeReference* return_type);
        CodeTypeReference* return_type();
        CodeStatementCollection* statements();
        CodeParameterDeclarationExpressionCollection* parameters();
        void attributes(MemberAttributes value);
        MemberAttributes attributes();

        virtual void accept(ICodeObjectVisitor* visitor);
        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);
        virtual std::string id();

    private:
        MemberAttributes m_attributes;
        CodeTypeReference * m_return_type;
        CodeStatementCollection * m_statements;
        CodeParameterDeclarationExpressionCollection * m_parameters;
    };
}

#endif	/* CODE_MEMBER_METHOD_HH */

