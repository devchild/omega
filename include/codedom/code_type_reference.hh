/* 
 * File:   code_type_reference.hh
 * Author: mario
 *
 * Created on September 3, 2014, 10:37 PM
 */

#ifndef CODE_TYPE_REFERENCE_HH
#define	CODE_TYPE_REFERENCE_HH
#include <string>


namespace mlang 
{
    class CodeObject;
    class ICodeObjectVisitor;
    enum class CodeObjectKind;
    class CodeScope;
    
    class CodeTypeReference : public CodeObject {
    public:
        using CodeObject::scope;
        CodeTypeReference();
        
        /*Gets or sets the name of the type being referenced.*/
        std::string base_type();
        
        /*Gets or sets the name of the type being referenced.*/
        void base_type(std::string value);
        
        void array_element_type(CodeTypeReference* value);
        CodeTypeReference* array_element_type();

        int array_rank();
        void array_rank(int value);

        virtual void accept(ICodeObjectVisitor* visitor);
        virtual bool type_of(CodeObjectKind kind);
        virtual void scope(CodeScope* scope);
    private:
        std::string m_base_type;
        CodeTypeReference * m_array_element_type;
        int m_array_rank;
    };
}

#endif	/* CODE_TYPE_REFERENCE_HH */

