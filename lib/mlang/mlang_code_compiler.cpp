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

#include <llvm/PassManager.h>
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

#include "pstream.hh"
#include "mlang_code_compiler.hh"
#include "mlang_dom_provider.hh"
#include "mlang_code_generator.hh"
#include "mlang_semantic_analysis.hh"

using namespace mlang;

MLangCodeCompiler::MLangCodeCompiler(MLangDomProvider& p) :
		m_provider(p) {
}

MLangCodeCompiler::MLangCodeCompiler(const MLangCodeCompiler& orig) :
		m_provider(orig.m_provider) {
}

MLangCodeCompiler::~MLangCodeCompiler() {
}

MLangDomProvider& MLangCodeCompiler::provider() {
	return this->m_provider;
}

void runLLVMOptimizations1(llvm::Module* module) {
	// Set up the function-level optimizations we want
	llvm::FunctionPassManager passManager(module);
	passManager.add(llvm::createVerifierPass());
	passManager.add(llvm::createPromoteMemoryToRegisterPass());
	passManager.add(llvm::createReassociatePass());
	passManager.add(llvm::createGVNPass());
	//passManager.add(llvm::createCoalesceInsertsPass());
	passManager.add(llvm::createAggressiveDCEPass());

	passManager.add(llvm::createFlattenCFGPass());
	passManager.add(llvm::createInstructionCombiningPass());
	//passManager.add(llvm::createPartiallyInlineLibCallsPass());
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
	llvm::PassManager modulePassManager;
	modulePassManager.add(llvm::createAlwaysInlinerPass());
	modulePassManager.add(llvm::createGlobalOptimizerPass());

	// Optimize the whole module
	bool changed = modulePassManager.run(*module);

	if (changed) {
		// removing globals created stack allocations we want to eliminate
		llvm::FunctionPassManager postGlobalManager(module);
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
//        for (function = module->begin(), lastFunction = module->end(); function != lastFunction; ++function) {
//            memoryPassManager.run(*function);
//        }
//        memoryPassManager.doFinalization();
//    }
}

static int generateobj(llvm::tool_output_file* Out, llvm::Module * module) {
	llvm::PassManager PM;
	llvm::TargetOptions Options;
	std::string Err;
	llvm::Triple TheTriple(module->getTargetTriple());
	if (TheTriple.getTriple().empty())
		TheTriple.setTriple(llvm::sys::getDefaultTargetTriple());
	const llvm::Target* TheTarget = llvm::TargetRegistry::lookupTarget(
			TheTriple.getTriple(), Err);
	std::string MCPU, FeaturesStr;
	llvm::TargetMachine * machineTarget = TheTarget->createTargetMachine(
			TheTriple.getTriple(), MCPU, FeaturesStr, Options);
// Figure out where we are going to send the output...
	llvm::formatted_raw_ostream FOS(Out->os());
	if (machineTarget->addPassesToEmitFile(PM, FOS,
			llvm::TargetMachine::CGFT_ObjectFile, true)) {
		std::cerr << " target does not support generation of this"
				<< " file type!\n";
		return 1;
	}
	PM.run(*module);
	return 0;
}

void
MLangCodeCompiler::IncludeEmbeddedTypes(mlang::CodeCompileUnit* compile_unit) {
	//
	// create embedded types
	//
	CodeTypeDeclaration * _int1 = new CodeTypeDeclaration();
	_int1->name("Int1");
	_int1->is_struct(true);
	_int1->is_embedded(true);
	compile_unit->types()->push_back(_int1);
	_int1->parent(compile_unit);

	CodeTypeDeclaration * _bool = new CodeTypeDeclaration();
	_bool->name("Bool");
	_bool->is_struct(true);
	_bool->is_embedded(true);
	compile_unit->types()->push_back(_bool);
	_bool->parent(compile_unit);

	CodeTypeDeclaration * _decimal = new CodeTypeDeclaration();
	_decimal->name("Decimal");
	_decimal->is_struct(true);
	_decimal->is_embedded(true);
	compile_unit->types()->push_back(_decimal);
	_decimal->parent(compile_unit);

	CodeTypeDeclaration * _sbyte = new CodeTypeDeclaration();
	_sbyte->name("SByte");
	_sbyte->is_struct(true);
	_sbyte->is_embedded(true);
	compile_unit->types()->push_back(_sbyte);
	_sbyte->parent(compile_unit);

	CodeTypeDeclaration * _byte = new CodeTypeDeclaration();
	_byte->name("Byte");
	_byte->is_struct(true);
	_byte->is_embedded(true);
	compile_unit->types()->push_back(_byte);
	_byte->parent(compile_unit);

	CodeTypeDeclaration * _short = new CodeTypeDeclaration();
	_short->name("Int16");
	_short->is_struct(true);
	_short->is_embedded(true);
	compile_unit->types()->push_back(_short);
	_short->parent(compile_unit);

	CodeTypeDeclaration * _ushort = new CodeTypeDeclaration();
	_ushort->name("UInt16");
	_ushort->is_struct(true);
	_ushort->is_embedded(true);
	compile_unit->types()->push_back(_ushort);
	_ushort->parent(compile_unit);

	CodeTypeDeclaration * _int32 = new CodeTypeDeclaration();
	_int32->name("Int32");
	_int32->is_struct(true);
	_int32->is_embedded(true);
	compile_unit->types()->push_back(_int32);
	_int32->parent(compile_unit);

	CodeTypeDeclaration * _uint32 = new CodeTypeDeclaration();
	_uint32->name("UInt32");
	_uint32->is_struct(true);
	_uint32->is_embedded(true);
	compile_unit->types()->push_back(_uint32);
	_uint32->parent(compile_unit);

	CodeTypeDeclaration * _long = new CodeTypeDeclaration();
	_long->name("Int64");
	_long->is_struct(true);
	_long->is_embedded(true);
	compile_unit->types()->push_back(_long);
	_long->parent(compile_unit);

	CodeTypeDeclaration * _ulong = new CodeTypeDeclaration();
	_ulong->name("UInt64");
	_ulong->is_struct(true);
	_ulong->is_embedded(true);
	compile_unit->types()->push_back(_ulong);
	_ulong->parent(compile_unit);

	CodeTypeDeclaration * _char = new CodeTypeDeclaration();
	_char->name("Char");
	_char->is_struct(true);
	_char->is_embedded(true);
	compile_unit->types()->push_back(_char);
	_char->parent(compile_unit);

	CodeTypeDeclaration * _float = new CodeTypeDeclaration();
	_float->name("Single");
	_float->is_struct(true);
	_float->is_embedded(true);
	compile_unit->types()->push_back(_float);
	_float->parent(compile_unit);

	CodeTypeDeclaration * _double = new CodeTypeDeclaration();
	_double->name("Double");
	_double->is_struct(true);
	_double->is_embedded(true);
	compile_unit->types()->push_back(_double);
	_double->parent(compile_unit);

	CodeTypeDeclaration * _object = new CodeTypeDeclaration();
	_object->name("Object");
	_object->is_struct(true);
	_object->is_embedded(true);
	compile_unit->types()->push_back(_object);
	_object->parent(compile_unit);

	CodeTypeDeclaration * _intptr = new CodeTypeDeclaration();
	_intptr->name("IntPtr");
	_intptr->is_struct(true);
	_intptr->is_embedded(true);
	compile_unit->types()->push_back(_intptr);
	_intptr->parent(compile_unit);

	CodeTypeDeclaration * _type = new CodeTypeDeclaration();
	_type->name("Type");
	_type->is_class(true);
	_type->is_embedded(true);
	compile_unit->types()->push_back(_type);
	_type->parent(compile_unit);

	CodeTypeDeclaration * _void = new CodeTypeDeclaration();
	_void->name("Void");
	_void->is_struct(true);
	_void->is_embedded(true);
	compile_unit->types()->push_back(_void);
	_void->parent(compile_unit);

	CodeTypeDeclaration * array = new CodeTypeDeclaration();
	array->name("Array");
	array->is_class(true);
	array->is_embedded(true);
	compile_unit->types()->push_back(array);
	array->parent(compile_unit);

	CodeTypeDeclaration * operator_attribute = new CodeTypeDeclaration();
	operator_attribute->name("Operator");
	operator_attribute->is_class(true);
	operator_attribute->is_embedded(true);
	compile_unit->types()->push_back(operator_attribute);
	operator_attribute->parent(compile_unit);

	CodeTypeDeclaration * cast_operator_attribute = new CodeTypeDeclaration();
	cast_operator_attribute->name("CastOperator");
	cast_operator_attribute->is_class(true);
	cast_operator_attribute->is_embedded(true);
	compile_unit->types()->push_back(cast_operator_attribute);
	cast_operator_attribute->parent(compile_unit);
}

CompilerResults*
MLangCodeCompiler::FromDomBatch(CompilerParameters options,
		mlang::CodeCompileUnit* compile_unit) {
	auto ret = new CompilerResults();

	IncludeEmbeddedTypes(compile_unit);

	MLangSemanticAnalysis* semantics = this->m_provider.CreateSemanticAnalysis();
	semantics->analyse(compile_unit);

	if (semantics->errors().size() > 0) {
		for (auto er : semantics->errors())
			ret->errors().push_back(er);
	} else {
		MLangCodeGenerator* code_gen = this->m_provider.CreateGenerator();
		auto module = code_gen->GenerateCodeFromCompileUnit(compile_unit);

		if (options.optimize()) {
			runLLVMOptimizations1(module);
		}

		/*
		 std::string err;
		 llvm::raw_fd_ostream myfile("a.bc", err);
		 llvm::WriteBitcodeToFile(module, myfile);
		 myfile.close();
		 */

		if (options.dump_ir()) {
			// run them across all functions
			module->dump();
		}
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

		std::string err;
		std::string out_file_name = "a.o";
		llvm::tool_output_file outp(out_file_name.c_str(), llvm::sys::fs::F_None);
		generateobj(&outp, module);

		// if you want the .o file to stay on disk then uncomment following line
		// outp.keep();

		redi::ipstream ld(
				"ld --eh-frame-hdr -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o a.out /usr/bin/../lib64/gcc/x86_64-unknown-linux-gnu/4.9.2/../../../../lib64/crt1.o /usr/bin/../lib64/gcc/x86_64-unknown-linux-gnu/4.9.2/../../../../lib64/crti.o /usr/bin/../lib64/gcc/x86_64-unknown-linux-gnu/4.9.2/crtbegin.o -L/usr/bin/../lib64/gcc/x86_64-unknown-linux-gnu/4.9.2 -L/usr/bin/../lib64/gcc/x86_64-unknown-linux-gnu/4.9.2/../../../../lib64 -L/lib/../lib64 -L/usr/lib/../lib64 -L/usr/bin/../lib64/gcc/x86_64-unknown-linux-gnu/4.9.2/../../.. -L/lib -L/usr/lib a.o -lm -lgcc --as-needed -lgcc_s --no-as-needed -lc -lgcc --as-needed -lgcc_s --no-as-needed /usr/bin/../lib64/gcc/x86_64-unknown-linux-gnu/4.9.2/crtend.o /usr/bin/../lib64/gcc/x86_64-unknown-linux-gnu/4.9.2/../../../../lib64/crtn.o");

		//redi::ipstream ld("ld -m elf_x86_64 a.o -o a.out");

		std::string ld_out;
		while (ld >> ld_out) {
			std::cout << ld_out << std::endl;
		}
	}

	return ret;
}
