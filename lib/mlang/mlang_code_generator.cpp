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

#include "compiler_error.hh"
#include "mlang_code_generator.hh"
#include "mlang_code_type_inference.hh"
#include <llvm/Assembly/Parser.h>
#include <llvm/Linker.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/IR/InlineAsm.h>

class GenerationPass: public CodeObjectVisitorBase {
private:
	std::vector<p_CompilerError>& m_errors;
public:
	GenerationPass(std::vector<p_CompilerError>& errors) :
			m_errors(errors) {
	}

	virtual ~GenerationPass() {

	}
	void error(Location* location, std::string msg) {
		p_CompilerError err = new CompilerError();
		err->location(location);
		err->message(msg);
		m_errors.push_back(err);
	}

	void error(CodeObject* object, std::string msg) {
		p_CompilerError err = new CompilerError();
		err->location(object->location());
		err->message(msg);
		m_errors.push_back(err);
	}

	inline std::vector<p_CompilerError>& errors() {
		return this->m_errors;
	}
};

class LLVMTypeGenerationPass: public GenerationPass {
private:
	llvm::Module * m_module;

protected:
	using CodeObjectVisitorBase::on_visit;
public:

	LLVMTypeGenerationPass(llvm::Module * module,
			std::vector<p_CompilerError>& errors) :
			GenerationPass(errors) {
		this->m_module = module;
	}

	virtual ~LLVMTypeGenerationPass() {

	}

	inline void on_visit(CodeCompileUnit* object) {
		for (auto x : *object->types()) {
			x->accept(this);
		}

		for (auto x : *object->namespaces()) {
			x->accept(this);
		}

		for (auto x : *object->methods()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeNamespace* object) {
		for (auto x : *object->types()) {
			x->accept(this);
		}
	}

	inline static constexpr unsigned int str2int(const char* str, int h = 0)
	{
	    return !str[h] ? 5381 : (str2int(str, h+1)*33) ^ str[h];
	}

	inline void on_visit(CodeTypeDeclaration* object) {
		llvm::LLVMContext & ctx = m_module->getContext();

		if (object->is_embedded()) {
			switch (str2int(object->name().c_str())) {
			case str2int("Int1"):
				//compile_unit->resolve_type("Int1")->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt1Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt1Ty(ctx));
				break;
			case str2int("Bool"):
				//	auto _bool = compile_unit->resolve_type("Bool");
				//  _bool->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt8Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt8Ty(ctx));
				break;
			case str2int("Char"):
				// auto _char = compile_unit->resolve_type("Char");
				// _char->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt8Ty(m_context)); // single byte char
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt8Ty(ctx));
				break;
			case str2int("SByte"):
				//	auto _sbyte = compile_unit->resolve_type("SByte");
				// _sbyte->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt8Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt8Ty(ctx));
				break;
			case str2int("Byte"):
				//	auto _byte = compile_unit->resolve_type("Byte");
				// _byte->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt8Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt8Ty(ctx));
				break;
			case str2int("Int16"):
				// 	auto _short = compile_unit->resolve_type("Int16");
				// _short->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt16Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt16Ty(ctx));
				break;
			case str2int("UInt16"):
				// 	auto _ushort = compile_unit->resolve_type("UInt16");
				// _ushort->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt16Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt16Ty(ctx));
				break;
			case str2int("Int32"):
				// 	auto _int32 = compile_unit->resolve_type("Int32");
				// _int32->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt32Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt32Ty(ctx));
				break;
			case str2int("UInt32"):
				// auto _uint32 = compile_unit->resolve_type("UInt32");
				// _uint32->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt32Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt32Ty(ctx));
				break;
			case str2int("Int64"):
				// auto _long = compile_unit->resolve_type("Int64");
				// _long->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt64Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt64Ty(ctx));
				break;
			case str2int("UInt64"):
				// 	auto _ulong = compile_unit->resolve_type("UInt64");
				// _ulong->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt64Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt64Ty(ctx));
				break;
			case str2int("Single"):
				// 	auto _float = compile_unit->resolve_type("Single");
				// _float->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getFloatTy(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getFloatTy(ctx));
				break;
			case str2int("Double"):
				// 	auto _double = compile_unit->resolve_type("Double");
				// _double->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getDoubleTy(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getDoubleTy(ctx));
				break;
			case str2int("Decimal"):
				// auto _decimal = compile_unit->resolve_type("Decimal");
				// _decimal->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getFP128Ty(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getFP128Ty(ctx));
				break;
			case str2int("IntPtr"):
				// auto _intptr = compile_unit->resolve_type("IntPtr");
				// _intptr->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getInt64PtrTy(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getInt64PtrTy(ctx));
				break;
			case str2int("Void"):
				// 	auto _void = compile_unit->resolve_type("Void");
				// _void->user_data(UserDataKind::LLVM_TYPE, llvm::Type::getVoidTy(m_context));
				object->user_data(UserDataKind::LLVM_TYPE,
						llvm::Type::getVoidTy(ctx));
				break;
			case str2int("Array"):
				object->user_data(UserDataKind::LLVM_TYPE, nullptr);
				break;
			}
		} else if (object->is_struct()) {
			std::string struct_name = object->name();
			llvm::StructType * struct_type = llvm::StructType::create(ctx, struct_name);

			object->user_data(UserDataKind::LLVM_TYPE, struct_type);

		} else if (object->is_class()) {
			std::string class_name = object->name();
			llvm::StructType * class_type = llvm::StructType::create(ctx, class_name);
			object->user_data(UserDataKind::LLVM_TYPE, class_type);
		}
	}
};

