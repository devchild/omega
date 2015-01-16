#include "mlang_code_compiler.hh"
#include "mlang_dom_provider.hh"
#include "mlang_code_parser.hh"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <iterator>
#include <tclap/CmdLine.h>

using namespace std;
using namespace TCLAP;


int
main (int argc, char ** argv)
{
    CmdLine cmd("mlang", ' ', "0.01" );
    UnlabeledMultiArg<string> file_names("fileName", "file names", false, "string");
    SwitchArg optimized("O", "optimized", "compile using optimizations");
    SwitchArg dump("D", "dump-ir", "dump generated ir to stdout");
    cmd.add( file_names );
    cmd.add(optimized);
    cmd.add(dump);
    cmd.parse(argc,argv);
    
    vector<string> v = file_names.getValue();
    if (v.size() > 0)
    {
        for ( int i = 0; static_cast<unsigned int>(i) < v.size(); i++ )
        {
            std::string file_name = v[i];
            MLangDomProvider provider;
            auto parser = provider.CreateParser();
            auto compile_unit = parser->parse(file_name);
            
            auto errors = parser->errors();
                            if (errors.size() > 0)
                            {
            					for(auto e:errors)
            					{
            						std::cerr << file_name << ": " << e->location()->to_string() << ": error: " << e->message() << std::endl;
            					}
            					//exit(EXIT_FAILURE);
                            }

            if (parser->sucess())
            {


                CompilerParameters parameters;
                parameters.optimize(optimized.getValue());
                parameters.dump_ir(dump.getValue());
                auto compiler = provider.CreateCompiler();
                auto result = compiler->FromDomBatch(parameters, compile_unit);
                for(auto x:result->errors()) {
                    std::cerr << x->location()->to_string() << x->message() << std::endl;
                }
            }
            else
            {
            	std::cerr << file_name << ": (-,-): error: this is embarrassing, I could not completely parse the file." << std::endl;
            	exit(EXIT_FAILURE);
            }
        }
    }
    else
    {
        cerr << "mlang: error: no input files" << endl;
        exit(EXIT_FAILURE);
    }

    exit (EXIT_SUCCESS);
}

