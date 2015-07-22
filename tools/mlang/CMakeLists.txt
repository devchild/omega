add_executable(mlang main.cpp)
 
# Find the libraries that correspond to the LLVM components
# that we wish to use
# llvm_map_components_to_libnames(llvm_libs support core irreader)

target_link_libraries(mlang libmlang)

# enable c++11
target_compile_features(mlang PRIVATE cxx_range_for)

include_directories("../../include")

install(TARGETS mlang
  # IMPORTANT: Add the bar executable to the "export-set"
  EXPORT MlangTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)