class LLVMMethodPrototypeGenerationPass: public GenerationPass {
private:
	llvm::Module * m_module;

protected:
	using CodeObjectVisitorBase::on_visit;
public:

	llvm::Type*
	get_llvm_type(CodeTypeReference* code_type_reference) {
		llvm::Type* ret = nullptr;
		CodeTypeDeclaration* code_type_declaration = (CodeTypeDeclaration*)code_type_reference->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);

		// the type should be in LLVM_TYPE only for the type ARRAY this is not the case, unless it has been resolved before.
		if (code_type_declaration->user_data(UserDataKind::LLVM_TYPE) == nullptr)
		{
			if (code_type_declaration->is_embedded() && code_type_declaration->name() == "Array")
			{
				if (code_type_reference->array_element_type() != nullptr)
				{
					llvm::Type* element_type = get_llvm_type(code_type_reference->array_element_type());
					ret = llvm::PointerType::get(element_type, 0);
				}

				code_type_declaration->user_data(UserDataKind::LLVM_TYPE, ret);
			}
			else if (code_type_declaration->is_class())
			{
				ret = llvm::PointerType::get(ret, 0);
			}
			else
			{
				// throw some exception, because only Array can be an unknown type at this point.
			}
		}
		else
		{
			ret = (llvm::Type*)code_type_declaration->user_data(UserDataKind::LLVM_TYPE);
		}

