/* 
 * File:   MLangCodeParser.hh
 * Author: mario
 *
 * Created on June 25, 2014, 8:18 AM
 */

#ifndef MLANGCODEPARSER_HH
#define	MLANGCODEPARSER_HH

#include "codedom.hh"
#include "compiler_error.hh"
#include "compiler_results.hh"


class MLangDomProvider;

class MLangCodeParser {
public:
    MLangCodeParser(const MLangDomProvider& p);
    MLangCodeParser(const MLangCodeParser& orig);
    virtual ~MLangCodeParser();
    
    bool sucess();
    std::vector<mlang::p_CompilerError>& errors();
    mlang::CodeCompileUnit* parse(std::istream* in);
    mlang::CodeCompileUnit* parse(const std::string &filename);
    const MLangDomProvider& provider();
private:
    std::vector<mlang::p_CompilerError> * m_errors;

    // indicates whether the parser could parse the complete file, this says nothing about the errors
    bool m_sucess;
    const MLangDomProvider& m_provider;
};

#endif	/* MLANGCODEPARSER_HH */

