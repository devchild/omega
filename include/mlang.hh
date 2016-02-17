/*
 * File:   mlang.hh
 * Author: mario
 *
 * Created on June 23, 2014, 11:09 PM
 */

#ifndef MLANG_HH
#define MLANG_HH

#include "argvparser.hh"
#include "compiler_error.hh"
#include "compiler_parameters.hh"
#include "compiler_results.hh"
#include "linker.hh"
#include "code_compiler.hh"
#include "code_generator.hh"
#include "code_parser.hh"
#include "code_type_inference.hh"
#include "dom_provider.hh"
#include "semantic_analysis.hh"
#include "code_resolver.hh"
#include "pstream.hh"

//
// codedom/*
//
#include "codedom/code_object_visitor.hh"
#include "codedom/code_assign_expression.hh"
#include "codedom/code_array_create_expression.hh"
#include "codedom/code_compile_unit.hh"
#include "codedom/code_expression.hh"
#include "codedom/code_member_field.hh"
#include "codedom/code_member_method.hh"
#include "codedom/code_member_property.hh"
#include "codedom/code_namespace.hh"
#include "codedom/code_object.hh"
#include "codedom/code_object_collections.hh"
#include "codedom/code_type_declaration.hh"
#include "codedom/code_type_member.hh"
#include "codedom/code_type_reference.hh"
#include "codedom/code_statement.hh"
#include "codedom/code_parameter_declaration_expression.hh"
#include "codedom/code_type_declaration.hh"
#include "codedom/code_variable_declaration_statement.hh"
#include "codedom/code_binary_operator_expression.hh"
#include "codedom/code_variable_reference_expression.hh"
#include "codedom/code_primitive_expression.hh"
#include "codedom/code_cast_expression.hh"
#include "codedom/code_method_return_statement.hh"
#include "codedom/code_method_invoke_expression.hh"
#include "codedom/code_method_reference_expression.hh"
#include "codedom/code_expression_statement.hh"
#include "codedom/code_condition_statement.hh"
#include "codedom/code_iteration_statement.hh"
#include "codedom/code_scope.hh"
#include "codedom/code_object_create_expression.hh"
#include "codedom/code_ir_block_statement.hh"
#include "codedom/code_file_include.hh"
#include "codedom/code_array_indexer_expression.hh"
#include "codedom/code_field_reference_expression.hh"
#include "codedom/code_assembly_call_expression.hh"
#include "codedom/code_size_of_expression.hh"
#include "codedom/code_attribute_argument.hh"
#include "codedom/code_attribute_declaration.hh"

#endif /* MLANG_HH */