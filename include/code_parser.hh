/*
 * File:   MLangCodeParser.hh
 * Author: mario
 *
 * Created on June 25, 2014, 8:18 AM
 */

#ifndef MLANGCODEPARSER_HH
#define MLANGCODEPARSER_HH

#include <vector>
#include <string>

namespace omega {

class CodeCompileUnit;
class CompilerError;
class DomProvider;

class CodeParser {
 public:
  CodeParser(const DomProvider &p);

  CodeParser(const CodeParser &orig);

  virtual ~CodeParser();

  bool sucess();

  std::vector<CompilerError *> &errors();

  omega::CodeCompileUnit &parse(const std::string &filename,
                                omega::CodeCompileUnit &compile_unit);

  const DomProvider &provider();

 private:
  std::vector<CompilerError *> m_errors;

  // indicates whether the parser could parse the complete file, this says
  // nothing about the errors
  bool m_sucess;
  const DomProvider &m_provider;
};
}

#endif /* MLANGCODEPARSER_HH */
