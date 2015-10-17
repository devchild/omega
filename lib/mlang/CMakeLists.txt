configure_file(config.h.in "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)

#
# Generate the parser using flex and bison
#
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/parser)
FIND_PACKAGE(FLEX REQUIRED)
SET(FlexOutput ${CMAKE_CURRENT_BINARY_DIR}/parser/mlang_scanner.cpp)
IF(FLEX_FOUND)
    ADD_CUSTOM_COMMAND(
      OUTPUT ${FlexOutput}
      COMMAND ${FLEX_EXECUTABLE}
              --outfile=${FlexOutput}
              ${CMAKE_CURRENT_SOURCE_DIR}/parser/mlang_scanner.ll
      COMMENT "Generating mlang_scanner.cpp"
      DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/parser/mlang_scanner.ll
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
ENDIF()
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/parser/mlang_scanner.cpp GENERATED)

FIND_PACKAGE(BISON REQUIRED)
SET(BisonOutput ${CMAKE_CURRENT_BINARY_DIR}/parser/mlang_parser.cpp)
SET(BisonOutputHeader ${CMAKE_CURRENT_BINARY_DIR}/parser/mlang_parser.hh)
IF(BISON_FOUND)
    ADD_CUSTOM_COMMAND(
      OUTPUT ${BisonOutput}
      COMMAND ${BISON_EXECUTABLE}
              --defines=${BisonOutputHeader}
              --output=${BisonOutput}
              ${CMAKE_CURRENT_SOURCE_DIR}/parser/mlang_parser.yy
      COMMENT "Generating mlang_parser.cpp"
      DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/parser/mlang_parser.yy
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
ENDIF()
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/parser/mlang_parser.cpp GENERATED)
SET_SOURCE_FILES_PROPERTIES(${FlexOutput} PROPERTIES OBJECT_DEPENDS ${BisonOutputHeader})

set(PROJECT_FILES
    ${PROJECT_FILES}

    # ./codedom
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_array_create_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_array_indexer_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_assembly_call_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_assign_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_attribute_argument.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_attribute_declaration.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_binary_operator_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_cast_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_compile_unit.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_condition_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_expression_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_field_reference_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_file_import.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_ir_block_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_iteration_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_member_field.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_member_method.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_member_property.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_method_invoke_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_method_reference_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_method_return_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_namespace.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_object.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_object_create_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_object_visitor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_parameter_declaration_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_primitive_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_scope.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_size_of_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_type_declaration.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_type_member.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_type_reference.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_variable_declaration_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codedom/code_variable_reference_expression.cpp

    # ./
    ${CMAKE_CURRENT_SOURCE_DIR}/argvparser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/linker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/compiler_error.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/compiler_parameters.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/compiler_results.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/code_compiler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/code_generator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/code_parser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/code_type_inference.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dom_provider.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/semantic_analysis.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/code_resolver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in

    # ./../../include/
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/argvparser.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/linker.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/mlang.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/compiler_error.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/compiler_parameters.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/compiler_results.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/file_system.hh
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include/code_compiler.hh
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include/code_generator.hh
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include/code_parser.hh
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include/code_type_inference.hh
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include/dom_provider.hh
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include/semantic_analysis.hh
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include/code_resolver.hh

    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/pstream.hh
    ${CMAKE_CURRENT_BINARY_DIR}/config.h

    # ./parser/
    ${CMAKE_CURRENT_SOURCE_DIR}/parser/mlang_driver.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/parser/mlang_driver.cpp
    ${BisonOutput}
    ${FlexOutput}
 )

include_directories("/opt/local/include/")
include_directories("/usr/local/include/")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/parser)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include/)

#
# include directories in the build directory
#
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/parser)

add_library(libmlang SHARED ${PROJECT_FILES})

#
# Find the libraries that correspond to the LLVM components
# that we wish to use
#
llvm_map_components_to_libnames(llvm_libs all)
target_compile_features(libmlang PRIVATE cxx_range_for)

#
# Link libmlang against the llvm libraries
#
target_link_libraries(libmlang ${llvm_libs})

#
# We want the output to be named libmlang
#
set_target_properties(libmlang PROPERTIES OUTPUT_NAME mlang)
# set_target_properties(libmlang PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADER_FILES}")
set_target_properties(libmlang PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS libmlang
  # IMPORTANT: Add the foo library to the "export-set"
  EXPORT MlangTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/mlang"
    COMPONENT dev)
