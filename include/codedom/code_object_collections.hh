/* 
 * File:   code_collections.hh
 * Author: mario
 *
 * Created on September 15, 2014, 8:43 PM
 */

#ifndef CODE_COLLECTIONS_HH
#define	CODE_COLLECTIONS_HH

#include <list>

#include "code_type_reference.hh"

namespace mlang {
    class CodeObject;
    class CodeMemberMethod;
    class CodeNamespace;
    class CodeParameterDeclarationExpression;
    class CodeTypeDeclaration;
    class CodeTypeMember;
    class CodeStatement;
    class CodeExpression;
    class CodeAttributeArgument;
    class CodeAttributeDeclaration;
    
    typedef std::list<CodeMemberMethod*> CodeMemberMethodCollection;
    typedef std::list<CodeExpression*> CodeExpressionCollection;
    typedef std::list<CodeTypeReference*> CodeTypeReferenceCollection;
    typedef std::list<CodeNamespace*> CodeNamespaceCollection;
    typedef std::list<CodeParameterDeclarationExpression*> CodeParameterDeclarationExpressionCollection;
    typedef std::list<CodeTypeDeclaration*> CodeTypeDeclarationCollection;
    typedef std::list<CodeTypeMember*> CodeTypeMemberCollection;
    typedef std::list<CodeStatement*> CodeStatementCollection;
    typedef std::list<CodeObject*> CodeObjectCollection;
    typedef std::list<CodeAttributeArgument*> CodeAttributeArgumentCollection;
    typedef std::list<CodeAttributeDeclaration*> CodeAttributeDeclarationCollection;
}


#endif	/* CODE_COLLECTIONS_HH */

