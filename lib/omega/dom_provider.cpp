/*
 * File:   MLangDomProvider.cpp
 * Author: mario
 *
 * Created on June 23, 2014, 11:24 PM
 */

#include "omega.hh"

namespace omega {
DomProvider::DomProvider() {}

DomProvider::DomProvider(const DomProvider &orig) {}

DomProvider::~DomProvider() {}

SemanticAnalysis *DomProvider::CreateSemanticAnalysis() {
  return new SemanticAnalysis(*this);
}

CodeGenerator *DomProvider::CreateGenerator() {
  return new CodeGenerator(*this);
}

CodeCompiler *DomProvider::CreateCompiler() { return new CodeCompiler(*this); }

CodeParser *DomProvider::CreateParser() { return new CodeParser(*this); }
}
