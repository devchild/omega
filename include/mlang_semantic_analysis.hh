/*
 * mlang_semantic_analysis.hh
 *
 *  Created on: Dec 25, 2014
 *      Author: mario
 */


#ifndef MLANGSEMANTICANALYSIS_HH
#define	MLANGSEMANTICANALYSIS_HH

#include <codedom.hh>
#include <vector>

#include "compiler_error.hh"

using namespace std;
using namespace mlang;

class MLangDomProvider;

class MLangSemanticAnalysis {

public:
	MLangSemanticAnalysis(const MLangDomProvider& p);
	MLangSemanticAnalysis(const MLangSemanticAnalysis& orig);
    virtual ~MLangSemanticAnalysis();

    void analyse(CodeCompileUnit* compile_unit);
    vector<p_CompilerError>& errors();

private:
    vector<p_CompilerError> m_errors;

    const MLangDomProvider& m_provider;
};

#endif	/* MLANGSEMANTICANALYSIS_HH */

