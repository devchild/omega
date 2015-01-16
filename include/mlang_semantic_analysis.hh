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


class MLangSemanticAnalysis {

public:
	MLangSemanticAnalysis();
	MLangSemanticAnalysis(const MLangSemanticAnalysis& orig);
    virtual ~MLangSemanticAnalysis();

    void analyse(CodeCompileUnit* compile_unit);

private:
    vector<p_CompilerError> m_errors;
};

#endif	/* MLANGSEMANTICANALYSIS_HH */

