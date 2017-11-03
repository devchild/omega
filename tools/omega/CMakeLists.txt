add_executable(omega main.cpp)
 
# Find the libraries that correspond to the LLVM components
# that we wish to use
# llvm_map_components_to_libnames(llvm_libs support core irreader)

target_link_libraries(omega libomega uuid)

# enable c++11
target_compile_features(omega PRIVATE cxx_range_for)

include_directories("../../include")
SET(CMAKE_INSTALL_RPATH "@rpath/lib")

install(TARGETS omega
  # IMPORTANT: Add the bar executable to the "export-set"
  EXPORT OmegaTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)

add_style_check_target(omega main.cpp)
