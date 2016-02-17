#ifndef mlang_DRIVER_HH
#define mlang_DRIVER_HH
#include <string>
#include <map>
#include <mlang_parser.hh>
#include <mlang_scanner.hh>
#include <mlang.hh>
#include <compiler_error.hh>

// Conducting the whole scanning and parsing of Calc++.
class mlang_driver {
 public:
  mlang_driver(mlang::CodeCompileUnit &value);

  virtual ~mlang_driver();

  // Handling the scanner.
  bool trace_scanning;
  bool trace_parsing;

  // Error handling.
  void error(const yy::location &l, const std::string &m);

  void error(const std::string &m);

  std::vector<mlang::CompilerError *> &errors();

  bool parse_stream(std::istream &in, const std::string &sname);

  bool parse_file(const std::string &filename);

  bool parse_string(const std::string &input, const std::string &sname);

  bool include(const std::string &search_string);

  std::string *streamname();

  yy::Scanner *scanner();

  mlang::CodeCompileUnit &root();

  void root(mlang::CodeCompileUnit &value);

  bool success();

  void success(bool value);

  mlang::Location *get_location(const YYLTYPE &location);

  mlang::Location *get_location(const YYLTYPE &begin, const YYLTYPE &end);

 private:
  mlang::CodeCompileUnit &m_root;
  yy::Scanner *m_scanner;
  yy::mlang_parser *m_parser;
  std::string m_streamname;
  bool m_success;
  std::vector<mlang::CompilerError *> *m_errors;
};
#endif  // ! mlang_DRIVER_HH
