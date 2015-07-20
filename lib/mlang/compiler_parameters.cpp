/* 
 * File:   CompilerParameters.cpp
 * Author: mario
 * 
 * Created on June 23, 2014, 10:52 PM
 */

#include "compiler_parameters.hh"
#include <iostream>
#include <string>

using namespace std;

CompilerParameters::CompilerParameters() {
    this->m_optimize = true;
    this->m_generate_executable = true;
    this->m_dump_ir = false;
    this->m_input_files = new list<string>();
}

CompilerParameters::CompilerParameters(const CompilerParameters& orig) {
    this->m_optimize = orig.m_optimize;
    this->m_generate_executable = orig.m_generate_executable;
    this->m_dump_ir = orig.m_dump_ir;
}

CompilerParameters::~CompilerParameters() {  
}

void 
CompilerParameters::generate_executable(bool value) {
    this->m_generate_executable = value;
}

bool 
CompilerParameters::generate_executable() {
    return this->m_generate_executable;
}

void 
CompilerParameters::optimize(bool value) {
    this->m_optimize = value;
}

bool 
CompilerParameters::optimize() {
    return this->m_optimize;
}

void
CompilerParameters::dump_ir(bool value) {
	this->m_dump_ir = value;
}

bool CompilerParameters::dump_ir() {
	return this->m_dump_ir;
}

void CompilerParameters::output_file_name(string file_name) {
    this->m_output_file_name = file_name;
}
    
string CompilerParameters::output_file_name() {
    return this->m_output_file_name;
}

list<string>* CompilerParameters::input_files() {
    return this->m_input_files;
}

void CompilerParameters::append_input_file(std::string file_name) {
    this->m_input_files->push_back(file_name);
}
