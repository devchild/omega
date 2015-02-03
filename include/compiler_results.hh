/* 
 * File:   CompilerResults.hh
 * Author: mario
 *
 * Created on June 23, 2014, 11:09 PM
 */

#ifndef COMPILERRESULTS_HH
#define	COMPILERRESULTS_HH

#include <vector>
#include "compiler_error.hh"

using namespace std;

class CompilerResults {
public:
    CompilerResults();
    CompilerResults(const CompilerResults& orig);
    virtual ~CompilerResults();
    vector<mlang::p_CompilerError>& errors();
    
private:
    vector<mlang::p_CompilerError> m_errors;
    // CompiledAssembly -> ?
    // Errors   -> ErrorCollectiong
    // NativeCompilerReturnValue -> int
    // Output --> StringCollection
    // PathToAssembly --> string
};

#endif	/* COMPILERRESULTS_HH */

