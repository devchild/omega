#include <mlang_code_compiler.hh>
#include <mlang_dom_provider.hh>
#include <mlang_code_parser.hh>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <iterator>
#include <argvparser.hh>
#include <dirent.h>
#include <utils.hh>
#include <file_system.hh>

#include <linker.hh>

#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Path.h>

using namespace std;
using namespace CommandLineProcessing;

void
parse_command_line(int argc, char ** argv, CompilerParameters* parameters) {
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
        auto searchDir = SourceFile::get_directory(argument);
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
    std::cout << ">> main " << std::endl;

    CompilerParameters parameters;
    parse_command_line(argc, argv, &parameters);

    if (parameters.input_files()->size() == 0) {
        cerr << "mlang: error: no input files" << endl;
        exit(EXIT_FAILURE);
    }
    
    mlang::CodeCompileUnit* compile_unit = new mlang::CodeCompileUnit();
    MLangDomProvider provider;
    int total_errors = 0;
    bool parser_success = true;

    for (string file_name : *parameters.input_files()) {
        std::cout << " - main 1 " << std::endl;

        auto parser = provider.CreateParser();
        parser->parse(file_name, compile_unit);

        auto errors = parser->errors();
        total_errors = errors.size();
        parser_success &= parser->sucess();

        if (errors.size() > 0) {
            std::cout << " - main 2 " << std::endl;

            for (auto e : errors) {
                std::cout << "errr" << std::endl;
                std::cerr << e->location()->to_string() << ": error: "
                        << e->message() << std::endl;
            }
        }
    }

    if (total_errors == 0 && parser_success) {
        std::cout << " - main 3 " << std::endl;

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
        std::cout << " - main 999 " << std::endl;

        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

