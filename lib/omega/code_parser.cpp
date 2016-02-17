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

#include <omega.hh>
#include "parser/omega_driver.hh"

namespace omega {
CodeParser::CodeParser(const DomProvider &p) : m_provider(p) {}

CodeParser::CodeParser(const CodeParser &orig) : m_provider(orig.m_provider) {}

CodeParser::~CodeParser() {}

const DomProvider &CodeParser::provider() { return this->m_provider; }

std::vector<omega::CompilerError *> &CodeParser::errors() {
  return this->m_errors;
}

bool CodeParser::sucess() { return this->m_sucess; }

omega::CodeCompileUnit &CodeParser::parse(
    const std::string &filename, omega::CodeCompileUnit &compile_unit) {
  // LOG(DEBUG);
  this->m_sucess = false;
  omega_driver p(compile_unit);
  // p.trace_parsing = true;

  this->m_sucess = p.parse_file(filename);

  for (auto e : p.errors()) {
    this->m_errors.push_back(e);
  }

  return p.root();
}
}
