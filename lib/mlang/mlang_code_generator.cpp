/* 
 * File:   MLangCodeGenerator.cpp
 * Author: mario
 * 
 * Created on June 24, 2014, 11:26 PM
 */
#include <list>
#include <vector>
#include <iterator>
#include <stdint.h>
#include <iostream>

#include "mlang_code_generator.hh"
#include "mlang_code_type_inference.hh"
#include <llvm/Assembly/Parser.h>
#include <llvm/Linker.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/IR/InlineAsm.h>

MLangCodeGenerator::MLangCodeGenerator(const MLangDomProvider& p) :
		m_provider(p), m_context(llvm::getGlobalContext()) {
}

MLangCodeGenerator::MLangCodeGenerator(const MLangCodeGenerator& orig) :
		m_provider(orig.m_provider), m_context(orig.m_context) {
}

MLangCodeGenerator::~MLangCodeGenerator() {
}

const MLangDomProvider& MLangCodeGenerator::provider() {
	return this->m_provider;
}

static llvm::FunctionType* get_malloc_functiontype(llvm::Module* mod) {
	llvm::PointerType* PointerTy_3 = llvm::PointerType::get(
			llvm::IntegerType::get(mod->getContext(), 8), 0);
	std::vector<llvm::Type*> FuncTy_11_args;
	FuncTy_11_args.push_back(llvm::IntegerType::get(mod->getContext(), 64));
	llvm::FunctionType* FuncTy_11 = llvm::FunctionType::get(
	/*Result=*/PointerTy_3,
	/*Params=*/FuncTy_11_args,
	/*isVarArg=*/false);
	return FuncTy_11;
}

llvm::Module* MLangCodeGenerator::GenerateCodeFromCompileUnit(
		mlang::CodeCompileUnit* compile_unit) {

	// create the global namespace
	CodeNamespace * global_namespace = new CodeNamespace();
	global_namespace->name("");
	compile_unit->namespaces()->push_back(global_namespace);
	global_namespace->parent(compile_unit);

	// create system namespace
	CodeNamespace *system_namespace = new CodeNamespace();
	system_namespace->name("system");
	compile_unit->namespaces()->push_back(system_namespace);
	system_namespace->parent(compile_unit);

	//
	// create embedded types
	//
	CodeTypeDeclaration * _int1 = new CodeTypeDeclaration();
	_int1->name("Int1");
	_int1->is_struct(true);
	system_namespace->types()->push_back(_int1);
	_int1->parent(system_namespace);

	CodeTypeDeclaration * _bool = new CodeTypeDeclaration();
	_bool->name("Bool");
	_bool->is_struct(true);
	system_namespace->types()->push_back(_bool);
	_bool->parent(system_namespace);

	CodeTypeDeclaration * _decimal = new CodeTypeDeclaration();
	_decimal->name("Decimal");
	_decimal->is_struct(true);
	system_namespace->types()->push_back(_decimal);
	_decimal->parent(system_namespace);

	CodeTypeDeclaration * _sbyte = new CodeTypeDeclaration();
	_sbyte->name("SByte");
	_sbyte->is_struct(true);
	system_namespace->types()->push_back(_sbyte);
	_sbyte->parent(system_namespace);

	CodeTypeDeclaration * _byte = new CodeTypeDeclaration();
	_byte->name("Byte");
	_byte->is_struct(true);
	system_namespace->types()->push_back(_byte);
	_byte->parent(system_namespace);

	CodeTypeDeclaration * _short = new CodeTypeDeclaration();
	_short->name("Int16");
	_short->is_struct(true);
	system_namespace->types()->push_back(_short);
	_short->parent(system_namespace);

	CodeTypeDeclaration * _ushort = new CodeTypeDeclaration();
	_ushort->name("UInt16");
	_ushort->is_struct(true);
	system_namespace->types()->push_back(_ushort);
	_ushort->parent(system_namespace);

	CodeTypeDeclaration * _int32 = new CodeTypeDeclaration();
	_int32->name("Int32");
	_int32->is_struct(true);
	system_namespace->types()->push_back(_int32);
	_int32->parent(system_namespace);

	CodeTypeDeclaration * _uint32 = new CodeTypeDeclaration();
	_uint32->name("UInt32");
	_uint32->is_struct(true);
	system_namespace->types()->push_back(_uint32);
	_uint32->parent(system_namespace);

	CodeTypeDeclaration * _long = new CodeTypeDeclaration();
	_long->name("Int64");
	_long->is_struct(true);
	system_namespace->types()->push_back(_long);
	_long->parent(system_namespace);

	CodeTypeDeclaration * _ulong = new CodeTypeDeclaration();
	_ulong->name("UInt64");
	_ulong->is_struct(true);
	system_namespace->types()->push_back(_ulong);
	_ulong->parent(system_namespace);

	CodeTypeDeclaration * _char = new CodeTypeDeclaration();
	_char->name("Char");
	_char->is_struct(true);
	system_namespace->types()->push_back(_char);
	_char->parent(system_namespace);

	CodeTypeDeclaration * _float = new CodeTypeDeclaration();
	_float->name("Single");
	_float->is_struct(true);
	system_namespace->types()->push_back(_float);
	_float->parent(system_namespace);

	CodeTypeDeclaration * _double = new CodeTypeDeclaration();
	_double->name("Double");
	_double->is_struct(true);
	system_namespace->types()->push_back(_double);
	_double->parent(system_namespace);

	CodeTypeDeclaration * _object = new CodeTypeDeclaration();
	_object->name("Object");
	_object->is_struct(true);
	system_namespace->types()->push_back(_object);
	_object->parent(system_namespace);

	/*
	 CodeTypeDeclaration * _string = new CodeTypeDeclaration();
	 _string->name("Char[]");
	 _string->is_class(true);
	 system_namespace->types()->push_back(_string);
	 _string->parent(system_namespace);
	 */

	CodeTypeDeclaration * _void = new CodeTypeDeclaration();
	_void->name("Void");
	_void->is_struct(true);
	system_namespace->types()->push_back(_void);

	llvm::Module * module = new llvm::Module("in_memory_module", m_context);
	module->setDataLayout(
			"e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128");
	module->setTargetTriple("x86_64-unknown-linux-gnu");

	_int1->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt1Ty(
			m_context);

	//auto _bool = compile_unit->resolve_type("Bool");
	_bool->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt8Ty(
			m_context);

	//auto _char = compile_unit->resolve_type("Char");
	_char->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt8Ty(
			m_context); // single byte char

	//auto _sbyte = compile_unit->resolve_type("SByte");
	_sbyte->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt8Ty(
			m_context);

	//auto _byte = compile_unit->resolve_type("Byte");
	_byte->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt8Ty(
			m_context);

	//auto _short = compile_unit->resolve_type("Int16");
	_short->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt16Ty(
			m_context);

	//auto _ushort = compile_unit->resolve_type("UInt16");
	_ushort->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt16Ty(
			m_context);

	//auto _int32 = compile_unit->resolve_type("Int32");
	_int32->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt32Ty(
			m_context);

	//auto _uint32 = compile_unit->resolve_type("UInt32");
	_uint32->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt32Ty(
			m_context);

	//auto _long = compile_unit->resolve_type("Int64");
	_long->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt64Ty(
			m_context);

	//auto _ulong = compile_unit->resolve_type("UInt64");
	_ulong->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getInt64Ty(
			m_context);

	//auto _float = compile_unit->resolve_type("Single");
	_float->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getFloatTy(
			m_context);

	//auto _double = compile_unit->resolve_type("Double");
	_double->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getDoubleTy(
			m_context);

	//auto _decimal = compile_unit->resolve_type("Decimal");
	_decimal->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getFP128Ty(
			m_context);

	//
	// for this we actualy need to create the Object class
	//
	//auto _object = compile_unit->resolve_type("Object");
	//_object->llvm_type(llvm::Type::getVoidTy(m_context));

	//
	// for this we actualy need to create the String class
	//
	/*
	 _string = compile_unit->resolve_type("Char[]");
	 _string->llvm_type(_char->llvm_type()->getPointerTo());
	 */

	//auto _void = compile_unit->resolve_type("Void");
	_void->user_data()[UserDataKind::LLVM_TYPE] = llvm::Type::getVoidTy(
			m_context);

	for (auto code_type_declaration : *compile_unit->types()) {
		auto bblock = llvm::BasicBlock::Create(m_context,
				code_type_declaration->name(), 0, 0);
		auto gen = MLangCodeStatementGenerator(bblock);
		code_type_declaration->accept(&gen);
	}

	for (auto code_member_method : *compile_unit->methods()) {
		CreateFunction(module, code_member_method);
	}

	for (auto code_namespace : *compile_unit->namespaces()) {
		for (auto code_type_declaration : *code_namespace->types()) {
			auto bblock = llvm::BasicBlock::Create(m_context,
					code_type_declaration->name(), 0, 0);
			auto gen = MLangCodeStatementGenerator(bblock);
			code_type_declaration->accept(&gen);
		}

		for (auto code_member_method : *code_namespace->methods()) {
			CreateFunction(module, code_member_method);
		}
	}

	return module;
}

