#include <codedom.hh>
#include <cstdlib>

namespace mlang {

    CodeScope::CodeScope(CodeScope* parent) {
        this->scope_ended = false;
        this->m_parent = parent;
        this->m_members = new std::list<CodeObject*>();
    }

    CodeScope::~CodeScope() {

    }

    std::list<CodeObject*>*
    CodeScope::members() {
        return this->m_members;
    }
    
    CodeScope*
    CodeScope::parent() {
        return this->m_parent;
    }

    void
    CodeScope::push_back(CodeObject* object) {
        if (scope_ended)
            exit(EXIT_FAILURE);
        this->m_members->push_back(object);
    }

    CodeScope*
    CodeScope::begin_scope() {
        CodeScope * ret = new CodeScope(this);
        return ret;
    }

    CodeScope*
    CodeScope::end_scope() {
        this->scope_ended = true;
        return this->m_parent;
    }
}


