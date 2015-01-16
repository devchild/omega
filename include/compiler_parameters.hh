/* 
 * File:   CompilerParameters.hh
 * Author: mario
 *
 * Created on June 23, 2014, 10:52 PM
 */

#ifndef COMPILERPARAMETERS_HH
#define	COMPILERPARAMETERS_HH

class CompilerParameters {
public:
    CompilerParameters();
    CompilerParameters(const CompilerParameters& orig);
    virtual ~CompilerParameters();
    
    void generate_executable(bool value);
    bool generate_executable();
    
    void optimize(bool value);
    bool optimize();

    void dump_ir(bool value);
    bool dump_ir();
private:
    bool m_generate_executable;
    bool m_optimize;
    bool m_dump_ir;
};

#endif	/* COMPILERPARAMETERS_HH */