llvm::Value* load_if_needed(CodeObject* obj, llvm::Value* value,
		llvm::BasicBlock* block) {
	MLangCodeTypeInference inf;
	obj->accept(&inf);
	auto obj_type = inf.result();
	auto obj_type_decl = obj->resolve_type(obj_type);

	llvm::Value* ret = value;
	if (obj->type_of(CodeObjectKind::CodeVariableReferenceExpression)
			|| obj->type_of(CodeObjectKind::CodeArrayIndexerExpression)
			|| obj->type_of(CodeObjectKind::CodeFieldReferenceExpression))
		ret = new llvm::LoadInst(value, "", block);
	return ret;
}

llvm::Function* MLangCodeGenerator::CreateFunction(llvm::Module * module,
		mlang::CodeMemberMethod* method) {
	//Type *Result, ArrayRef<Type*> Params, bool IsVarArgs
	auto function_type = GetFunctionType(method->return_type(),
			method->parameters(), false);

	if (method->name() == "main" || method->name() == "_start")
		method->attributes(MemberAttributes::Public);

	std::string method_name = method->id();
	auto function = llvm::Function::Create(function_type,
			llvm::GlobalValue::LinkageTypes::ExternalLinkage, method_name,
			module);

	if (method->attributes() != MemberAttributes::External) {
		auto bblock = llvm::BasicBlock::Create(m_context, "entry", function, 0);

		llvm::Function::arg_iterator args = function->arg_begin();

		for (auto p : *method->parameters()) {
			llvm::Value* paramter_input = args++;
			paramter_input->setName(p->name());

			auto parameter_gen = MLangCodeStatementGenerator(bblock);
			p->accept(&parameter_gen);
			auto parameter_input_addr =
					(llvm::AllocaInst*) parameter_gen.result();

			//auto td = method->resolve_type(p->type());
			parameter_input_addr->setName(p->name() + ".addr");
			//llvm::StoreInst* void_15 =
			new llvm::StoreInst(paramter_input, parameter_input_addr, false,
					bblock);
		}

		if (method->statements() != nullptr) {
			for (auto statement : *method->statements()) {
				auto statement_gen = MLangCodeStatementGenerator(bblock);
				statement->accept(&statement_gen);
				//not used
				//auto statement_res = statement_gen.result();
				bblock = statement_gen.block();
			}
		}
	}

	return function;
}

llvm::FunctionType* MLangCodeGenerator::GetFunctionType(
		CodeTypeReference* code_type_reference,
		CodeParameterDeclarationExpressionCollection* params,
		bool is_var_args) {
	auto t = code_type_reference->resolve_type(code_type_reference);
	llvm::Type* result_type =
			static_cast<llvm::Type*>(t->user_data()[UserDataKind::LLVM_TYPE]);

	std::vector<llvm::Type*> param_types;
	if (params->size() > 0) {
		for (auto p : *params) {
			//std::string base_type_name = p->type();
			auto tp = p->resolve_type(p->type());
			auto llvm_type =
					static_cast<llvm::Type*>(tp->user_data()[UserDataKind::LLVM_TYPE]); //tp->llvm_type();

			param_types.push_back(llvm_type);
		}
	}

	llvm::FunctionType * ret = llvm::FunctionType::get(result_type, param_types,
			is_var_args);
	return ret;
}

MLangCodeStatementGenerator::MLangCodeStatementGenerator(
		llvm::BasicBlock* block) {
	this->m_result = nullptr;
	this->m_block = block;
}

MLangCodeStatementGenerator::~MLangCodeStatementGenerator() {

}

llvm::Value* MLangCodeStatementGenerator::result() {
	return this->m_result;
}

llvm::BasicBlock* MLangCodeStatementGenerator::block() {
	return this->m_block;
}

