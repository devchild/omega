/* 
 * File:   MLangDomProvider.cpp
 * Author: mario
 * 
 * Created on June 23, 2014, 11:24 PM
 */

#include "mlang_code_parser.hh"
#include "mlang_code_compiler.hh"
#include "mlang_dom_provider.hh"
#include "mlang_code_generator.hh"

MLangDomProvider::MLangDomProvider() {
}

MLangDomProvider::MLangDomProvider(const MLangDomProvider& orig) {
}

MLangDomProvider::~MLangDomProvider() {
}

MLangCodeGenerator* MLangDomProvider::CreateGenerator() {
    return new MLangCodeGenerator(*this);
}

MLangCodeCompiler*  MLangDomProvider::CreateCompiler() {
    return new MLangCodeCompiler(*this);
}

MLangCodeParser* MLangDomProvider::CreateParser() {
    return new MLangCodeParser(*this);
}

