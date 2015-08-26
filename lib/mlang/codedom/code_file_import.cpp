/* 
 * File:   code_file_include.cpp
 * Author: mario
 * 
 * Created on September 11, 2014, 9:34 AM
 */

#include "mlang.hh"

namespace mlang {
	CodeFileInclude::CodeFileInclude()
        : CodeObject()
    {
        this->m_file_name = "";
    }

    CodeFileInclude::~CodeFileInclude() {
    }
    
    bool CodeFileInclude::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeFileInclude || CodeObject::type_of(kind);
    }

    void
	CodeFileInclude::accept(ICodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
       
    void 
	CodeFileInclude::scope(CodeScope* scope) {
        CodeObject::scope(scope);
    }

    std::string
	CodeFileInclude::file_name() {
    	return this->m_file_name;
    }

    void
	CodeFileInclude::file_name(std::string value) {
    	this->m_file_name = value;
    }
}
