/*
 * File:   MLangCodeCompiler.cpp
 * Author: mario
 *
 * Created on June 24, 2014, 11:11 PM
 */

#include <string>
#include <vector>

#include <iostream>
#include <cstring>
#include <string>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Support/raw_ostream.h>

#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/Verifier.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/LinkAllPasses.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ADT/Triple.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/Registry.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/FormattedStream.h>

#include <omega.hh>

#include <easylogging++.hh>
INITIALIZE_EASYLOGGINGPP

namespace omega {
CodeCompiler::CodeCompiler(DomProvider &p) : m_provider(p) {}

CodeCompiler::CodeCompiler(const CodeCompiler &orig)
    : m_provider(orig.m_provider) {}

CodeCompiler::~CodeCompiler() {}

DomProvider &CodeCompiler::provider() { return this->m_provider; }

void runLLVMOptimizations1(llvm::Module *module) {
  LOG(TRACE);

  // Set up the function-level optimizations we want
  llvm::legacy::FunctionPassManager passManager(module);
  passManager.add(llvm::createVerifierPass());
  passManager.add(llvm::createPromoteMemoryToRegisterPass());
  passManager.add(llvm::createReassociatePass());
  passManager.add(llvm::createGVNPass());
  // passManager.add(llvm::createCoalesceInsertsPass());
  passManager.add(llvm::createAggressiveDCEPass());

  passManager.add(llvm::createFlattenCFGPass());
  passManager.add(llvm::createInstructionCombiningPass());
  // passManager.add(llvm::createPartiallyInlineLibCallsPass());
  passManager.add(llvm::createVerifierPass());
  llvm::Module::iterator function, lastFunction;

  // run them across all functions
  passManager.doInitialization();
  for (function = module->begin(), lastFunction = module->end();
       function != lastFunction; ++function) {
    passManager.run(*function);
  }
  passManager.doFinalization();

  // Set up the module-level optimizations we want
  llvm::legacy::PassManager modulePassManager;
  modulePassManager.add(llvm::createAlwaysInlinerPass());
  modulePassManager.add(llvm::createGlobalOptimizerPass());

  // Optimize the whole module
  bool changed = modulePassManager.run(*module);

  if (changed) {
    // removing globals created stack allocations we want to eliminate
    llvm::legacy::FunctionPassManager postGlobalManager(module);
    postGlobalManager.add(llvm::createPromoteMemoryToRegisterPass());

    // run across all functions
    postGlobalManager.doInitialization();
    for (function = module->begin(), lastFunction = module->end();
         function != lastFunction; ++function) {
      postGlobalManager.run(*function);
    }
    postGlobalManager.doFinalization();
  }

  //    if (! backEnd->preferRegistersOverMemory()) {
  //        llvm::FunctionPassManager memoryPassManager(module);
  //        memoryPassManager.add(llvm::createDemoteRegisterToMemoryPass());
  //
  //        memoryPassManager.doInitialization();
  //        for (function = module->begin(), lastFunction = module->end();
  //        function != lastFunction; ++function) {
  //            memoryPassManager.run(*function);
  //        }
  //        memoryPassManager.doFinalization();
  //    }
}

/*	static int generateobj(std::shared_ptr<llvm::tool_output_file> Out,
   llvm::Module * module)
        {
                llvm::legacy::PassManager PM;

                llvm::TargetOptions Options;

                std::string Err;

                llvm::Triple TheTriple(module->getTargetTriple());
                if (TheTriple.getTriple().empty())
                        TheTriple.setTriple(llvm::sys::getDefaultTargetTriple());

                const llvm::Target* TheTarget =
   llvm::TargetRegistry::lookupTarget(TheTriple.getTriple(), Err);

                std::string MCPU,FeaturesStr;

                llvm::TargetMachine * machineTarget =
                                TheTarget->createTargetMachine(TheTriple.getTriple(),
   MCPU, FeaturesStr, Options);

                // Figure out where we are going to send the output...

                if (machineTarget->addPassesToEmitFile(PM, Out->os(),
   llvm::TargetMachine::CGFT_ObjectFile))
                {
                        std::cerr << " target does not support generation of
   this"     << " file type!\n";
                        return 1;
                }

                PM.run(*module);
                return 0;
        }*/

static int generateobj(llvm::raw_fd_ostream &out, llvm::Module *module) {
  LOG(TRACE);

  llvm::legacy::PassManager PM;
  llvm::TargetOptions Options;
  std::string Err;

  llvm::Triple TheTriple(module->getTargetTriple());
  if (TheTriple.getTriple().empty())
    TheTriple.setTriple("x86_64-apple-macosx");

  const llvm::Target *TheTarget =
      llvm::TargetRegistry::lookupTarget(TheTriple.getTriple(), Err);

  std::string MCPU, FeaturesStr;
  llvm::TargetMachine *machineTarget = TheTarget->createTargetMachine(
      TheTriple.getTriple(), MCPU, FeaturesStr, Options);

      module->setDataLayout( machineTarget->createDataLayout() );
  // Figure out where we are going to send the output...
  // llvm::raw_fd_ostream FOS(out);
  if (machineTarget->addPassesToEmitFile(
          PM, out, llvm::TargetMachine::CGFT_ObjectFile)) {
    std::cerr << " target does not support generation of this file type!\n";
    return 1;
  }
  PM.run(*module);
  return 0;
}

void CodeCompiler::IncludeEmbeddedTypes(omega::CodeCompileUnit *compile_unit) {
  LOG(TRACE);
  //
  // create embedded types
  //
  auto _int1 = new CodeTypeDeclaration();
  _int1->name("Int1");
  _int1->is_struct(true);
  _int1->is_embedded(true);
  compile_unit->types()->push_back(_int1);
  _int1->parent(compile_unit);
  _int1->scope(compile_unit->scope());

  auto _bool = new CodeTypeDeclaration();
  _bool->name("Bool");
  _bool->is_struct(true);
  _bool->is_embedded(true);
  compile_unit->types()->push_back(_bool);
  _bool->parent(compile_unit);
  _bool->scope(compile_unit->scope());

  auto _decimal = new CodeTypeDeclaration();
  _decimal->name("Decimal");
  _decimal->is_struct(true);
  _decimal->is_embedded(true);
  compile_unit->types()->push_back(_decimal);
  _decimal->parent(compile_unit);
  _decimal->scope(compile_unit->scope());

  auto _sbyte = new CodeTypeDeclaration();
  _sbyte->name("SByte");
  _sbyte->is_struct(true);
  _sbyte->is_embedded(true);
  compile_unit->types()->push_back(_sbyte);
  _sbyte->parent(compile_unit);
  _sbyte->scope(compile_unit->scope());

  auto _byte = new CodeTypeDeclaration();
  _byte->name("Byte");
  _byte->is_struct(true);
  _byte->is_embedded(true);
  compile_unit->types()->push_back(_byte);
  _byte->parent(compile_unit);
  _byte->scope(compile_unit->scope());

  auto _short = new CodeTypeDeclaration();
  _short->name("Int16");
  _short->is_struct(true);
  _short->is_embedded(true);
  compile_unit->types()->push_back(_short);
  _short->parent(compile_unit);
  _short->scope(compile_unit->scope());

  auto _ushort = new CodeTypeDeclaration();
  _ushort->name("UInt16");
  _ushort->is_struct(true);
  _ushort->is_embedded(true);
  compile_unit->types()->push_back(_ushort);
  _ushort->parent(compile_unit);
  _ushort->scope(compile_unit->scope());

  auto _int32 = new CodeTypeDeclaration();
  _int32->name("Int32");
  _int32->is_struct(true);
  _int32->is_embedded(true);
  compile_unit->types()->push_back(_int32);
  _int32->parent(compile_unit);
  _int32->scope(compile_unit->scope());

  auto _uint32 = new CodeTypeDeclaration();
  _uint32->name("UInt32");
  _uint32->is_struct(true);
  _uint32->is_embedded(true);
  compile_unit->types()->push_back(_uint32);
  _uint32->parent(compile_unit);
  _uint32->scope(compile_unit->scope());

  auto _long = new CodeTypeDeclaration();
  _long->name("Int64");
  _long->is_struct(true);
  _long->is_embedded(true);
  compile_unit->types()->push_back(_long);
  _long->parent(compile_unit);
  _long->scope(compile_unit->scope());

  auto _ulong = new CodeTypeDeclaration();
  _ulong->name("UInt64");
  _ulong->is_struct(true);
  _ulong->is_embedded(true);
  compile_unit->types()->push_back(_ulong);
  _ulong->parent(compile_unit);
  _ulong->scope(compile_unit->scope());

  auto _char = new CodeTypeDeclaration();
  _char->name("Char");
  _char->is_struct(true);
  _char->is_embedded(true);
  compile_unit->types()->push_back(_char);
  _char->parent(compile_unit);
  _char->scope(compile_unit->scope());

  auto _float = new CodeTypeDeclaration();
  _float->name("Single");
  _float->is_struct(true);
  _float->is_embedded(true);
  compile_unit->types()->push_back(_float);
  _float->parent(compile_unit);
  _float->scope(compile_unit->scope());

  auto _double = new CodeTypeDeclaration();
  _double->name("Double");
  _double->is_struct(true);
  _double->is_embedded(true);
  compile_unit->types()->push_back(_double);
  _double->parent(compile_unit);
  _double->scope(compile_unit->scope());

  auto _object = new CodeTypeDeclaration();
  _object->name("Object");
  _object->is_struct(true);
  _object->is_embedded(true);
  compile_unit->types()->push_back(_object);
  _object->parent(compile_unit);
  _object->scope(compile_unit->scope());

  auto _intptr = new CodeTypeDeclaration();
  _intptr->name("IntPtr");
  _intptr->is_struct(true);
  _intptr->is_embedded(true);
  compile_unit->types()->push_back(_intptr);
  _intptr->parent(compile_unit);
  _intptr->scope(compile_unit->scope());

  auto _type = new CodeTypeDeclaration();
  _type->name("Type");
  _type->is_class(true);
  _type->is_embedded(true);
  compile_unit->types()->push_back(_type);
  _type->parent(compile_unit);
  _type->scope(compile_unit->scope());

  auto _void = new CodeTypeDeclaration();
  _void->name("Void");
  _void->is_struct(true);
  _void->is_embedded(true);
  compile_unit->types()->push_back(_void);
  _void->parent(compile_unit);
  _void->scope(compile_unit->scope());

  auto array = new CodeTypeDeclaration();
  array->name("Array");
  array->is_class(true);
  array->is_embedded(true);
  compile_unit->types()->push_back(array);
  array->parent(compile_unit);
  array->scope(compile_unit->scope());

  auto operator_attribute = new CodeTypeDeclaration();
  operator_attribute->name("Operator");
  operator_attribute->is_class(true);
  operator_attribute->is_embedded(true);
  compile_unit->types()->push_back(operator_attribute);
  operator_attribute->parent(compile_unit);
  operator_attribute->scope(compile_unit->scope());

  auto cast_operator_attribute = new CodeTypeDeclaration();
  cast_operator_attribute->name("CastOperator");
  cast_operator_attribute->is_class(true);
  cast_operator_attribute->is_embedded(true);
  compile_unit->types()->push_back(cast_operator_attribute);
  cast_operator_attribute->parent(compile_unit);
  cast_operator_attribute->scope(compile_unit->scope());
}

CompilerResults *CodeCompiler::FromDomBatch(
    CompilerParameters &parameters, omega::CodeCompileUnit &compile_unit) {
  LOG(TRACE);
  auto ret = new CompilerResults();

  IncludeEmbeddedTypes(&compile_unit);

  SemanticAnalysis *semantics = this->m_provider.CreateSemanticAnalysis();
  semantics->analyse(&compile_unit);

  if (semantics->errors().size() > 0) {
    for (auto er : semantics->errors()) ret->errors().push_back(er);
  } else {
    CodeGenerator *code_gen = this->m_provider.CreateGenerator();
    auto module = code_gen->GenerateCodeFromCompileUnit(&compile_unit);

    if (parameters.optimize()) {
      runLLVMOptimizations1(module);
    }

    /*
std::string err;
llvm::raw_fd_ostream myfile("a.bc", err);
llvm::WriteBitcodeToFile(module, myfile);
myfile.close();
*/

    // if (parameters.dump_ir()) {
    // run them across all functions
    module->dump();
    //}
    /*
redi::ipstream llc(
"/home/mario/Projects/llvm.obj/Debug/bin/llc a.bc -filetype=obj");
std::string llc_out;
while (llc >> llc_out) {
std::cout << llc_out << std::endl;
}
*/

    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmPrinters();
    llvm::InitializeAllAsmParsers();

    std::error_code err;
    std::string out_file_name = "a.o";
    // llvm::tool_output_file outp(out_file_name.c_str(),
    // llvm::sys::fs::F_None);

    llvm::raw_fd_ostream outp(out_file_name.c_str(), err,
                              llvm::sys::fs::F_None);
    generateobj(outp, module);
    // if you want the .o file to stay on disk then uncomment following line
    // outp.keep();

    ret->output().push_back(out_file_name);
  }

  return ret;
}
}
