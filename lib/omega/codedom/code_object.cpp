#include <string>

#include <omega.hh>
#include <uuid/uuid.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>

namespace omega {
const std::string UserDataKind::MLANG_INFERRED_TYPE_REFERENCE =
    "MLANG_INFERRED_TYPE_REFERENCE";

const std::string UserDataKind::MLANG_RESOLVED_VARIABLE =
    "MLANG_RESOLVED_VARIABLE";
const std::string UserDataKind::MLANG_RESOLVED_TYPE =
    "MLANG_RESOLVED_TYPE_DECLARATION";
const std::string UserDataKind::MLANG_RESOLVED_METHOD =
    "MLANG_RESOLVED_MEMBER_METHOD";

const std::string UserDataKind::MLANG_RESOLVED_MEMBER_FIELD =
    "MLANG_RESOLVED_MEMBER_FIELD";
const std::string UserDataKind::MLANG_RESOLVED_VARIABLE_DECLARATION_STATEMENT =
    "MLANG_RESOLVED_VARIABLE_DECLARATION_STATEMENT";
const std::string
    UserDataKind::MLANG_RESOLVED_PARAMETER_DECLARATION_EXPRESSION =
        "MLANG_RESOLVED_PARAMETER_DECLARATION_EXPRESSION";
const std::string UserDataKind::LLVM_TYPE = "llvm_type";
const std::string UserDataKind::LLVM_L_VALUE = "llvm_l_value";
const std::string UserDataKind::LLVM_R_VALUE = "llvm_r_value";

CodeObject::CodeObject() {
  this->m_parent = nullptr;
  this->m_scope = nullptr;
  this->m_location = nullptr;
  uuid_t id;
  uuid_generate(id);
  char* str = new char[50];
  uuid_unparse(id, str);
  this->m_id = std::string(str);
}

CodeObject::~CodeObject() {}

void* CodeObject::user_data(std::string key) {
  auto res = this->m_user_data.find(key);
  if (res != this->m_user_data.end())
    return res->second;
  else
    return nullptr;
}

void CodeObject::user_data(std::string key, void* value) {
  this->m_user_data[key] = value;
}

CodeObject* CodeObject::parent() { return this->m_parent; }

void CodeObject::parent(CodeObject* parent) { this->m_parent = parent; }

bool CodeObject::type_of(CodeObjectKind kind) {
  return kind == CodeObjectKind::CodeObject;
}

CodeScope* CodeObject::scope() { return this->m_scope; }

std::string CodeObject::id() { return this->m_id; }

void CodeObject::scope(CodeScope* scope) {
  scope->push_back(this);
  this->m_scope = scope;
}

Location* CodeObject::location() { return this->m_location; }

void CodeObject::location(Location* value) { this->m_location = value; }

CodeCompileUnit* CodeObject::code_compile_unit() {
  CodeObject* current = this;
  while (!current->type_of(CodeObjectKind::CodeCompileUnit)) {
    current = current->parent();
  }

  if (current->type_of(CodeObjectKind::CodeCompileUnit))
    return static_cast<CodeCompileUnit*>(current);
  else
    return nullptr;
}
}