void MLangCodeStatementGenerator::visit(CodeBinaryOperatorExpression* object) {
	std::cout << ">> CodeBinaryOperatorExpression" << std::endl;
	llvm::LLVMContext& ctx = this->m_block->getContext();
	llvm::Constant *zero = llvm::Constant::getNullValue(llvm::IntegerType::getInt32Ty(ctx));

	llvm::Function* parent_function = this->m_block->getParent();
	llvm::Module* mod = parent_function->getParent();

	auto expression_left = object->left();
	auto expression_right = object->right();

	llvm::Value *expression_left_value = nullptr;
	llvm::Value *expression_right_value = nullptr;

	CodeTypeDeclaration *left_type_decl = nullptr;
	CodeTypeReference *left_type = nullptr;
	CodeTypeDeclaration *right_type_decl = nullptr;
	CodeTypeReference *right_type = nullptr;

	std::list<CodeTypeDeclaration*> method_arg_types;
	std::vector<llvm::Value*> method_args;

	if (expression_left != nullptr) {
		auto expression_gen_left = MLangCodeStatementGenerator(this->m_block);
		expression_left->accept(&expression_gen_left);
		expression_left_value = expression_gen_left.result();

		MLangCodeTypeInference type_inf;
		expression_left->accept(&type_inf);
		left_type = type_inf.result();
		left_type_decl = object->resolve_type(left_type);
		method_arg_types.push_back(left_type_decl);

		expression_left_value = load_if_needed(expression_left,
				expression_left_value, this->m_block);
		method_args.push_back(expression_left_value);
	}

	if (expression_right != nullptr) {
		auto expression_gen_right = MLangCodeStatementGenerator(this->m_block);
		expression_right->accept(&expression_gen_right);
		expression_right_value = expression_gen_right.result();

		MLangCodeTypeInference type_inf;
		expression_right->accept(&type_inf);
		right_type = type_inf.result();
		right_type_decl = object->resolve_type(right_type);
		method_arg_types.push_back(right_type_decl);

		expression_right_value = load_if_needed(expression_right,
				expression_right_value, this->m_block);
		method_args.push_back(expression_right_value);
	}

	CodeMemberMethod * resolved_method = nullptr;
	llvm::Function* f = nullptr;
	std::string method_name = "";
	switch(object->operator_())
	{
		case CodeBinaryOperatorType::Add:
			method_name = "add";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			break;
		case CodeBinaryOperatorType::Divide:
			method_name = "divide";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			break;
		case CodeBinaryOperatorType::Subtract:
			method_name = "subtract";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			break;
		case CodeBinaryOperatorType::Multiply:
			method_name = "multiply";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			break;
		case CodeBinaryOperatorType::Modulus:
			method_name = "modulus";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			break;
		case CodeBinaryOperatorType::ShiftLeft:
			method_name = "shift_left";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			break;
		case CodeBinaryOperatorType::ShiftRight:
			method_name = "shift_right";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			break;
		case CodeBinaryOperatorType::BitwiseOr:
			this->m_result = llvm::BinaryOperator::CreateOr(expression_left_value, expression_right_value, "", this->m_block);
			break;
		case CodeBinaryOperatorType::BooleanOr:
			this->m_result = llvm::BinaryOperator::CreateOr(expression_left_value, expression_right_value, "", this->m_block);
			break;
		case CodeBinaryOperatorType::BitwiseAnd:
			this->m_result = llvm::BinaryOperator::CreateAnd(expression_left_value, expression_right_value, "", this->m_block);
			break;
		case CodeBinaryOperatorType::BooleanAnd:
			this->m_result = llvm::BinaryOperator::CreateAnd(expression_left_value, expression_right_value, "", this->m_block);
			break;
		case CodeBinaryOperatorType::ExlusiveOr:
			this->m_result = llvm::BinaryOperator::CreateXor(expression_left_value, expression_right_value, "", this->m_block);
			break;
		case CodeBinaryOperatorType::IdentityEquality:
			method_name = "equals";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			break;
		case CodeBinaryOperatorType::IdentityInEquality:
			method_name = "not_equals";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			break;
		case CodeBinaryOperatorType::LessThan:
			method_name = "compare";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			this->m_result = llvm::ICmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_ULT, this->m_result, zero, "", this->m_block);
			break;
		case CodeBinaryOperatorType::LessThanOrEqual:
			method_name = "compare";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			this->m_result = llvm::ICmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_ULE, this->m_result, zero, "", this->m_block);
			break;
		case CodeBinaryOperatorType::GreaterThan:
			method_name = "compare";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			this->m_result = llvm::ICmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_UGT, this->m_result, zero, "", this->m_block);
			break;
		case CodeBinaryOperatorType::GreaterThanOrEqual:
			method_name = "compare";
			resolved_method = object->resolve_method(method_name, &method_arg_types);
			f = mod->getFunction(resolved_method->id());
			this->m_result = llvm::CallInst::Create(f, method_args, "", this->m_block);
			this->m_result = llvm::ICmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_UGE, this->m_result, zero, "", this->m_block);
			break;
	}
}

void MLangCodeStatementGenerator::visit(CodeCompileUnit* object) {
	std::cout << ">> CodeCompileUnit" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeExpression* object) {
	std::cout << ">> CodeExpression" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeMemberField* object) {
	std::cout << ">> CodeMemberField" << std::endl;

}

void MLangCodeStatementGenerator::visit(CodeMemberMethod* object) {
	std::cout << ">> CodeMemberMethod" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeMemberProperty* object) {
	std::cout << ">> CodeMemberProperty" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeMethodReturnStatement* object) {
	std::cout << ">> CodeMethodReturnStatement" << std::endl;
	auto expression = object->expression();
	if (expression != nullptr) {
		auto expression_gen = MLangCodeStatementGenerator(this->m_block);
		expression->accept(&expression_gen);
		auto return_val = expression_gen.result();
		return_val = load_if_needed(expression, return_val, this->m_block);

		m_result = llvm::ReturnInst::Create(this->m_block->getContext(),
				return_val, m_block);
	} else {
		// return void
		m_result = llvm::ReturnInst::Create(this->m_block->getContext(),
				m_block);
	}
}

void MLangCodeStatementGenerator::visit(CodeNamespace* object) {
	std::cout << ">> CodeNamespace" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeObject* object) {
	std::cout << ">> CodeObject" << std::endl;
}