		return ret;
	}

	LLVMMethodPrototypeGenerationPass(llvm::Module * module,
			std::vector<p_CompilerError>& errors) :
			GenerationPass(errors) {
		this->m_module = module;
	}

	virtual ~LLVMMethodPrototypeGenerationPass() {

	}

	inline void on_visit(CodeCompileUnit* object) {
		for (auto x : *object->namespaces()) {
			x->accept(this);
		}

		for (auto x : *object->types()) {
			x->accept(this);
		}

		for (auto x : *object->methods()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeNamespace* object) {
		for (auto x : *object->types()) {
			x->accept(this);
		}

		for (auto x : *object->methods()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeTypeDeclaration* object) {
		for (auto x : *object->members()) {
			x->accept(this);
		}
	}

	inline void on_visit(CodeMemberMethod* object) {
		llvm::Type* result_type = get_llvm_type(object->return_type()); //  static_cast<llvm::Type*>(t->user_data(UserDataKind::LLVM_TYPE));

		std::vector<llvm::Type*> param_types;
		if (object->parameters()->size() > 0) {
			for (auto p : *object->parameters()) {
				auto llvm_type = get_llvm_type(p->type());
				param_types.push_back(llvm_type);
			}
		}

		llvm::FunctionType * function_type = llvm::FunctionType::get(result_type, param_types, false);

		if (object->name() == "main" || object->name() == "_start")
			object->attributes(MemberAttributes::Public);

		std::string method_name = object->id();
		auto function = llvm::Function::Create(function_type, llvm::GlobalValue::LinkageTypes::ExternalLinkage, method_name, m_module);
	}
};

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
	llvm::Module * module = new llvm::Module("in_memory_module", m_context);
	module->setDataLayout(
			"e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128");
	module->setTargetTriple("x86_64-unknown-linux-gnu");

	std::vector<p_CompilerError> err;
	LLVMTypeGenerationPass type_generator(module, err);
	compile_unit->accept(&type_generator);


	LLVMMethodPrototypeGenerationPass method_prototype_generator(module, err);
	compile_unit->accept(&method_prototype_generator);

	for (auto code_type_declaration : *compile_unit->types()) {
		auto bblock = llvm::BasicBlock::Create(m_context,
				code_type_declaration->name(), 0, 0);
		auto gen = new MLangCodeStatementGenerator(bblock);
		code_type_declaration->accept(gen);
	}

	for (auto code_member_method : *compile_unit->methods()) {
		CreateFunction(module, code_member_method);
	}

	for (auto code_namespace : *compile_unit->namespaces()) {
		for (auto code_type_declaration : *code_namespace->types()) {
			auto bblock = llvm::BasicBlock::Create(m_context,
					code_type_declaration->name(), 0, 0);
			auto gen = new MLangCodeStatementGenerator(bblock);
			code_type_declaration->accept(gen);
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

	auto obj_type_decl = (CodeTypeDeclaration*) obj_type->user_data(
			UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION); //obj->resolve_type(obj_type);

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

	/*
	auto function_type = GetFunctionType(method->return_type(),
			method->parameters(), false);

	if (method->name() == "main" || method->name() == "_start")
		method->attributes(MemberAttributes::Public);
*/
	std::string method_name = method->id();
	auto function = module->getFunction(method_name);
			/*
			llvm::Function::Create(function_type,
			llvm::GlobalValue::LinkageTypes::ExternalLinkage, method_name,
			module);*/

	if (method->attributes() != MemberAttributes::External) {
		auto bblock = llvm::BasicBlock::Create(m_context, "entry", function, 0);

		llvm::Function::arg_iterator args = function->arg_begin();

		for (auto p : *method->parameters()) {
			llvm::Value* paramter_input = args++;
			paramter_input->setName(p->name());

			auto parameter_gen = new MLangCodeStatementGenerator(bblock);
			p->accept(parameter_gen);
			auto parameter_input_addr =
					(llvm::AllocaInst*) parameter_gen->result();

			//auto td = method->resolve_type(p->type());
			parameter_input_addr->setName(p->name() + ".addr");
			//llvm::StoreInst* void_15 =
			new llvm::StoreInst(paramter_input, parameter_input_addr, false,
					bblock);
		}

		if (method->statements() != nullptr) {
			for (auto statement : *method->statements()) {
				auto statement_gen = new MLangCodeStatementGenerator(bblock);
				statement->accept(statement_gen);
				//not used
				//auto statement_res = statement_gen.result();
				bblock = statement_gen->block();
			}
		}
	}

	for (auto attribute : method->custom_attributes()) {
		if (attribute->name() == "Inline"
				&& attribute->arguments().size() == 0) {
			function->addFnAttr(llvm::Attribute::InlineHint);
			function->setLinkage(llvm::GlobalValue::PrivateLinkage);
		}
	}

	return function;
}

llvm::Type*
MLangCodeGenerator::get_llvm_type(CodeTypeReference* code_type_reference) {
	llvm::Type* ret = nullptr;
		CodeTypeDeclaration* code_type_declaration = (CodeTypeDeclaration*)code_type_reference->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);

		if (code_type_declaration->user_data(UserDataKind::LLVM_TYPE) == nullptr)
		{
			// the type should be in LLVM_TYPE only for the type ARRAY this is not the case, unless it has been resolved before.
			if (code_type_declaration->is_embedded() && code_type_declaration->name() == "Array")
			{
				if (code_type_reference->array_element_type() != nullptr)
				{
					llvm::Type* element_type = get_llvm_type(code_type_reference->array_element_type());
					ret = llvm::PointerType::get(element_type, 0);
				}

				code_type_declaration->user_data(UserDataKind::LLVM_TYPE, ret);
			}
			else
			{
				// throw some exception, because only Array can be an unknown type at this point.
			}
		}
		else
		{
			ret = (llvm::Type*)code_type_declaration->user_data(UserDataKind::LLVM_TYPE);
		}

		if (code_type_declaration->is_class())
		{
			ret = llvm::PointerType::get((llvm::Type*)code_type_declaration->user_data(UserDataKind::LLVM_TYPE), 0);
		}

		return ret;
}

llvm::FunctionType* MLangCodeGenerator::GetFunctionType(
		CodeTypeReference* code_type_reference,
		CodeParameterDeclarationExpressionCollection* params,
		bool is_var_args) {

	llvm::Type* result_type = get_llvm_type(code_type_reference);

	std::vector<llvm::Type*> param_types;
	if (params->size() > 0) {
		for (auto p : *params) {
			auto llvm_type = get_llvm_type(p->type());
			param_types.push_back(llvm_type);
		}
	}

	llvm::FunctionType * ret = llvm::FunctionType::get(result_type, param_types,
			is_var_args);
	return ret;
}

llvm::Type*
MLangCodeStatementGenerator::get_llvm_type(CodeTypeReference* code_type_reference) {
	llvm::Type* ret = nullptr;
			CodeTypeDeclaration* code_type_declaration = (CodeTypeDeclaration*)code_type_reference->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);

			if (code_type_declaration->user_data(UserDataKind::LLVM_TYPE) == nullptr)
			{
				// the type should be in LLVM_TYPE only for the type ARRAY this is not the case, unless it has been resolved before.
				if (code_type_declaration->is_embedded() && code_type_declaration->name() == "Array")
				{
					if (code_type_reference->array_element_type() != nullptr)
					{
						llvm::Type* element_type = get_llvm_type(code_type_reference->array_element_type());
						ret = llvm::PointerType::get(element_type, 0);
					}

					code_type_declaration->user_data(UserDataKind::LLVM_TYPE, ret);
				}
				else
				{
					// throw some exception, because only Array can be an unknown type at this point.
				}
			}
			else
			{
				ret = (llvm::Type*)code_type_declaration->user_data(UserDataKind::LLVM_TYPE);
			}

			if (code_type_declaration->is_class())
			{
				ret = llvm::PointerType::get(ret, 0);
			}

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

void MLangCodeStatementGenerator::on_visit(CodeBinaryOperatorExpression* object) {
	// // std::cout << ">> CodeBinaryOperatorExpression" << std::endl;
	llvm::LLVMContext& ctx = this->m_block->getContext();
	llvm::Constant *zero = llvm::Constant::getNullValue(
			llvm::IntegerType::getInt32Ty(ctx));

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
		auto expression_gen_left = new MLangCodeStatementGenerator(
				this->m_block);
		expression_left->accept(expression_gen_left);
		expression_left_value = expression_gen_left->result();
		expression_left_value = load_if_needed(expression_left,
				expression_left_value, this->m_block);
		method_args.push_back(expression_left_value);
	}

	if (expression_right != nullptr) {
		auto expression_gen_right = new MLangCodeStatementGenerator(
				this->m_block);
		expression_right->accept(expression_gen_right);
		expression_right_value = expression_gen_right->result();
		expression_right_value = load_if_needed(expression_right,
				expression_right_value, this->m_block);
		method_args.push_back(expression_right_value);
	}

	CodeMemberMethod * resolved_method =  (CodeMemberMethod *)object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_METHOD);
	llvm::Function* f = mod->getFunction(resolved_method->id());
	switch (object->operator_()) {
	case CodeBinaryOperatorType::Add:
	case CodeBinaryOperatorType::Divide:
	case CodeBinaryOperatorType::Subtract:
	case CodeBinaryOperatorType::Multiply:
	case CodeBinaryOperatorType::Modulus:
	case CodeBinaryOperatorType::ShiftLeft:
	case CodeBinaryOperatorType::ShiftRight:
	case CodeBinaryOperatorType::BitwiseOr:
	case CodeBinaryOperatorType::BooleanOr:
	case CodeBinaryOperatorType::BitwiseAnd:
	case CodeBinaryOperatorType::BooleanAnd:
	case CodeBinaryOperatorType::ExlusiveOr:
	case CodeBinaryOperatorType::IdentityEquality:
	case CodeBinaryOperatorType::IdentityInEquality:
	case CodeBinaryOperatorType::LessThan:
	case CodeBinaryOperatorType::LessThanOrEqual:
	case CodeBinaryOperatorType::GreaterThan:
	case CodeBinaryOperatorType::GreaterThanOrEqual:
		this->m_result = llvm::CallInst::Create(f, method_args, "",
						this->m_block);
		break;
	}
}

