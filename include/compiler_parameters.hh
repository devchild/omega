/*
 * File:   CompilerParameters.hh
 * Author: mario
 *
 * Created on June 23, 2014, 10:52 PM
 */

#ifndef COMPILERPARAMETERS_HH
#define COMPILERPARAMETERS_HH
#include <iostream>
#include <string>
#include <list>

using namespace std;

namespace omega {
class CompilerParameters {
 public:
  CompilerParameters();

  CompilerParameters(const CompilerParameters &orig);

  virtual ~CompilerParameters();

  void generate_executable(bool value);

  bool generate_executable();

  void optimize(bool value);

  bool optimize();

  void dump_ir(bool value);

  bool dump_ir();

  void output_file_name(string file_name);

  string output_file_name();

  list<string> *input_files();

 private:
  bool m_generate_executable;
  bool m_optimize;
  bool m_dump_ir;
  string m_output_file_name;
  list<string> *m_input_files;
};
}
#endif /* COMPILERPARAMETERS_HH */