void MLangCodeStatementGenerator::visit(
		CodeParameterDeclarationExpression* object) {
	std::cout << ">> CodeParameterDeclarationExpression" << std::endl;

	auto type_reference = object->type();
	CodeTypeDeclaration * td = object->resolve_type(type_reference);
	llvm::Type * type =
			static_cast<llvm::Type*>(td->user_data()[UserDataKind::LLVM_TYPE]); //td->llvm_type();

	auto name = object->name();
	llvm::AllocaInst *alloc = new llvm::AllocaInst(type, name.c_str(),
			this->m_block);

	object->user_data()[UserDataKind::LLVM_L_VALUE] = alloc;
	this->m_result = alloc;
}

void MLangCodeStatementGenerator::visit(CodePrimitiveExpression* object) {
	std::cout << ">> CodePrimitiveExpression" << std::endl;

	auto module = this->m_block->getParent()->getParent();
	llvm::LLVMContext& ctx = this->m_block->getContext();

	auto type_reference = object->type();
	CodeTypeDeclaration * td = object->resolve_type(type_reference);
	llvm::Type * type =
			static_cast<llvm::Type*>(td->user_data()[UserDataKind::LLVM_TYPE]); //td->llvm_type();

	if (td->name() == "Int32") {
		uint64_t v = (uint64_t) (uint64_t*) object->value();
		m_result = llvm::ConstantInt::get(
				llvm::Type::getInt32Ty(m_block->getContext()), v, true);
	}

	if (td->name() == "Char[]") {
		std::string v = object->value_as_string();
		// not used
		llvm::Constant *str_val = llvm::ConstantDataArray::getString(ctx, v);

		llvm::GlobalVariable *str_var = new llvm::GlobalVariable(*module,
				llvm::ArrayType::get(llvm::IntegerType::get(ctx, 8),
						(uint64_t) v.size() + 1), true,
				llvm::GlobalValue::PrivateLinkage, str_val, "");

		str_var->setInitializer(str_val);

		llvm::Constant *zero = llvm::Constant::getNullValue(
				llvm::IntegerType::getInt32Ty(ctx));

		std::vector<llvm::Constant*> indices;
		indices.push_back(zero);
		indices.push_back(zero);
		llvm::Constant *var_ref = llvm::ConstantExpr::getGetElementPtr(str_var,
				indices);
		m_result = var_ref;
	}

	std::cout << "<< CodePrimitiveExpression" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeStatement* object) {
	std::cout << ">> CodeStatement" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeTypeDeclaration* object) {
	std::cout << ">> CodeTypeDeclaration \"" << object->name() << "\""
			<< std::endl;

	llvm::LLVMContext& ctx = this->m_block->getContext();

	if (object->is_struct()) {
		std::string struct_name = object->name();
		llvm::StructType * struct_type = llvm::StructType::create(ctx,
				struct_name);

		std::vector<llvm::Type*> struct_type_fields;

		for (auto field_decl : *object->members()) {
			CodeMemberField * field = static_cast<CodeMemberField*>(field_decl);
			if (field != nullptr) {
				CodeTypeDeclaration * td = object->resolve_type(field->type());
				llvm::Type * field_type =
						static_cast<llvm::Type*>(td->user_data()[UserDataKind::LLVM_TYPE]); //td->llvm_type();
				struct_type_fields.push_back(field_type);
			}
		}

		if (struct_type->isOpaque()) {
			struct_type->setBody(struct_type_fields, /*isPacked=*/false);
		}

		object->user_data()[UserDataKind::LLVM_TYPE] = struct_type;
	}

	if (object->is_class()) {
		std::string class_name = object->name();
		llvm::StructType * class_type = llvm::StructType::create(ctx,
				class_name);

		std::vector<llvm::Type*> class_type_fields;

		for (auto field_decl : *object->members()) {
			CodeMemberField * field = static_cast<CodeMemberField*>(field_decl);
			if (field != nullptr) {
				CodeTypeDeclaration * td = object->resolve_type(field->type());
				llvm::Type * field_type =
						static_cast<llvm::Type*>(td->user_data()[UserDataKind::LLVM_TYPE]); //td->llvm_type();
				class_type_fields.push_back(field_type);
			}
		}

		if (class_type->isOpaque()) {
			class_type->setBody(class_type_fields, /*isPacked=*/false);
		}

		llvm::Type * tp = llvm::PointerType::get(class_type, 0);
		//object->llvm_type(tp);
		object->user_data()[UserDataKind::LLVM_TYPE] = tp;
	}

	std::cout << "<< CodeTypeDeclaration" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeTypeMember* object) {
	std::cout << ">> CodeTypeMember" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeTypeReference* object) {
	std::cout << ">> CodeTypeReference" << std::endl;

}

void MLangCodeStatementGenerator::visit(
		CodeVariableDeclarationStatement* object) {
	std::cout << ">> CodeVariableDeclarationStatement" << std::endl;

	// find out the llvm type
	auto type_reference = object->type();
	CodeTypeDeclaration * td = object->resolve_type(type_reference);
	llvm::Type * type =
			static_cast<llvm::Type*>(td->user_data()[UserDataKind::LLVM_TYPE]); //td->llvm_type();

	auto name = object->name();

	llvm::AllocaInst *alloc = new llvm::AllocaInst(type, name.c_str(),
			this->m_block);
	object->user_data()[UserDataKind::LLVM_L_VALUE] = alloc;
	//object->alloca_inst(alloc);
	this->m_result = alloc;

	if (object->init_expression() != nullptr) {
		MLangCodeStatementGenerator * expr = new MLangCodeStatementGenerator(
				this->m_block);
		object->init_expression()->accept(expr);
		auto expr_res = expr->result();
		expr_res = load_if_needed(object->init_expression(), expr_res,
				this->m_block);

		if (expr_res != nullptr) {
			new llvm::StoreInst(expr_res, alloc, false, this->m_block);
		}
	}

	std::cout << "<< CodeVariableDeclarationStatement" << std::endl;
}