void MLangCodeStatementGenerator::on_visit(CodeCompileUnit* object) {
	// std::cout << ">> CodeCompileUnit" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeExpression* object) {
	// std::cout << ">> CodeExpression" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeMemberField* object) {
	// std::cout << ">> CodeMemberField" << std::endl;

}

void MLangCodeStatementGenerator::on_visit(CodeMemberMethod* object) {
	// std::cout << ">> CodeMemberMethod" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeMemberProperty* object) {
	// std::cout << ">> CodeMemberProperty" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeMethodReturnStatement* object) {
	// std::cout << ">> CodeMethodReturnStatement" << std::endl;
	auto expression = object->expression();
	if (expression != nullptr) {
		auto expression_gen = new MLangCodeStatementGenerator(this->m_block);
		expression->accept(expression_gen);
		auto return_val = expression_gen->result();
		return_val = load_if_needed(expression, return_val, this->m_block);

		m_result = llvm::ReturnInst::Create(this->m_block->getContext(),
				return_val, m_block);
	} else {
		// return void
		m_result = llvm::ReturnInst::Create(this->m_block->getContext(),
				m_block);
	}
}

void MLangCodeStatementGenerator::on_visit(CodeNamespace* object) {
	// std::cout << ">> CodeNamespace" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeObject* object) {
	// std::cout << ">> CodeObject" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(
		CodeParameterDeclarationExpression* object) {
	auto llvm_type = get_llvm_type(object->type());
	auto name = object->name();
	llvm::AllocaInst *alloc = new llvm::AllocaInst(llvm_type, name.c_str(), this->m_block);
	object->user_data(UserDataKind::LLVM_L_VALUE, alloc);
	this->m_result = alloc;
}

