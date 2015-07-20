# include <fstream>
# include <sstream>

# include "mlang_driver.hh"
# include "mlang_parser.hh"
# include "mlang_scanner.hh"
# include <pstream.hh>
# include <file_system.hh>

mlang_driver::mlang_driver() :
		trace_scanning(false), trace_parsing(false) {
	m_errors = new std::vector<mlang::p_CompilerError>();
	m_streamname = "";
	m_root = nullptr;
	m_success = false;
	m_scanner = nullptr;
	m_parser = nullptr;
}

mlang_driver::~mlang_driver() {
}

bool mlang_driver::parse_stream(std::istream& in, const std::string& sname) {
	// why was this set to nill?
        // this->m_root = nullptr;
	m_streamname = sname;

	yy::Scanner scanner(&in, &std::cout);
	scanner.set_debug(trace_scanning);
	this->m_scanner = &scanner;

	yy::mlang_parser parser(*this);
	parser.set_debug_level(trace_parsing);
	return (parser.parse() == 0);
}

bool mlang_driver::parse_file(const std::string &filename) {
	std::ifstream in(filename.c_str());
	if (!in.good())
		return false;
	return parse_stream(in, filename);
}

bool mlang_driver::include(const std::string &import_statement) {
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

std::string*
mlang_driver::streamname() {
	return &this->m_streamname;
}

yy::Scanner*
mlang_driver::scanner() {
	return this->m_scanner;
}

mlang::CodeCompileUnit*
mlang_driver::root() {
	return this->m_root;
}

void mlang_driver::root(mlang::CodeCompileUnit* value) {
	this->m_root = value;
}

bool mlang_driver::success() {
	return this->m_success;
}

void mlang_driver::success(bool value) {
	this->m_success = value;
}

bool mlang_driver::parse_string(const std::string &input,
		const std::string& sname) {
	std::istringstream iss(input);
	return parse_stream(iss, sname);
}

mlang::Location* mlang_driver::get_location(const YYLTYPE& l) {
	mlang::Location * loc = new mlang::Location();
	loc->file_name(this->m_streamname);
	loc->first_column(l.begin.column);
	loc->last_column(l.end.column);
	loc->first_line(l.begin.line);
	loc->last_line(l.end.line);
	return loc;
}

mlang::Location* mlang_driver::get_location(const YYLTYPE& begin, const YYLTYPE& end) {
	mlang::Location * loc = new mlang::Location();
	loc->file_name(this->m_streamname);
	loc->first_column(begin.begin.column);
	loc->last_column(end.end.column);
	loc->first_line(begin.begin.line);
	loc->last_line(end.end.line);
	return loc;
}

void mlang_driver::error(const yy::location& l, const std::string& m) {
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
	mlang::CompilerError * error = new mlang::CompilerError();
	error->message(m);

	mlang::Location * loc = new mlang::Location();
	loc->file_name(this->m_streamname);
	loc->first_column(l.begin.column);
	loc->last_column(l.end.column);
	loc->first_line(l.begin.line);
	loc->last_line(l.end.line);
	error->location(loc);

	m_errors->push_back(error);
}

std::vector<mlang::p_CompilerError>&
mlang_driver::errors() {
	return *this->m_errors;
}

void mlang_driver::error(const std::string& m) {
	std::cerr << m << std::endl;
}