void MLangCodeStatementGenerator::visit(
		CodeVariableReferenceExpression* object) {
	std::cout << ">> CodeVariableReferenceExpression" << std::endl;
	//not used
	//CodeScope * scope = object->scope();

	auto var = object->resolve_variable(object->variable_name());
	if (var == nullptr || var->size() == 0)
		return;
	//CodeTypeDeclaration* var_type = nullptr;

	llvm::Value* left = nullptr;
	int i = 0;
	for (CodeObject* part : *var) {
		if (i == 0) {
			if (part->type_of(
					CodeObjectKind::CodeVariableDeclarationStatement)) {
				CodeVariableDeclarationStatement* code_variable_declaration_statement =
						static_cast<CodeVariableDeclarationStatement*>(part);
				//var_type = object->resolve_type(code_variable_declaration_statement->type());
				left =
						static_cast<llvm::Value*>(code_variable_declaration_statement->user_data()[UserDataKind::LLVM_L_VALUE]); //code_variable_declaration_statement->alloca_inst();
			}

			if (part->type_of(
					CodeObjectKind::CodeParameterDeclarationExpression)) {
				CodeParameterDeclarationExpression* code_parameter_declaration_statement =
						static_cast<CodeParameterDeclarationExpression*>(part);
				//var_type = object->resolve_type(code_parameter_declaration_statement->type());
				left =
						static_cast<llvm::Value*>(code_parameter_declaration_statement->user_data()[UserDataKind::LLVM_L_VALUE]); //code_parameter_declaration_statement->alloca_inst();
			}
		} else {
			if (part->type_of(CodeObjectKind::CodeMemberField)) {
				CodeMemberField* code_member_field =
						static_cast<CodeMemberField*>(part);
				CodeTypeDeclaration* t_d =
						static_cast<CodeTypeDeclaration*>(code_member_field->parent());
				//var_type = object->resolve_type(code_member_field->type());

				int index = 0;
				for (auto x : *t_d->members()) {
					if (x == code_member_field)
						break;

					if (x->type_of(CodeObjectKind::CodeMemberField))
						index++;
				}

				llvm::ConstantInt* const_int32_0 = llvm::ConstantInt::get(
						this->m_block->getContext(),
						llvm::APInt(32, llvm::StringRef("0"), 10));
				llvm::ConstantInt* const_int32_i = llvm::ConstantInt::get(
						this->m_block->getContext(), llvm::APInt(32, index));

				std::vector<llvm::Value*> ptr_a_indices;
				ptr_a_indices.push_back(const_int32_0);
				ptr_a_indices.push_back(const_int32_i);

				left = llvm::GetElementPtrInst::Create(left, ptr_a_indices,
						code_member_field->name(), this->m_block);
			}
		}
		i++;
	}

	this->m_result = left;
	std::cout << "<< CodeVariableReferenceExpression" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeCastExpression* object) {
	std::cout << ">> CodeCastExpression" << std::endl;
	CodeTypeDeclaration* td = object->resolve_type(object->target_type());

	auto tp_gen = new MLangCodeStatementGenerator(this->m_block);
	object->expression()->accept(tp_gen);

	if (td->name() == "Int32") {
		auto result_tmp = tp_gen->result();
		auto llvm_type =
				static_cast<llvm::Type*>(td->user_data()[UserDataKind::LLVM_TYPE]); //td->llvm_type();
		llvm::CastInst* int32_18 = new llvm::TruncInst(result_tmp, llvm_type,
				"", this->m_block);
		m_result = int32_18;
	} else if (td->name() == "Int64") {
		auto result_tmp = tp_gen->result();
		auto llvm_type =
				static_cast<llvm::Type*>(td->user_data()[UserDataKind::LLVM_TYPE]); //td->llvm_type();
		llvm::CastInst* int64_21 = new llvm::SExtInst(result_tmp, llvm_type, "",
				this->m_block);
		m_result = int64_21;
	}
}

void MLangCodeStatementGenerator::visit(CodeObjectCreateExpression* object) {
	std::cout << ">> CodeObjectCreateExpression" << std::endl;

	auto resolved = object->resolve_type(object->create_type());

	if (resolved->is_class()) {
		auto module = this->m_block->getParent()->getParent();
		llvm::LLVMContext& context = module->getContext();

		//llvm::FunctionType*tp = malloc_prototype(context, module);

		auto resolved = object->resolve_type(object->create_type());
		auto create_type =
				(llvm::PointerType*) static_cast<llvm::Type*>(resolved->user_data()[UserDataKind::LLVM_TYPE]); //resolved->llvm_type();
		auto element_type = create_type->getElementType();

		llvm::DataLayout l = llvm::DataLayout(module);
		llvm::ConstantInt* const_int64_14 = llvm::ConstantInt::get(
				module->getContext(),
				llvm::APInt(64, l.getTypeAllocSize(element_type)));

		llvm::Function* func_malloc = module->getFunction("malloc");
		llvm::CallInst* ptr_19 = llvm::CallInst::Create(func_malloc,
				const_int64_14, "", this->m_block);
		this->m_result = new llvm::BitCastInst(ptr_19, create_type, "",
				this->m_block);
	} else {
		this->m_result = nullptr;
	}
}

void MLangCodeStatementGenerator::visit(CodeFileImport* object) {
	std::cout << ">> CodeFileImport" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeFieldReferenceExpression* object) {
	std::cout << ">> CodeFieldReferenceExpression" << std::endl;

	MLangCodeTypeInference type_inf;
	object->target_object()->accept(&type_inf);
	auto target_object_type = object->resolve_type(type_inf.result());

	llvm::Value* target_object_value;
	MLangCodeStatementGenerator * target_object_gen =
			new MLangCodeStatementGenerator(this->m_block);
	object->target_object()->accept(target_object_gen);
	target_object_value = target_object_gen->result();

	int index = 0;
	for (auto x : *target_object_type->members()) {
		if (x->name() == object->field_name())
			break;

		if (x->type_of(CodeObjectKind::CodeMemberField))
			index++;
	}

	llvm::ConstantInt* const_int32_0 = llvm::ConstantInt::get(
			this->m_block->getContext(),
			llvm::APInt(32, llvm::StringRef("0"), 10));
	llvm::ConstantInt* const_int32_i = llvm::ConstantInt::get(
			this->m_block->getContext(), llvm::APInt(32, index));

	std::vector<llvm::Value*> ptr_a_indices;
	ptr_a_indices.push_back(const_int32_0);
	ptr_a_indices.push_back(const_int32_i);

	target_object_value = load_if_needed(object->target_object(),
			target_object_value, this->m_block);
	this->m_result = llvm::GetElementPtrInst::Create(target_object_value,
			ptr_a_indices, object->field_name(), this->m_block);
}

