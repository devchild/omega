#include <fstream>
#include <sstream>

#include "omega_driver.hh"
#include "omega_parser.hh"
#include "omega_scanner.hh"
#include <pstream.hh>
#include <file_system.hh>

omega_driver::omega_driver(omega::CodeCompileUnit &root)
    : trace_scanning(false), trace_parsing(false), m_root(root) {
  m_errors = new std::vector<omega::CompilerError *>();
  m_streamname = "";
  m_success = false;
  m_scanner = nullptr;
  m_parser = nullptr;
}

omega_driver::~omega_driver() {}

bool omega_driver::parse_stream(std::istream &in, const std::string &sname) {
  // why was this set to nill?
  // this->m_root = nullptr;
  m_streamname = sname;

  yy::Scanner scanner(&in, &std::cout);
  scanner.set_debug(trace_scanning);
  this->m_scanner = &scanner;

  yy::omega_parser parser(*this);
  parser.set_debug_level(trace_parsing);
  return (parser.parse() == 0);
}

bool omega_driver::parse_file(const std::string &filename) {
  std::ifstream in(filename.c_str());
  if (!in.good()) {
    std::cout << filename << " does not exist." << std::endl;
    return false;
  }
  return parse_stream(in, filename);
}

bool omega_driver::include(const std::string &import_statement) {
  bool ret = true;
  SourceFile sf(this->m_streamname);

  for (auto file : sf.import(import_statement)) {
    ret &= parse_file(file);
  }

  return ret;

  /*
std::ifstream in(filename.c_str());
if (!in.good()) return false;
return parse_stream(in, filename);
*/
}

std::string *omega_driver::streamname() { return &this->m_streamname; }

yy::Scanner *omega_driver::scanner() { return this->m_scanner; }

omega::CodeCompileUnit &omega_driver::root() { return this->m_root; }

void omega_driver::root(omega::CodeCompileUnit &value) { this->m_root = value; }

bool omega_driver::success() { return this->m_success; }

void omega_driver::success(bool value) { this->m_success = value; }

bool omega_driver::parse_string(const std::string &input,
                                const std::string &sname) {
  std::istringstream iss(input);
  return parse_stream(iss, sname);
}

omega::Location *omega_driver::get_location(const YYLTYPE &l) {
  omega::Location *loc = new omega::Location();
  loc->file_name(this->m_streamname);
  loc->first_column(l.begin.column);
  loc->last_column(l.end.column);
  loc->first_line(l.begin.line);
  loc->last_line(l.end.line);
  return loc;
}

omega::Location *omega_driver::get_location(const YYLTYPE &begin,
                                            const YYLTYPE &end) {
  omega::Location *loc = new omega::Location();
  loc->file_name(this->m_streamname);
  loc->first_column(begin.begin.column);
  loc->last_column(end.end.column);
  loc->first_line(begin.begin.line);
  loc->last_line(end.end.line);
  return loc;
}

void omega_driver::error(const yy::location &l, const std::string &m) {
  /*
int i = 0;
std::cout << "...... !";
for (i=1; i<l.begin.column; i++)
std::cout << ".";
for (i=l.begin.column; i<=l.end.column -1; i++)
std::cout << "^";
for (i=l.end.column+1; i<m.size(); i++)
std::cout << ".";
std::cout << std::endl;
std::cout << "Error: "<< m << std::endl << std::endl;
*/
  omega::CompilerError *error = new omega::CompilerError();
  error->message(m);

  omega::Location *loc = new omega::Location();
  loc->file_name(this->m_streamname);
  loc->first_column(l.begin.column);
  loc->last_column(l.end.column);
  loc->first_line(l.begin.line);
  loc->last_line(l.end.line);
  error->location(loc);

  m_errors->push_back(error);
}

std::vector<omega::CompilerError *> &omega_driver::errors() {
  return *this->m_errors;
}

void omega_driver::error(const std::string &m) { std::cerr << m << std::endl; }
