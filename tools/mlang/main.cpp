#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <iterator>
#include <argvparser.hh>
#include <dirent.h>

#include <linker.hh>

#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Path.h>

#include <mlang.hh>


#include <file_system.hh>
#include <easylogging++.hh>
INITIALIZE_EASYLOGGINGPP


using namespace std;
using namespace CommandLineProcessing;
using namespace mlang;


bool GeneralTextCompare(
        char * pTameText, // A string without wildcards
        char * pWildText, // A (potentially) corresponding string with wildcards
        bool bCaseSensitive = false, // By default, match on 'X' vs 'x'
        char cAltTerminator = '\0' // For function names, for example, you can stop at the first '('
) {
    bool bMatch = true;
    char * pAfterLastWild = NULL; // The location after the last '*', if we’ve encountered one
    char * pAfterLastTame = NULL; // The location in the tame string, from which we started after last wildcard
    char t, w;

    // Walk the text strings one character at a time.
    while (1) {
        t = *pTameText;
        w = *pWildText;

        // How do you match a unique text string?
        if (!t || t == cAltTerminator) {
            // Easy: unique up on it!
            if (!w || w == cAltTerminator) {
                break; // "x" matches "x"
            } else if (w == '*') {
                pWildText++;
                continue; // "x*" matches "x" or "xy"
            } else if (pAfterLastTame) {
                if (!(*pAfterLastTame) || *pAfterLastTame == cAltTerminator) {
                    bMatch = false;
                    break;
                }
                pTameText = pAfterLastTame++;
                pWildText = pAfterLastWild;
                continue;
            }

            bMatch = false;
            break; // "x" doesn't match "xy"
        } else {
            if (!bCaseSensitive) {
                // Lowercase the characters to be compared.
                if (t >= 'A' && t <= 'Z') {
                    t += ('a' - 'A');
                }

                if (w >= 'A' && w <= 'Z') {
                    w += ('a' - 'A');
                }
            }

            // How do you match a tame text string?
            if (t != w) {
                // The tame way: unique up on it!
                if (w == '*') {
                    pAfterLastWild = ++pWildText;
                    pAfterLastTame = pTameText;
                    w = *pWildText;

                    if (!w || w == cAltTerminator) {
                        break; // "*" matches "x"
                    }
                    continue; // "*y" matches "xy"
                } else if (pAfterLastWild) {
                    if (pAfterLastWild != pWildText) {
                        pWildText = pAfterLastWild;
                        w = *pWildText;

                        if (!bCaseSensitive && w >= 'A' && w <= 'Z') {
                            w += ('a' - 'A');
                        }

                        if (t == w) {
                            pWildText++;
                        }
                    }
                    pTameText++;
                    continue; // "*sip*" matches "mississippi"
                } else {
                    bMatch = false;
                    break; // "x" doesn't match "y"
                }
            }
        }

        pTameText++;
        pWildText++;
    }

    return bMatch;
}


void
parse_command_line(int argc, char ** argv, CompilerParameters* parameters) {
    LOG(DEBUG);
    ArgvParser cmd;
    // init
    cmd.setIntroductoryDescription("MLang Compiler.");
    //define error codes
    cmd.addErrorCode(0, "Success");
    cmd.addErrorCode(1, "Error");

    cmd.setHelpOption("h", "help", "Print this help page");

    cmd.defineOption("out", "Specifies the output file name (default: base name of file with main function or first file).", ArgvParser::OptionRequiresValue);
    cmd.defineOption("target", "Specifies the format of the output file by using one of four options:/target:appcontainerexe, --target=exe, --target=library.", ArgvParser::OptionRequiresValue);

    // finally parse and handle return codes (display help etc...)
    int result = cmd.parse(argc, argv);

    if (result != ArgvParser::NoParserError) {
        cout << cmd.parseErrorDescription(result);
        exit(1);
    }

    // now query the parsing results
    if (cmd.foundOption("out")) {
        parameters->output_file_name(cmd.optionValue("out"));
    }

    // should we create a library or an executable
    if (cmd.foundOption("target")) {
        cmd.optionValue("target");
    }

    // what files should we use as input
    for (int i = 0; i < cmd.arguments(); i++) {
        // todo: parse out '/' or '\' to find out if we need to search inside some directory.
        
        string argument = cmd.argument(i);
        auto searchDir =  SourceFile::get_directory(argument);
        auto searchPart = SourceFile::get_file_name(argument);
        
        char* c_argument = const_cast<char*>(searchPart.c_str());
        if (argument.find("*") || argument.find("?"))
        {
            DIR* dir;
            dirent* pdir;
            dir = opendir(searchDir.c_str()); // open current directory

            while ((pdir = readdir(dir))) {
                if (GeneralTextCompare(pdir->d_name, c_argument))
                {
                    parameters->input_files()->push_back(searchDir + "/"  +  pdir->d_name);
                    cout << pdir->d_name << endl;
                }
            }
            closedir(dir);
        }
        else
        {
            parameters->input_files()->push_back(cmd.argument(i));
        }
    }
}

int main(int argc, char ** argv) {
    START_EASYLOGGINGPP(argc, argv);
    LOG(DEBUG);

    CompilerParameters parameters;
    parse_command_line(argc, argv, &parameters);

    if (parameters.input_files()->size() == 0) {
        cerr << "mlang: error: no input files" << endl;
        exit(EXIT_FAILURE);
    }
    
    CodeCompileUnit* compile_unit = new CodeCompileUnit();

    DomProvider provider;
    int total_errors = 0;
    bool parser_success = true;


    for (string file_name : *parameters.input_files()) {
        std::cout << "parsing: " << file_name << std::endl;

        auto parser = provider.CreateParser();
        parser->parse(file_name, compile_unit);

        auto errors = parser->errors();
        total_errors = errors.size();
        parser_success &= parser->sucess();

        if (errors.size() > 0) {
            for (auto e : errors) {
                std::cerr << e->location()->to_string() << ": error: "
                        << e->message() << std::endl;
            }
        }
    }

    if (total_errors == 0 && parser_success) {
        std::cout << "Identify scopes" << std::endl;
        // I think this part should be moved into to parser part, I don't know.
        mlang::CodeScope* global_scope = new mlang::CodeScope(nullptr);
        compile_unit->scope(global_scope);

        // --

        CompilerParameters parameters;
        // parameters.optimize(optimized.getValue());
        // parameters.dump_ir(dump.getValue());
        auto compiler = provider.CreateCompiler();
        auto result = compiler->FromDomBatch(parameters, compile_unit);
        
        for (auto x : result->errors()) {
            if (x->has_location())
                std::cerr << x->location()->to_string() << ": error: " << x->message() << std::endl;
            else
                std::cerr << ": error: " << x->message() << std::endl;
        }

        if (result->errors().size() == 0) {
            std::cout << "no errors" << std::endl;
            Linker l;
            if (l.createExecutable( result->output(), "test") != 0) {
                std::cout << "create executable failed" << std::endl;
            }
        }
    } else {
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

