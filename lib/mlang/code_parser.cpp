/* 
 * File:   MLangCodeParser.cpp
 * Author: mario
 * 
 * Created on June 25, 2014, 8:18 AM
 */

#include "code_parser.hh"
#include "dom_provider.hh"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>


#include <mlang.hh>
#include "parser/mlang_driver.hh"


namespace mlang {
	CodeParser::CodeParser(const DomProvider &p) :
			m_provider(p) {
	}

	CodeParser::CodeParser(const CodeParser &orig) :
			m_provider(orig.m_provider) {
	}

	CodeParser::~CodeParser() {
	}

	const DomProvider &
	CodeParser::provider() {
		return this->m_provider;
	}

	std::vector<mlang::CompilerError*> &CodeParser::errors() {
		return this->m_errors;
	}

	bool CodeParser::sucess() {
		return this->m_sucess;
	}

	mlang::CodeCompileUnit *
	CodeParser::parse(const std::string &filename, mlang::CodeCompileUnit *compile_unit) {
		//LOG(DEBUG);
		this->m_sucess = false;
		mlang_driver p;

		p.root(compile_unit);
		// p.trace_parsing = true;

		this->m_sucess = p.parse_file(filename);

		for (auto e: p.errors()) {
			this->m_errors.push_back(e);
		}

		return p.root();
	}

	mlang::CodeCompileUnit *
	CodeParser::parse(std::istream *in) {
		//LOG(DEBUG);
		this->m_sucess = false;
		mlang_driver p;
		this->m_sucess = p.parse_stream(*in, ":memory:");

		//mlang::CodeScope* global_scope = nullptr;
		if (p.root()->scope() == nullptr)
			p.root()->scope(new mlang::CodeScope(nullptr));

		for (auto e: p.errors())
			this->m_errors.push_back(e);

		return p.root();
	}
}