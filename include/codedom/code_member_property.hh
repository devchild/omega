/*
 * File:   code_member_property.hh
 * Author: mario
 *
 * Created on August 25, 2014, 10:50 PM
 */

#ifndef CODE_MEMBER_PROPERTY_HH
#define CODE_MEMBER_PROPERTY_HH

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace mlang {
class CodeTypeMember;
class CodeMemberProperty : public CodeTypeMember {
 public:
  using CodeObject::scope;
  CodeMemberProperty();
  ~CodeMemberProperty();
  virtual void accept(ICodeObjectVisitor* visitor);
  virtual bool type_of(CodeObjectKind kind);
  virtual void scope(CodeScope* scope);

  CodeStatementCollection& get_statements();
  CodeStatementCollection& set_statements();

 private:
  CodeStatementCollection m_get_statements;
  CodeStatementCollection m_set_statements;
};
}

#endif /* CODE_MEMBER_PROPERTY_HH */