void MLangCodeStatementGenerator::on_visit(CodePrimitiveExpression* object) {
	// std::cout << ">> CodePrimitiveExpression" << std::endl;

	auto module = this->m_block->getParent()->getParent();
	llvm::LLVMContext& ctx = this->m_block->getContext();

	//auto type_reference = object->type();

	CodeTypeDeclaration * td = (CodeTypeDeclaration*) object->type()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	llvm::Type * type = get_llvm_type(object->type());
			//static_cast<llvm::Type*>(td->user_data(
			//UserDataKind::LLVM_TYPE)); //td->llvm_type();

	if (td->name() == "Int32") {
		uint64_t v = (uint64_t) (uint64_t*) object->value();
		m_result = llvm::ConstantInt::get(
				llvm::Type::getInt32Ty(m_block->getContext()), v, true);
	}

	if (td->is_embedded() && object->type()->base_type() == "Array"
			&& object->type()->array_element_type()->base_type() == "Char") {
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

	// std::cout << "<< CodePrimitiveExpression" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeStatement* object) {
	// std::cout << ">> CodeStatement" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeTypeDeclaration* object) {
	llvm::LLVMContext& ctx = this->m_block->getContext();
	//auto module = this->m_block->getParent()->getParent();

	if (object->is_embedded()) {

	} else if (object->is_struct()) {
		llvm::StructType * struct_type = (llvm::StructType*)object->user_data(UserDataKind::LLVM_TYPE);

		std::vector<llvm::Type*> struct_type_fields;
		for (auto field_decl : *object->members()) {
			CodeMemberField * field = static_cast<CodeMemberField*>(field_decl);
			if (field != nullptr) {
				llvm::Type * field_type = get_llvm_type(field->type());
				struct_type_fields.push_back(field_type);
			}
		}

		if (struct_type_fields.size() >  0 && struct_type->isOpaque()) {
			struct_type->setBody(struct_type_fields, /*isPacked=*/false);
		}

	} else if (object->is_class()) {
		llvm::StructType * struct_type = (llvm::StructType*)object->user_data(UserDataKind::LLVM_TYPE);

		std::vector<llvm::Type*> class_type_fields;
		for (auto field_decl : *object->members()) {
			CodeMemberField * field = static_cast<CodeMemberField*>(field_decl);
			if (field != nullptr) {
				llvm::Type * field_type = get_llvm_type(field->type());
				class_type_fields.push_back(field_type);
			}
		}

		if (class_type_fields.size() > 0 &&  struct_type->isOpaque()) {
			struct_type->setBody(class_type_fields, /*isPacked=*/false);
		}
	}
}

void MLangCodeStatementGenerator::on_visit(CodeTypeMember* object) {
	// std::cout << ">> CodeTypeMember" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeTypeReference* object) {
	// std::cout << ">> CodeTypeReference" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(
		CodeVariableDeclarationStatement* object) {
	// find out the llvm type for a single instance of the type
	auto llvm_type = get_llvm_type(object->type()); // static_cast<llvm::Type*>(type_declaration->user_data(UserDataKind::LLVM_TYPE)); //resolved->llvm_type();

	// if its a array_type_reference we should declare a pointer
	auto name = object->name();
	llvm::AllocaInst *alloc = new llvm::AllocaInst(llvm_type, name.c_str(), this->m_block);
	object->user_data(UserDataKind::LLVM_L_VALUE, alloc);
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
}

void MLangCodeStatementGenerator::on_visit(
		CodeVariableReferenceExpression* object) {
	CodeObject* resolved_variable_reference = nullptr;

	if (nullptr != object->user_data(UserDataKind::MLANG_RESOLVED_VARIABLE_DECLARATION_STATEMENT))
		resolved_variable_reference = (CodeObject*)object->user_data(UserDataKind::MLANG_RESOLVED_VARIABLE_DECLARATION_STATEMENT);

	if (nullptr != object->user_data(UserDataKind::MLANG_RESOLVED_PARAMETER_DECLARATION_EXPRESSION))
		resolved_variable_reference = (CodeObject*)object->user_data(UserDataKind::MLANG_RESOLVED_PARAMETER_DECLARATION_EXPRESSION);

	if (nullptr != object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_FIELD))
		resolved_variable_reference = (CodeObject*)object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_FIELD);

	if (resolved_variable_reference == nullptr)
		return;

	if (resolved_variable_reference->type_of(CodeObjectKind::CodeVariableDeclarationStatement))
	{
		llvm::Value * value = static_cast<llvm::Value*>(resolved_variable_reference->user_data(UserDataKind::LLVM_L_VALUE));
		this->m_result = value;
	}

	if (resolved_variable_reference->type_of(CodeObjectKind::CodeParameterDeclarationExpression))
	{
		llvm::Value * value = static_cast<llvm::Value*>(resolved_variable_reference->user_data(UserDataKind::LLVM_L_VALUE));
		this->m_result = value;
	}
}

