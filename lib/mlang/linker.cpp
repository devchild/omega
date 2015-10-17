#include <linker.hh>
#include <string>
#include <vector>
#include <iostream>
#include <llvm/Support/Program.h>
#include <llvm/Support/ErrorOr.h>

int
Linker::execute(const std::string &tool, std::vector<std::string> const &args, bool verbose) {
    // Construct real argument list.
    // First entry is the tool itself, last entry must be NULL.
    std::vector<const char *> realargs;
    realargs.reserve(args.size() + 2);
    realargs.push_back(tool.c_str());
    for (std::vector<std::string>::const_iterator it = args.begin(); it != args.end(); ++it)
    {
        realargs.push_back((*it).c_str());
    }
    realargs.push_back(NULL);

    // Print command line if requested
    if (verbose)
    {
        // Print it
        for (size_t i = 0; i < realargs.size()-1; i++)
            std::cout << realargs[i] << " ";
    }

    // Execute tool.
    std::string errstr;
    if (int status = llvm::sys::ExecuteAndWait(tool, &realargs[0], NULL, NULL, 0, 0, &errstr))
    {
        /*
        error(Loc(), "%s failed with status: %d", tool.c_str(), status);
        if (!errstr.empty())
            error(Loc(), "message: %s", errstr.c_str());
        */
        return status;
    }
    return 0;
}

int
Linker::createExecutable(std::vector<std::string>& fileNames, std::string output) {
    llvm::ErrorOr<std::string> tool = llvm::sys::findProgramByName("ld");

    std::vector<std::string> args;


    args.push_back("-demangle");
    args.push_back("-dynamic");
    args.push_back("-arch"); args.push_back("x86_64");
    args.push_back("-macosx_version_min"); args.push_back("10.10.0");
    args.push_back("-syslibroot"); args.push_back("/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk");

    args.push_back("-o");args.push_back(output);

    for(auto fileName: fileNames)
    {
        args.push_back(fileName);
    }

    args.push_back("-lm"); 
    args.push_back("-lSystem");
    args.push_back("/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../lib/clang/6.1.0/lib/darwin/libclang_rt.osx.a");

    std::cout << "executing tool" << std::endl;

    std::cout << tool.getError().message() << std::endl;
    return execute(tool.get(), args, true); 
}
