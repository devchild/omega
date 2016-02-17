/*
 * File:   CompilerResults.cpp
 * Author: mario
 *
 * Created on June 23, 2014, 11:09 PM
 */

#include "compiler_results.hh"

namespace omega {
CompilerResults::CompilerResults() {}

CompilerResults::CompilerResults(const CompilerResults &orig) {}

CompilerResults::~CompilerResults() {}

vector<omega::CompilerError *> &CompilerResults::errors() {
  return this->m_errors;
}

vector<std::string> &CompilerResults::output() { return this->m_output; }
}
