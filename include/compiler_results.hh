/*
 * File:   CompilerResults.hh
 * Author: mario
 *
 * Created on June 23, 2014, 11:09 PM
 */

#ifndef COMPILERRESULTS_HH
#define COMPILERRESULTS_HH

#include <vector>
#include <string>

using namespace std;

namespace mlang {
class CompilerError;

class CompilerResults {
 public:
  CompilerResults();

  CompilerResults(const CompilerResults &orig);

  virtual ~CompilerResults();

  vector<CompilerError *> &errors();

  vector<std::string> &output();

 private:
  vector<CompilerError *> m_errors;
  vector<std::string> m_output;
  // CompiledAssembly -> ?
  // Errors   -> ErrorCollectiong
  // NativeCompilerReturnValue -> int
  // Output --> StringCollection
  // PathToAssembly --> string
};
}

#endif /* COMPILERRESULTS_HH */
