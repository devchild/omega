#ifndef omega_DRIVER_HH
#define omega_DRIVER_HH
#include <string>
#include <map>
#include <omega_parser.hh>
#include <omega_scanner.hh>
#include <omega.hh>
#include <compiler_error.hh>

// Conducting the whole scanning and parsing of Calc++.
class omega_driver {
 public:
  omega_driver(omega::CodeCompileUnit &value);

  virtual ~omega_driver();

  // Handling the scanner.
  bool trace_scanning;
  bool trace_parsing;

  // Error handling.
  void error(const yy::location &l, const std::string &m);

  void error(const std::string &m);

  std::vector<omega::CompilerError *> &errors();

  bool parse_stream(std::istream &in, const std::string &sname);

  bool parse_file(const std::string &filename);

  bool parse_string(const std::string &input, const std::string &sname);

  bool include(const std::string &search_string);

  std::string *streamname();

  yy::Scanner *scanner();

  omega::CodeCompileUnit &root();

  void root(omega::CodeCompileUnit &value);

  bool success();

  void success(bool value);

  omega::Location *get_location(const YYLTYPE &location);

  omega::Location *get_location(const YYLTYPE &begin, const YYLTYPE &end);

 private:
  omega::CodeCompileUnit &m_root;
  yy::Scanner *m_scanner;
  yy::omega_parser *m_parser;
  std::string m_streamname;
  bool m_success;
  std::vector<omega::CompilerError *> *m_errors;
};
#endif  // ! omega_DRIVER_HH
