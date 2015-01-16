/* 
 * File:   code_file_import.cpp
 * Author: mario
 * 
 * Created on September 11, 2014, 9:34 AM
 */

#include "codedom.hh"

namespace mlang {
    CodeFileImport::CodeFileImport()
        : CodeObject()
    {
        this->m_file_name = "";
    }

    CodeFileImport::~CodeFileImport() {
    }
    
    bool CodeFileImport::type_of(CodeObjectKind kind) {
        return kind == CodeObjectKind::CodeFileImport || CodeObject::type_of(kind);
    }

    void
	CodeFileImport::accept(CodeObjectVisitor* visitor) {
        visitor->visit(this);
    }
       
    void 
	CodeFileImport::scope(CodeScope* scope) {
        CodeObject::scope(scope);
    }

    std::string
	CodeFileImport::file_name() {
    	return this->m_file_name;
    }

    void
	CodeFileImport::file_name(std::string value) {
    	this->m_file_name = value;
    }
}
