/*
 * File:   CompilerError.cpp
 * Author: mario
 *
 * Created on June 23, 2014, 10:55 PM
 */

#include "compiler_error.hh"
namespace mlang {
CompilerError::CompilerError() { this->m_has_location = false; }

CompilerError::CompilerError(const CompilerError& orig) {}

CompilerError::~CompilerError() {}

void CompilerError::message(std::string message) { this->m_message = message; }

std::string CompilerError::message() { return this->m_message; }

void CompilerError::location(Location* location) {
  this->m_location = location;
  this->m_has_location = this->m_location != nullptr;
}

Location* CompilerError::location() { return this->m_location; }

bool CompilerError::has_location() { return this->m_has_location; }
}
