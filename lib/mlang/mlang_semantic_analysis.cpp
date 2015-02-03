/*
 * mlang_semantic_analysis.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: mario
 */
#include <map>

#include "mlang_semantic_analysis.hh"
#include "mlang_dom_provider.hh"


class ResolveTypes: public CodeObjectResolver {
private:
	std::string current_namespace;
	vector<p_CompilerError>& m_errors;
	std::map<std::string, CodeTypeDeclaration*> declarations;
public:
	ResolveTypes(vector<p_CompilerError>& errors)
		: m_errors(errors)
	{
	}

	virtual ~ResolveTypes(){

	}
    virtual std::list<CodeObject*>* resolve(){
    	return nullptr;
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

	inline void visit(CodeCompileUnit* object) {
		current_namespace = "global";
		for (auto x : *object->types()) {
			x->accept(this);
		}

		for (auto x : *object->namespaces()) {
			x->accept(this);
		}

		current_namespace = "";
	}

	inline void visit(CodeNamespace* object) {
		std::string orig = current_namespace;
		if (current_namespace == "global")
			current_namespace = "global::" + object->name();
		else
			current_namespace = current_namespace + "." + object->name();

		for (auto x : *object->types()) {
			x->accept(this);
		}
		current_namespace = orig;
	}

	inline void visit(CodeTypeDeclaration* object) {
		std::string full_name = "";
		if (current_namespace == "global")
			full_name = "global::" + object->name();
		else
			full_name = current_namespace + "." + object->name();

		std::map<std::string, CodeTypeDeclaration*>::iterator it = declarations.find(full_name);
		if (it != declarations.end())
		{
			error(object, "The namespace `" + current_namespace + "' already contains a definition for `"+ object->name() +"'.");
		}
		else
		{
			declarations.insert(std::map<std::string, CodeTypeDeclaration*>::value_type(full_name, object));
		}
	}

	inline vector<p_CompilerError>& errors() {
		return this->m_errors;
	}
};


MLangSemanticAnalysis::MLangSemanticAnalysis(const MLangDomProvider& p) :
		m_provider(p) {

}

MLangSemanticAnalysis::MLangSemanticAnalysis(const MLangSemanticAnalysis& orig) :
		m_provider(orig.m_provider) {

}

MLangSemanticAnalysis::~MLangSemanticAnalysis() {

}

void MLangSemanticAnalysis::analyse(CodeCompileUnit* compile_unit) {
	ResolveTypes resolve_types(this->errors());
	compile_unit->accept(&resolve_types);
}

vector<p_CompilerError>&
MLangSemanticAnalysis::errors() {
	return this->m_errors;
}

