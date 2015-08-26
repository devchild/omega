/* 
 * File:   MLangDomProvider.hh
 * Author: mario
 *
 * Created on June 23, 2014, 11:24 PM
 */

#ifndef MLANGDOMPROVIDER_HH
#define	MLANGDOMPROVIDER_HH

#include <string>
#include <vector>

namespace mlang {
    class CodeCompiler;
    class CodeParser;
    class CodeGenerator;
    class SemanticAnalysis;

    class DomProvider {
    public:
        DomProvider();

        DomProvider(const DomProvider &orig);

        virtual ~DomProvider();

        CodeCompiler *CreateCompiler();

        CodeParser *CreateParser();

        CodeGenerator *CreateGenerator();

        SemanticAnalysis *CreateSemanticAnalysis();

    private:
    };
}

#endif	/* MLANGDOMPROVIDER_HH */