void MLangCodeStatementGenerator::visit(CodeArrayIndexerExpression* object) {
	std::cout << ">> CodeArrayIndexerExpression" << std::endl;

	auto m_func = this->m_block->getParent();
	auto m_module = m_func->getParent();
	llvm::LLVMContext & m_context = m_module->getContext();

	static llvm::Constant *zero = llvm::Constant::getNullValue(
			llvm::IntegerType::getInt32Ty(m_context));

	MLangCodeStatementGenerator * target_object_gen =
			new MLangCodeStatementGenerator(this->m_block);
	object->target_object()->accept(target_object_gen);
	llvm::Value* ptr_29 = target_object_gen->result(); // reference to array
	//ptr_29 = new llvm::LoadInst(ptr_29, "", this->m_block);

	ptr_29 = load_if_needed(object->target_object(), ptr_29, this->m_block);
	// -> need a loadinst

	std::vector<llvm::Value*> indices;
	for (auto x : *object->indices()) {
		MLangCodeStatementGenerator * index_gen =
				new MLangCodeStatementGenerator(this->m_block);
		x->accept(index_gen);
		llvm::Value* index = index_gen->result();
		index = load_if_needed(x, index, this->m_block);
		indices.push_back(index);
	}

	llvm::GetElementPtrInst* ptr_30 = llvm::GetElementPtrInst::Create(ptr_29,
			indices, "", this->m_block);

	this->m_result = ptr_30;
	//this->m_result = new llvm::LoadInst(this->m_result, "", this->m_block);

}

void MLangCodeStatementGenerator::visit(CodeArrayCreateExpression* object) {
	std::cout << ">> CodeArrayCreateExpression" << std::endl;

	auto m_func = this->m_block->getParent();
	auto m_module = m_func->getParent();
	llvm::LLVMContext & m_context = m_module->getContext();

	auto resolved = object->resolve_type(object->create_type());
	auto create_type =
			static_cast<llvm::Type*>(resolved->user_data()[UserDataKind::LLVM_TYPE]); //resolved->llvm_type();
	auto element_type = create_type->getScalarType();

	MLangCodeStatementGenerator * size_gen = new MLangCodeStatementGenerator(
			this->m_block);
	object->size_expression()->accept(size_gen);
	llvm::Value* size_expression = size_gen->result();

	size_expression = load_if_needed(object->size_expression(), size_expression,
			this->m_block);
	//auto alloca = new llvm::AllocaInst(create_type, size_expression, "", this->m_block);
	//this->m_result = alloca;

	auto func_malloc = m_module->getOrInsertFunction("malloc",
			get_malloc_functiontype(m_module));
	llvm::CallInst* ptr_55 = llvm::CallInst::Create(func_malloc,
			size_expression, "", this->m_block);
	this->m_result = ptr_55;
}

void MLangCodeStatementGenerator::visit(CodeAssemblyCallExpression* object) {
	std::cout << ">> CodeAsmBlockStatement" << std::endl;

	auto m_func = this->m_block->getParent();
	auto m_module = m_func->getParent();
	llvm::LLVMContext & m_context = m_module->getContext();

	std::vector<llvm::Value*> args;
	std::list<CodeTypeDeclaration*> parameter_types;
	std::vector<llvm::Type*> parameter_llvm_types;

	auto cv = llvm::InlineAsm::ParseConstraints(object->constraints());

	//ia->ParseConstraints().front().Type == llvm::InlineAsm::ConstraintPrefix::isInput;

	llvm::Type* return_type = llvm::Type::getVoidTy(m_context);

	int i = 0;
	for (auto p_arg : *object->parameters()) {
		MLangCodeTypeInference type_inf;
		p_arg->accept(&type_inf);
		auto par_type = object->resolve_type(type_inf.result());
		parameter_types.push_back(par_type);
		llvm::Type* tp =
				static_cast<llvm::Type*>(par_type->user_data()[UserDataKind::LLVM_TYPE]); //par_type->llvm_type()
		parameter_llvm_types.push_back(tp);

		if (cv.at(i).Type == llvm::InlineAsm::ConstraintPrefix::isOutput)
			return_type = tp;

		MLangCodeStatementGenerator * p_gen = new MLangCodeStatementGenerator(
				this->m_block);
		p_arg->accept(p_gen);
		auto res = p_gen->result();
		res = load_if_needed(p_arg, res, this->m_block);
		args.push_back(res);
	}

	auto FT = llvm::FunctionType::get(return_type, parameter_llvm_types, false);
	llvm::InlineAsm* ia = llvm::InlineAsm::get(FT, object->content(),
			object->constraints(), true);

	llvm::CallInst* call_inst = llvm::CallInst::Create(ia, args, "",
			this->m_block);
	call_inst->setCallingConv(llvm::CallingConv::C);
	call_inst->setTailCall(false);

	this->m_result = call_inst;
	/*		::get(FT, code, constraints, sideeffect);
	 llvm::Value* rv = gIR->ir->CreateCall(ia, args, "");
	 */

	std::cout << "<< CodeAsmBlockStatement" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeIrBlockStatement* object) {
	std::cout << ">> CodeIrBlockStatement" << std::endl;

	auto m_func = this->m_block->getParent();
	auto m_module = m_func->getParent();
	llvm::LLVMContext & m_context = m_module->getContext();

	std::string str;
	llvm::raw_string_ostream stream(str);
	stream << "define " << "void" << " @_" << object->id() << "(";
	int i = 0;

	std::vector<llvm::Value*> params;
	CodeScope* parent = object->scope();
	while (parent != nullptr) {

		for (auto m : *parent->members()) {
			if (m->type_of(CodeObjectKind::CodeVariableDeclarationStatement)) {
				CodeVariableDeclarationStatement * var =
						(CodeVariableDeclarationStatement*) m;
				if (i > 0)
					stream << ", ";
				auto l_value =
						static_cast<llvm::Value*>(var->user_data()[UserDataKind::LLVM_L_VALUE]); //
				l_value->getType()->print(stream);
				stream << " ";
				stream << "%" << var->name();
				params.push_back(l_value);
				i++;
			}

			if (m->type_of(
					CodeObjectKind::CodeParameterDeclarationExpression)) {
				CodeParameterDeclarationExpression * var =
						(CodeParameterDeclarationExpression*) m;
				if (i > 0)
					stream << ", ";

				auto l_value =
						static_cast<llvm::Value*>(var->user_data()[UserDataKind::LLVM_L_VALUE]); //
				l_value->getType()->print(stream);
				stream << " ";
				stream << "%" << var->name();
				params.push_back(l_value);
				i++;
			}
		}

		parent = parent->parent();
	}

	// stream 	<< 1. generate parameters
	stream << ")\n{\n" << object->content() << "\nret void\n}";

	llvm::SMDiagnostic err;
	auto m = llvm::ParseAssemblyString(stream.str().c_str(), m_module, err,
			m_context);

	std::string errstr = err.getMessage();
	if (errstr != "")
		std::cout << "can't parse inline LLVM IR:\n"
				<< err.getLineContents().str().c_str() << "\n"
				<< (std::string(err.getColumnNo(), ' ') + '^').c_str()
				<< errstr.c_str() << "\nThe input string was: \n"
				<< stream.str().c_str();

	std::string errstr2 = "";
	llvm::Linker(m_module).linkInModule(m, &errstr2);

	llvm::Function* fun = m_module->getFunction("_" + object->id());
	fun->setLinkage(llvm::GlobalValue::LinkOnceODRLinkage);
	fun->addFnAttr(llvm::Attribute::AlwaysInline);
	this->m_result = llvm::CallInst::Create(fun, params, "", this->m_block);
}