void MLangCodeStatementGenerator::on_visit(CodeCastExpression* object) {
	// std::cout << ">> CodeCastExpression" << std::endl;

	llvm::LLVMContext& ctx = this->m_block->getContext();
	llvm::Constant *zero = llvm::Constant::getNullValue(
			llvm::IntegerType::getInt32Ty(ctx));

	llvm::Function* parent_function = this->m_block->getParent();
	llvm::Module* mod = parent_function->getParent();

	std::list<CodeTypeDeclaration*> method_arg_types;
	std::vector<llvm::Value*> method_args;

	// infer the type of the target_expression
	MLangCodeTypeInference type_inf;
	object->expression()->accept(&type_inf);
	auto expression_type = type_inf.result();
	auto expression_type_decl =
			(CodeTypeDeclaration*) expression_type->user_data(
					UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION); //object->resolve_type(expression_type);
	method_arg_types.push_back(expression_type_decl);

	// I'll need the return type of the method to resolve
	CodeTypeDeclaration* td_return =
			(CodeTypeDeclaration*) object->target_type()->user_data(
					UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION); //object->resolve_type(
	//object->target_type());

	std::string method_name = "cast";
	auto resolved_method = object->resolve_method(method_name, td_return,
			&method_arg_types);

	// generate the code for the target_expression
	auto tp_gen = new MLangCodeStatementGenerator(this->m_block);
	object->expression()->accept(tp_gen);
	auto expression_value = tp_gen->result();

	// prepare a list of parameters i need to pass to the target method
	expression_value = load_if_needed(object->expression(), expression_value,
			this->m_block);

	if (resolved_method != nullptr) {
		method_args.push_back(expression_value);
		auto f = mod->getFunction(resolved_method->id());
		this->m_result = llvm::CallInst::Create(f, method_args, "",
				this->m_block);
	} else {
		auto create_type = static_cast<llvm::Type*>(td_return->user_data(
				UserDataKind::LLVM_TYPE));
		this->m_result = new llvm::BitCastInst(expression_value, create_type,
				"", this->m_block);
	}
}

void MLangCodeStatementGenerator::on_visit(CodeObjectCreateExpression* object) {
	// std::cout << ">> CodeObjectCreateExpression" << std::endl;
	auto resolved = (CodeTypeDeclaration*) object->create_type()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION); //object->resolve_type(object->create_type());

	if (resolved->is_class()) {
		auto create_type = (llvm::PointerType*)get_llvm_type(object->create_type());
		auto element_type = (llvm::Type*)resolved->user_data(UserDataKind::LLVM_TYPE);

		auto module = this->m_block->getParent()->getParent();
		llvm::LLVMContext& context = module->getContext();

		llvm::DataLayout l = llvm::DataLayout(module);
		llvm::ConstantInt* const_int64_14 = llvm::ConstantInt::get(context, llvm::APInt(64, l.getTypeAllocSize(element_type)));

		llvm::Function* func_malloc = module->getFunction("malloc");
		llvm::CallInst* ptr_19 = llvm::CallInst::Create(func_malloc, const_int64_14, "", this->m_block);
		this->m_result = new llvm::BitCastInst(ptr_19, create_type, "", this->m_block);
	} else {
		this->m_result = nullptr;
	}
}

