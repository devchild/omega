/* 
 * File:   CompilerResults.cpp
 * Author: mario
 * 
 * Created on June 23, 2014, 11:09 PM
 */

#include "compiler_results.hh"

namespace mlang {
    CompilerResults::CompilerResults() {
    }

    CompilerResults::CompilerResults(const CompilerResults &orig) {
    }

    CompilerResults::~CompilerResults() {
    }

    vector<mlang::CompilerError*> &CompilerResults::errors() {
        return this->m_errors;
    }

    vector<std::string> &CompilerResults::output() {
        return this->m_output;
    }
}


