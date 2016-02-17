/*
 * File:   code_scope.hh
 * Author: mario
 *
 * Created on October 3, 2014, 9:06 AM
 */

#ifndef CODE_SCOPE_HH
#define CODE_SCOPE_HH

#include <list>
#include <string>

namespace omega {
class CodeObject;

class CodeScope {
 public:
  ~CodeScope();
  explicit CodeScope(CodeScope* parent);

  std::list<CodeObject*>* members();
  CodeScope* parent();
  CodeScope* begin_scope();
  CodeScope* end_scope();
  void push_back(CodeObject* object);

 private:
  std::list<CodeObject*>* m_members;
  CodeScope* m_parent;
  bool scope_ended;
};
}

#endif /* CODE_SCOPE_HH */
