/* 
 * File:   code_member_field.hh
 * Author: mario
 *
 * Created on August 25, 2014, 10:47 PM
 */

#ifndef CODE_MEMBER_FIELD_HH
#define	CODE_MEMBER_FIELD_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

#include "code_type_member.hh"

namespace mlang {    
    class CodeMemberField : public CodeTypeMember {
    public:
        using CodeObject::scope;
        using CodeObject::resolve_type;

        CodeMemberField();
        virtual void accept(CodeObjectVisitor* visitor);
        
        void init_expression(CodeExpression* value);
        CodeExpression* init_expression();
        
        void type(CodeTypeReference* value);
        CodeTypeReference* type();
        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);
    private:
        CodeExpression * m_init_expression;
        CodeTypeReference * m_type;
    };
}

#endif	/* CODE_MEMBER_FIELD_HH */

