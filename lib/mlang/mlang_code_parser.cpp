/* 
 * File:   MLangCodeParser.cpp
 * Author: mario
 * 
 * Created on June 25, 2014, 8:18 AM
 */

#include "mlang_code_parser.hh"
#include "mlang_dom_provider.hh"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "parser/mlang_driver.hh"
//#include "parser/scanner.hh"
//#include "parser/parser.hh"

MLangCodeParser::MLangCodeParser(const MLangDomProvider& p) :
		m_provider(p) {
}

MLangCodeParser::MLangCodeParser(const MLangCodeParser& orig) :
		m_provider(orig.m_provider) {
}

MLangCodeParser::~MLangCodeParser() {
}

const MLangDomProvider&
MLangCodeParser::provider() {
	return this->m_provider;
}

std::vector<mlang::p_CompilerError>& MLangCodeParser::errors() {
	return this->m_errors;
}

bool MLangCodeParser::sucess() {
	return this->m_sucess;
}

mlang::CodeCompileUnit*
MLangCodeParser::parse(const std::string &filename, mlang::CodeCompileUnit* compile_unit) {
    std::cout << ">> parse" << std::endl;

	this->m_sucess = false;
	mlang_driver p;
        
    p.root(compile_unit);
	p.trace_parsing = true;

    std::cout << " - parse 1" << std::endl;

	this->m_sucess = p.parse_file(filename);

	if (this->m_sucess)
	{
        std::cout << " - parse 2" << std::endl;

            if (p.root()->scope() == nullptr)
            {
                std::cout << "setting root scope" << std::endl;
                p.root()->scope( new mlang::CodeScope(nullptr) );
                
            }
            else {
            std::cout << "root scope already set" << std::endl;
            }
	}

	for(auto e: p.errors()) {
		this->m_errors.push_back(e);
        std::cout << " - parse 3" << e->message() << std::endl;

    }

    std::cout << "<< parse" << std::endl;

	return p.root();
}

mlang::CodeCompileUnit*
MLangCodeParser::parse(std::istream* in) {
	this->m_sucess = false;
	mlang_driver p;
	this->m_sucess = p.parse_stream(*in, ":memory:");

	//mlang::CodeScope* global_scope = nullptr;
        if (p.root()->scope() == nullptr)
            p.root()->scope( new mlang::CodeScope(nullptr) );

	for(auto e: p.errors())
		this->m_errors.push_back(e);

	return p.root();
}

