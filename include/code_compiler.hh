/*
 * File:   MLangCodeCompiler.hh
 * Author: mario
 *
 * Created on June 24, 2014, 11:11 PM
 */

#ifndef MLANGCODECOMPILER_HH
#define MLANGCODECOMPILER_HH

#include <string>

namespace omega {
class CodeCompileUnit;
class DomProvider;
class CompilerResults;
class CompilerParameters;

class CodeCompiler {
 public:
  CodeCompiler(DomProvider &p);

  CodeCompiler(const CodeCompiler &orig);

  virtual ~CodeCompiler();

  CompilerResults *FromDomBatch(CompilerParameters &parameters,
                                omega::CodeCompileUnit &compile_unit);

  DomProvider &provider();

 private:
  void IncludeEmbeddedTypes(omega::CodeCompileUnit *compile_unit);

  DomProvider &m_provider;
};
}

#endif /* MLANGCODECOMPILER_HH */
