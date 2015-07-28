cmake_minimum_required(VERSION 2.8)
project(mlang)
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")

if(MSVC)
    set(LIBCONFIG_DLL OFF CACHE BOOL "Use libconfig DLL instead of static library")
endif()

include(CheckIncludeFile)
include(CheckLibraryExists)
include(CheckCXXCompilerFlag)

#
# Locate LLVM.
#
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

#
# Main configuration.
#
set(MLANG_MAJOR_VERSION 0)
set(MLANG_MINOR_VERSION 1)
set(MLANG_PATCH_VERSION 0)
set(MLANG_VERSION
  ${MLANG_MAJOR_VERSION}.${MLANG_MINOR_VERSION}.${MLANG_PATCH_VERSION})

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH
  "Installation directory for header files")
if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/CMake/Mlang)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH
  "Installation directory for CMake files")
 
# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()
 
# set up include-directories
include_directories(
  "${PROJECT_SOURCE_DIR}"   # to find foo/foo.h
  "${PROJECT_BINARY_DIR}")  # to find foo/config.h
 
# Add sub-directories
add_subdirectory(tools)
add_subdirectory(lib)





# The interesting stuff goes here
# ===============================

# Add all targets to the build-tree export set
export(TARGETS mlang libmlang
  FILE "${PROJECT_BINARY_DIR}/MlangTargets.cmake")
 
# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE mlang)
 
# Create the FooBarConfig.cmake and FooBarConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
   "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(MlangConfig.cmake.in
  "${PROJECT_BINARY_DIR}/MlangConfig.cmake" @ONLY)
# ... for the install tree
set(CONF_INCLUDE_DIRS "\${MLANG_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(MlangConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MlangConfig.cmake" @ONLY)
# ... for both
configure_file(MlangConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/MlangConfigVersion.cmake" @ONLY)
 
# Install the MlangConfig.cmake and MlangConfigVersion.cmake
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MlangConfig.cmake"
  "${PROJECT_BINARY_DIR}/MlangConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)
 
# Install the export set for use with the install-tree
install(EXPORT MlangTargets DESTINATION
  "${INSTALL_CMAKE_DIR}" COMPONENT dev)
