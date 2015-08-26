#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

#include <mlang.hh>

#include "codedom/code_object_resolver.hh"

namespace mlang {

    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }
    
    ICodeObjectResolver::ICodeObjectResolver() {
    }

    ICodeObjectResolver::~ICodeObjectResolver() {
    }


    VariableFieldOrParameterResolver::VariableFieldOrParameterResolver(CodeScope* scope, std::string name) {
        this->m_name = name;
        this->m_scope = scope;
        this->m_result = new std::list<CodeObject*>();
        this->m_tokens = split(name, '.');
        this->token_index = 0;
    }

    VariableFieldOrParameterResolver::~VariableFieldOrParameterResolver() {
    }

    std::list<CodeObject*>*
    VariableFieldOrParameterResolver::resolve() {        
        CodeScope* scope = this->m_scope;
        while (this->m_result->size() == 0 && scope != nullptr) {
            
            for (auto x : * scope->members()) {
                if (x->type_of(CodeObjectKind::CodeVariableDeclarationStatement))
                    x->accept(this);
                
                if (x->type_of(CodeObjectKind::CodeParameterDeclarationExpression))
                    x->accept(this);
                
                // for statis fields
                if (x->type_of(CodeObjectKind::CodeTypeDeclaration))
                    x->accept(this);
                
                if (x->type_of(CodeObjectKind::CodeMemberField))
                    x->accept(this);
            }
            scope = scope->parent();
        }
        
        if (this->token_index < this->m_tokens.size())
            this->m_result->clear();
        
        return this->m_result;
    }
    
    void
    VariableFieldOrParameterResolver::on_visit(CodeMemberField* object) {
        if (this->token_index >= this->m_tokens.size())
            return;
                
        if (object->name() == this->m_tokens[this->token_index]) {
            this->token_index++;
            
            this->m_result->push_back(object);
            auto type = object->resolve_type(object->type()->base_type());


            for (auto x : *type->members()) 
            {
                x->accept(this);
            }
        }
    }

    void
    VariableFieldOrParameterResolver::on_visit(CodeParameterDeclarationExpression* object) {
        if (this->token_index >= this->m_tokens.size())
            return;
                
        if (object->name() == this->m_tokens[this->token_index]) {
            this->token_index++;
            
            this->m_result->push_back(object);
            /*
            auto type = object->resolve_type(object->type());
            for (auto x : *type->members()) 
            {
                x->accept(this);
            }
            */
        }
    }

    void
    VariableFieldOrParameterResolver::on_visit(CodeVariableDeclarationStatement* object) {
        if (this->token_index >= this->m_tokens.size())
            return;
                
        if (object->name() == this->m_tokens[this->token_index]) {
            this->token_index++;
            
            this->m_result->push_back(object);

            auto type = (CodeTypeDeclaration*) object->type()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION); //object->resolve_type(object->type());
            for (auto x : *type->members()) 
            {
                x->accept(this);
            }
        }
    }

    CodeTypeDeclarationResolver::CodeTypeDeclarationResolver(CodeScope* scope, std::string name, std::string namespace_name) {
        this->m_namespace_name = namespace_name;
        this->m_name = name;
        this->m_scope = scope;
        this->m_result = new std::list<CodeObject*>();
    }

    CodeTypeDeclarationResolver::~CodeTypeDeclarationResolver() {
    }

    std::list<CodeObject*>*
    CodeTypeDeclarationResolver::resolve() {       
        CodeScope* scope = this->m_scope;
        while (this->m_result->size() == 0 && scope != nullptr) {
            for (auto x : *scope->members()) {
                x->accept(this);
            }
            scope = scope->parent();
        }
        return this->m_result;
    }

    void
    CodeTypeDeclarationResolver::on_visit(CodeCompileUnit* object) {
        for (auto x : *object->namespaces()) {
            x->accept(this);
        }

        for (auto x : *object->types()) {
        	x->accept(this);
        }
    }

    void
    CodeTypeDeclarationResolver::on_visit(CodeNamespace* object) {
        if (object->name() == this->m_namespace_name || object->name() == "") {
            for (auto x : *object->types()) {
                x->accept(this);
            }
        }
    }

    void
    CodeTypeDeclarationResolver::on_visit(CodeTypeDeclaration* object) {
        if (object->name() == this->m_name) {
            this->m_result->push_back(object);
        }
    }

    CodeMemberMethodResolver::CodeMemberMethodResolver(CodeScope* scope, std::string name, CodeTypeDeclarationCollection* parameter_types) {
    	this->m_return_type = nullptr;
    	this->m_scope = scope;
    	this->m_name = name;
    	this->m_parameter_types = parameter_types;
    	this->m_result = new std::list<CodeObject*>();
    }

    CodeMemberMethodResolver::CodeMemberMethodResolver(CodeScope* scope, CodeTypeDeclaration* return_type, std::string name, CodeTypeDeclarationCollection* parameter_types) {
    	this->m_return_type = return_type;
    	this->m_scope = scope;
    	this->m_name = name;
    	this->m_parameter_types = parameter_types;
    	this->m_result = new std::list<CodeObject*>();
    }

    CodeMemberMethodResolver::~CodeMemberMethodResolver() {

    }

    std::list<CodeObject*>*
	CodeMemberMethodResolver::resolve() {
    	CodeScope* scope = this->m_scope;
    	while (this->m_result->size() == 0 && scope != nullptr) {
    		for (auto x : *scope->members()) {
    			x->accept(this);
    		}
    		scope = scope->parent();
    	}
    	return this->m_result;
    }

    void
    CodeMemberMethodResolver::on_visit(CodeMemberMethod* object) {
    	if(object->name() == this->m_name)
    	{
    		if (this->m_return_type != nullptr)
    		{
    			auto resolved_return_type = (CodeTypeDeclaration*) object->return_type()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION); //object->resolve_type(object->return_type());
    			if (resolved_return_type != this->m_return_type)
    				return;
    		}

    		auto my_parameter_types = new CodeTypeDeclarationCollection();

    		for (auto x: *this->m_parameter_types)
    			my_parameter_types->push_back(x);

    		if (object->parameters()->size() == my_parameter_types->size()) {
    			auto object_parameters = *object->parameters();
    			CodeParameterDeclarationExpressionCollection::iterator it_object_parameters = object_parameters.begin();

    			auto types = *my_parameter_types;
    			CodeTypeDeclarationCollection::iterator it_types = types.begin();

    			bool ok = true;
    			while (ok && it_object_parameters != object_parameters.end()) {
    				auto it_object_parameter = *it_object_parameters;
    				auto it_type = *it_types;


    				auto resolved_type = (CodeTypeDeclaration*) it_object_parameter->type()->user_data(UserDataKind::MLANG_RESOLVED_TYPE_DECLARATION); //it_object_parameter->resolve_type(it_object_parameter->type());
    				ok &= ((resolved_type == it_type) || (resolved_type != nullptr && it_type != nullptr && resolved_type->name() == it_type->name()));
    				it_object_parameters++;
    				it_types++;
    			}

    			if (ok)
    				this->m_result->push_back(object);
    		}
    	}
    }
}


