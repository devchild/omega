/*
 * mlang_semantic_analysis.hh
 *
 *  Created on: Dec 25, 2014
 *      Author: mario
 */


#ifndef MLANGSEMANTICANALYSIS_HH
#define	MLANGSEMANTICANALYSIS_HH

#include <vector>

#include "compiler_error.hh"

using namespace std;

namespace mlang {

    class DomProvider;

    class CompilerError;

    class CodeCompileUnit;

    class SemanticAnalysis {

    public:
        SemanticAnalysis(const DomProvider &p);

        SemanticAnalysis(const SemanticAnalysis &orig);

        virtual ~SemanticAnalysis();

        void analyse(CodeCompileUnit *compile_unit);

        vector<CompilerError*> &errors();

    private:
        vector<CompilerError *> m_errors;

        const DomProvider &m_provider;
    };
}

#endif	/* MLANGSEMANTICANALYSIS_HH */

