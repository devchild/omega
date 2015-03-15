/* 
 * File:   MLangCodeCompiler.hh
 * Author: mario
 *
 * Created on June 24, 2014, 11:11 PM
 */

#ifndef MLANGCODECOMPILER_HH
#define	MLANGCODECOMPILER_HH

#include <string>

#include "compiler_results.hh"
#include "compiler_parameters.hh"
#include "mlang_dom_provider.hh"
#include "codedom.hh"

class MLangCodeCompiler {
public:
    MLangCodeCompiler(MLangDomProvider& p);
    MLangCodeCompiler(const MLangCodeCompiler& orig);
    virtual ~MLangCodeCompiler();
    CompilerResults* FromDomBatch(CompilerParameters options, mlang::CodeCompileUnit* compile_unit);
    
    MLangDomProvider &provider();
private:
    void IncludeEmbeddedTypes(mlang::CodeCompileUnit* compile_unit);
    MLangDomProvider &m_provider;
};

#endif	/* MLANGCODECOMPILER_HH */