void MLangCodeStatementGenerator::on_visit(CodeFileInclude* object) {
	// std::cout << ">> CodeFileImport" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeFieldReferenceExpression* object) {
	MLangCodeStatementGenerator target_object_gen(this->m_block);
	object->target_object()->accept(&target_object_gen);
	llvm::Value* target_object_l_value = target_object_gen.result();

	CodeTypeDeclaration* target_object_type_declaration = (CodeTypeDeclaration*)object->target_object()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);
	if (target_object_type_declaration->is_class())
	{
		target_object_l_value = new llvm::LoadInst(target_object_l_value, "", this->m_block);
	}

	int index = 0;
	for (auto x : *target_object_type_declaration->members()) {
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

	this->m_result = llvm::GetElementPtrInst::Create(target_object_l_value, ptr_a_indices, object->field_name(), this->m_block);
}

void MLangCodeStatementGenerator::on_visit(CodeArrayIndexerExpression* object) {
	// std::cout << ">> CodeArrayIndexerExpression" << std::endl;

	auto m_func = this->m_block->getParent();
	auto m_module = m_func->getParent();
	llvm::LLVMContext & m_context = m_module->getContext();

	static llvm::Constant *zero = llvm::Constant::getNullValue(
			llvm::IntegerType::getInt32Ty(m_context));

	MLangCodeStatementGenerator * target_object_gen =
			new MLangCodeStatementGenerator(this->m_block);
	object->target_object()->accept(target_object_gen);
	llvm::Value* ptr_29 = target_object_gen->result();

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

void MLangCodeStatementGenerator::on_visit(CodeArrayCreateExpression* object) {
	// std::cout << ">> CodeArrayCreateExpression" << std::endl;

	auto m_func = this->m_block->getParent();
	auto m_module = m_func->getParent();
	llvm::LLVMContext & m_context = m_module->getContext();

	auto resolved = (CodeTypeDeclaration*) object->create_type()->user_data(
			UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION);

	//auto resolved = object->resolve_type(object->create_type());
	auto llvm_type = static_cast<llvm::Type*>(resolved->user_data(
			UserDataKind::LLVM_TYPE)); //resolved->llvm_type();

	if (object->create_type()->array_element_type() != nullptr)
		llvm_type = llvm::PointerType::get(llvm_type, 0);

	MLangCodeStatementGenerator * size_gen = new MLangCodeStatementGenerator(
			this->m_block);
	object->size_expression()->accept(size_gen);
	llvm::Value* size_expression = size_gen->result();

	size_expression = load_if_needed(object->size_expression(), size_expression,
			this->m_block);
	auto alloca = new llvm::AllocaInst(llvm_type, size_expression, "",
			this->m_block);
	this->m_result = alloca;

	auto func_malloc = m_module->getOrInsertFunction("malloc",
			get_malloc_functiontype(m_module));
	llvm::CallInst* ptr_55 = llvm::CallInst::Create(func_malloc,
			size_expression, "", this->m_block);
	this->m_result = ptr_55;
}

void MLangCodeStatementGenerator::on_visit(CodeSizeOfExpression* object) {
	auto m_func = this->m_block->getParent();
	auto m_module = m_func->getParent();
	llvm::LLVMContext & m_context = m_module->getContext();

	auto resolved = (CodeTypeDeclaration*) object->type()->user_data(
			UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION); // object->resolve_type(object->type());
	auto create_type = static_cast<llvm::Type*>(resolved->user_data(
			UserDataKind::LLVM_TYPE)); //resolved->llvm_type();

	if (create_type->isPointerTy())
		create_type = ((llvm::PointerType*) create_type)->getElementType();

	llvm::DataLayout l = llvm::DataLayout(m_module);
	llvm::ConstantInt* const_int64_14 = llvm::ConstantInt::get(m_context,
			llvm::APInt(64, l.getTypeAllocSize(create_type), /* isSigned = */
			false));
	this->m_result = const_int64_14;
}

void MLangCodeStatementGenerator::on_visit(CodeAssemblyCallExpression* object) {
	// std::cout << ">> CodeAsmBlockStatement" << std::endl;

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
		auto par_type = (CodeTypeDeclaration*) type_inf.result()->user_data(
				UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION); //object->resolve_type(type_inf.result());
		parameter_types.push_back(par_type);
		llvm::Type* tp = static_cast<llvm::Type*>(par_type->user_data(
				UserDataKind::LLVM_TYPE)); //par_type->llvm_type()
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

	// std::cout << "<< CodeAsmBlockStatement" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeIrBlockStatement* object) {
	// std::cout << ">> CodeIrBlockStatement" << std::endl;

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
				auto l_value = static_cast<llvm::Value*>(var->user_data(UserDataKind::LLVM_L_VALUE)); //
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

				auto l_value = static_cast<llvm::Value*>(var->user_data(UserDataKind::LLVM_L_VALUE)); //
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

	auto s = stream.str().c_str();
	llvm::SMDiagnostic err;
	auto m = llvm::ParseAssemblyString(s, m_module, err,
			m_context);

	std::string errstr = err.getMessage();
	if (errstr != "")
		std::cout << "can't parse inline LLVM IR:\n"
				<< err.getLineContents().str().c_str() << "\n"
				<< (std::string(err.getColumnNo(), ' ') + '^').c_str()
				<< errstr.c_str() << "\nThe input string was: \n"
				<< stream.str().c_str();

	std::string errstr2 = "";
	if (m_module != m)
	{
		llvm::Linker(m_module).linkInModule(m, &errstr2);
	}

	llvm::Function* fun = m_module->getFunction("_" + object->id());
	fun->setLinkage(llvm::GlobalValue::LinkOnceODRLinkage);
	fun->addFnAttr(llvm::Attribute::AlwaysInline);
	this->m_result = llvm::CallInst::Create(fun, params, "", this->m_block);
}

void MLangCodeStatementGenerator::on_visit(CodeAssignExpression* object) {
	// std::cout << ">> CodeAssignExpression" << std::endl;

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
							static_cast<llvm::Value*>(code_variable_declaration_statement->user_data(
									UserDataKind::LLVM_L_VALUE)); //code_variable_declaration_statement->alloca_inst();
				}

				if (part->type_of(
						CodeObjectKind::CodeParameterDeclarationExpression)) {
					CodeParameterDeclarationExpression* code_parameter_declaration_statement =
							static_cast<CodeParameterDeclarationExpression*>(part);
					left =
							static_cast<llvm::Value*>(code_parameter_declaration_statement->user_data(
									UserDataKind::LLVM_L_VALUE)); //code_parameter_declaration_statement->alloca_inst();
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
	// std::cout << "<< CodeAssignExpression" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeExpressionStatement* object) {
	// std::cout << ">> CodeExpressionStatement" << std::endl;

	MLangCodeStatementGenerator * gen = new MLangCodeStatementGenerator(
			this->m_block);
	object->expression()->accept(gen);
	m_result = gen->result();

	m_result = load_if_needed(object->expression(), m_result, this->m_block); // new llvm::LoadInst(m_result, "", this->m_block);
}

void MLangCodeStatementGenerator::on_visit(CodeMethodInvokeExpression* object) {
	// std::cout << ">> CodeMethodInvokeExpression" << std::endl;

	auto parent_function = this->m_block->getParent();
	auto module = parent_function->getParent();
	llvm::LLVMContext& ctx = module->getContext();

	std::vector<llvm::Value*> args;
	if (object->method()->target_object() != nullptr) {
		MLangCodeStatementGenerator * p_gen = new MLangCodeStatementGenerator(this->m_block);
		object->method()->target_object()->accept(p_gen);
		auto res = p_gen->result();
		res = load_if_needed(object->method()->target_object(), res,this->m_block);
		args.push_back(res);
	}

	for (auto p_arg : *object->parameters()) {
		MLangCodeStatementGenerator * p_gen = new MLangCodeStatementGenerator(this->m_block);
		p_arg->accept(p_gen);
		auto res = p_gen->result();
		res = load_if_needed(p_arg, res, this->m_block);
		args.push_back(res);
	}

	auto resolved_method = (CodeMemberMethod*) object->user_data(UserDataKind::MLANG_RESOLVED_MEMBER_METHOD);
	llvm::Function* f = nullptr;
	f = module->getFunction(resolved_method->id());
	this->m_result = llvm::CallInst::Create(f, args, "", this->m_block);
}

void MLangCodeStatementGenerator::on_visit(CodeConditionStatement* object) {
	// std::cout << ">> CodeConditionStatement" << std::endl;

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

void MLangCodeStatementGenerator::on_visit(
		CodeMethodReferenceExpression* object) {
	// std::cout << ">> CodeMethodReferenceExpression" << std::endl;
}

void MLangCodeStatementGenerator::on_visit(CodeAttributeArgument* object) {

}

void MLangCodeStatementGenerator::on_visit(CodeAttributeDeclaration* object) {

}

void MLangCodeStatementGenerator::on_visit(CodeIterationStatement* object) {
	// std::cout << ">> CodeIterationStatement" << std::endl;

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