void MLangCodeStatementGenerator::visit(CodeAssignExpression* object) {
	std::cout << ">> CodeAssignExpression" << std::endl;

	llvm::Value* left = nullptr;

	if (object->left() != nullptr
			&& object->left()->type_of(
					CodeObjectKind::CodeVariableReferenceExpression)) {
		CodeObjectCollection* var = nullptr;
		CodeVariableReferenceExpression * v =
				static_cast<CodeVariableReferenceExpression*>(object->left());
		var = (CodeObjectCollection*) object->resolve_variable(
				v->variable_name());
		if (var == nullptr || var->size() == 0)
			return;

		int i = 0;
		for (CodeObject* part : *var) {
			if (i == 0) {
				if (part->type_of(
						CodeObjectKind::CodeVariableDeclarationStatement)) {
					CodeVariableDeclarationStatement* code_variable_declaration_statement =
							static_cast<CodeVariableDeclarationStatement*>(part);
					left =
							static_cast<llvm::Value*>(code_variable_declaration_statement->user_data()[UserDataKind::LLVM_L_VALUE]); //code_variable_declaration_statement->alloca_inst();
				}

				if (part->type_of(
						CodeObjectKind::CodeParameterDeclarationExpression)) {
					CodeParameterDeclarationExpression* code_parameter_declaration_statement =
							static_cast<CodeParameterDeclarationExpression*>(part);
					left =
							static_cast<llvm::Value*>(code_parameter_declaration_statement->user_data()[UserDataKind::LLVM_L_VALUE]); //code_parameter_declaration_statement->alloca_inst();
				}
			} else {
				if (part->type_of(CodeObjectKind::CodeMemberField)) {
					CodeMemberField* code_member_field =
							static_cast<CodeMemberField*>(part);
					CodeTypeDeclaration* t_d =
							static_cast<CodeTypeDeclaration*>(code_member_field->parent());

					int index = 0;
					for (auto x : *t_d->members()) {
						if (x == code_member_field)
							break;

						if (x->type_of(CodeObjectKind::CodeMemberField))
							index++;
					}

					llvm::ConstantInt* const_int32_0 = llvm::ConstantInt::get(
							this->m_block->getContext(),
							llvm::APInt(32, llvm::StringRef("0"), 10));
					llvm::ConstantInt* const_int32_i = llvm::ConstantInt::get(
							this->m_block->getContext(),
							llvm::APInt(32, index));

					std::vector<llvm::Value*> ptr_a_indices;
					ptr_a_indices.push_back(const_int32_0);
					ptr_a_indices.push_back(const_int32_i);

					if (t_d->is_class())
						left = new llvm::LoadInst(left, "", this->m_block);

					left = llvm::GetElementPtrInst::Create(left, ptr_a_indices,
							code_member_field->name(), this->m_block);
				}
			}
			i++;
		}
	}

	if (object->left() != nullptr
			&& object->left()->type_of(
					CodeObjectKind::CodeArrayIndexerExpression)) {
		CodeArrayIndexerExpression * v =
				static_cast<CodeArrayIndexerExpression*>(object->left());

		MLangCodeStatementGenerator * p_gen = new MLangCodeStatementGenerator(
				this->m_block);
		v->accept(p_gen);
		auto res = p_gen->result();
		left = res;
	}

	if (object->left() != nullptr
			&& object->left()->type_of(
					CodeObjectKind::CodeFieldReferenceExpression)) {
		CodeFieldReferenceExpression * v =
				static_cast<CodeFieldReferenceExpression*>(object->left());
		MLangCodeStatementGenerator * p_gen = new MLangCodeStatementGenerator(
				this->m_block);
		v->accept(p_gen);
		auto res = p_gen->result();
		left = res;
	}

	MLangCodeStatementGenerator * right_gen = new MLangCodeStatementGenerator(
			this->m_block);
	object->right()->accept(right_gen);
	llvm::Value* right = right_gen->result();
	right = load_if_needed(object->right(), right, this->m_block);

	auto st = new llvm::StoreInst(right, left, false, this->m_block);
	this->m_result = left;
	std::cout << "<< CodeAssignExpression" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeExpressionStatement* object) {
	std::cout << ">> CodeExpressionStatement" << std::endl;

	MLangCodeStatementGenerator * gen = new MLangCodeStatementGenerator(
			this->m_block);
	object->expression()->accept(gen);
	m_result = gen->result();

	m_result = load_if_needed(object->expression(), m_result, this->m_block); // new llvm::LoadInst(m_result, "", this->m_block);
}

void MLangCodeStatementGenerator::visit(CodeMethodInvokeExpression* object) {
	std::cout << ">> CodeMethodInvokeExpression" << std::endl;

	auto parent_function = this->m_block->getParent();
	auto module = parent_function->getParent();
	llvm::LLVMContext& ctx = module->getContext();

	std::vector<llvm::Value*> args;

	std::list<CodeTypeDeclaration*>* parameter_types =
			new std::list<CodeTypeDeclaration*>();

	if (object->method()->target_object() != nullptr) {
		MLangCodeStatementGenerator * p_gen = new MLangCodeStatementGenerator(
				this->m_block);
		object->method()->target_object()->accept(p_gen);
		auto res = p_gen->result();
		res = load_if_needed(object->method()->target_object(), res,
				this->m_block);
		args.push_back(res);

		MLangCodeTypeInference type_inf;
		object->method()->target_object()->accept(&type_inf);
		parameter_types->push_back(object->resolve_type(type_inf.result()));
	}

	for (auto p_arg : *object->parameters()) {
		MLangCodeTypeInference type_inf;
		p_arg->accept(&type_inf);
		auto par_type = object->resolve_type(type_inf.result());
		parameter_types->push_back(par_type);

		MLangCodeStatementGenerator * p_gen = new MLangCodeStatementGenerator(
				this->m_block);
		p_arg->accept(p_gen);
		auto res = p_gen->result();
		res = load_if_needed(p_arg, res, this->m_block);
		args.push_back(res);
	}

	auto resolved_method = object->resolve_method(
			object->method()->method_name(), parameter_types);
	llvm::Function* f = nullptr;

	/*if (resolved_method == nullptr
	 && object->method()->method_name() == "print")
	 f = (llvm::Function*) module->getOrInsertFunction("printf",
	 printf_prototype(ctx, module));
	 else*/

	f = module->getFunction(resolved_method->id());

	/*if (f->getName() == "printf") {
	 this->m_result = create_print_call(f, args[0], this->m_block);
	 } else
	 {*/
	this->m_result = llvm::CallInst::Create(f, args, "", this->m_block);
	/*}*/
}

