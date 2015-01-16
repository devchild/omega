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

class MLangCodeCompiler;
class MLangCodeParser;
class MLangCodeGenerator;

class MLangDomProvider {
public:
    MLangDomProvider();
    MLangDomProvider(const MLangDomProvider& orig);
    virtual ~MLangDomProvider();

    MLangCodeCompiler* CreateCompiler();
    
    MLangCodeParser* CreateParser();
    
    MLangCodeGenerator* CreateGenerator();
private:
};

#endif	/* MLANGDOMPROVIDER_HH */

