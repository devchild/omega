/*
 * File:   code_file_import.hh
 * Author: mario
 *
 * Created on September 3, 2014, 11:12 PM
 */

#ifndef CODE_FILE_IMPORT_HH
#define	CODE_FILE_IMPORT_HH

#include <string>

#include "code_object.hh"
#include "code_object_collections.hh"
#include "code_object_visitor.hh"

namespace mlang {
    class CodeFileImport : public CodeObject {
    public:
        using CodeObject::scope;
        CodeFileImport();
        ~CodeFileImport();
        virtual void accept(CodeObjectVisitor* visitor);
        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);

        std::string file_name();
        void file_name(std::string value);
    private:
        std::string m_file_name;
    };
}


#endif	/* CODE_FILE_IMPORT_HH */