void MLangCodeStatementGenerator::visit(CodeConditionStatement* object) {
	std::cout << ">> CodeConditionStatement" << std::endl;

	bool has_false_block = object->false_statements()->size();
	llvm::LLVMContext& context = this->m_block->getContext();
	auto parent_function = this->m_block->getParent();
	auto true_val = llvm::ConstantInt::get(context,
			llvm::APInt(32, llvm::StringRef("0"), 10));

	llvm::BasicBlock* label_if_end = llvm::BasicBlock::Create(context, "if.end",
			parent_function, 0);
	llvm::BasicBlock* label_if_true = llvm::BasicBlock::Create(context,
			"if.then", parent_function, 0);

	llvm::BasicBlock* label_if_false = nullptr;
	if (has_false_block)
		label_if_false = llvm::BasicBlock::Create(context, "if.else",
				parent_function, 0);

	// condition
	MLangCodeStatementGenerator* gen_condition =
			new MLangCodeStatementGenerator(this->m_block);
	object->condition()->accept(gen_condition);

	llvm::CmpInst* compare_instr =
			static_cast<llvm::CmpInst*>(gen_condition->result());
	llvm::CmpInst* result_tobool = nullptr;
	if (compare_instr == nullptr)
		result_tobool = new llvm::ICmpInst(*this->m_block,
				llvm::ICmpInst::ICMP_NE, gen_condition->result(), true_val,
				"tobool");
	else
		result_tobool = compare_instr;

	if (has_false_block)
		this->m_result = llvm::BranchInst::Create(label_if_true, label_if_false,
				result_tobool, this->m_block);
	else
		this->m_result = llvm::BranchInst::Create(label_if_true, label_if_end,
				result_tobool, this->m_block);

	// true
	this->m_block = label_if_true;
	for (auto statement : *object->true_statements()) {
		MLangCodeStatementGenerator* gen_true = new MLangCodeStatementGenerator(
				this->m_block);
		statement->accept(gen_true);
		this->m_block = gen_true->block();
	}
	if (this->m_block->getTerminator() == nullptr)
		llvm::BranchInst::Create(label_if_end, this->m_block);

	// false
	if (has_false_block) {
		this->m_block = label_if_false;
		for (auto statement : *object->false_statements()) {
			MLangCodeStatementGenerator* gen_false =
					new MLangCodeStatementGenerator(this->m_block);
			statement->accept(gen_false);
			this->m_block = gen_false->block();
		}
		if (this->m_block->getTerminator() == nullptr)
			llvm::BranchInst::Create(label_if_end, this->m_block);
	}

	this->m_block = label_if_end;
}

void MLangCodeStatementGenerator::visit(CodeMethodReferenceExpression* object) {
	std::cout << ">> CodeMethodReferenceExpression" << std::endl;
}

void MLangCodeStatementGenerator::visit(CodeIterationStatement* object) {
	std::cout << ">> CodeIterationStatement" << std::endl;

	llvm::LLVMContext& context = this->m_block->getContext();
	auto parent_function = this->m_block->getParent();

	llvm::BasicBlock* label_entry = this->m_block;
	llvm::BasicBlock* label_for_end = llvm::BasicBlock::Create(context,
			"for.end", parent_function);
	llvm::BasicBlock* label_for_cond = llvm::BasicBlock::Create(context,
			"for.cond", parent_function);
	llvm::BasicBlock* label_for_body = llvm::BasicBlock::Create(context,
			"for.body", parent_function);
	llvm::BasicBlock* label_for_inc = llvm::BasicBlock::Create(context,
			"for.inc", parent_function);

	// not used??
	// llvm::BasicBlock* final_jumpblock = label_for_end;

	// label_init
	if (object->init_statement() != nullptr) {
		auto gen_init_statement = new MLangCodeStatementGenerator(label_entry);
		object->init_statement()->accept(gen_init_statement);
	}
	this->m_result = llvm::BranchInst::Create(label_for_cond, label_entry);

	// label_cond
	if (object->test_expression() != nullptr) {
		auto true_val = llvm::ConstantInt::get(context,
				llvm::APInt(32, llvm::StringRef("0"), 10));
		MLangCodeStatementGenerator* gen_condition =
				new MLangCodeStatementGenerator(label_for_cond);
		auto test_expression = object->test_expression();
		test_expression->accept(gen_condition);

		llvm::CmpInst* compare_instr =
				static_cast<llvm::CmpInst*>(gen_condition->result());
		llvm::CmpInst* result_tobool = nullptr;
		if (compare_instr == nullptr)
			result_tobool = new llvm::ICmpInst(*label_for_cond,
					llvm::ICmpInst::ICMP_NE, gen_condition->result(), true_val,
					"tobool");
		else
			result_tobool = compare_instr;

		llvm::BranchInst::Create(label_for_body, label_for_end, result_tobool,
				label_for_cond);
	} else {
		llvm::BranchInst::Create(label_for_cond, label_for_body);
	}

	// label_body
	if (object->statements()->size() > 0) {
		for (auto statement : *object->statements()) {
			MLangCodeStatementGenerator* gen_s =
					new MLangCodeStatementGenerator(label_for_body);
			statement->accept(gen_s);
		}
	}
	llvm::BranchInst::Create(label_for_inc, label_for_body);

	// label_inc
	if (object->increment_statement() != nullptr) {

		auto gen_increment_statement = new MLangCodeStatementGenerator(
				label_for_inc);
		object->increment_statement()->accept(gen_increment_statement);
	}
	llvm::BranchInst::Create(label_for_cond, label_for_inc);

	this->m_block = label_for_end;
}
