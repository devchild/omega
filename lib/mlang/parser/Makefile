##===- projects/mlang/lib/Makefile ------------------------*- Makefile -*-===##

#
# Relative path to the top of the source tree.
#
LEVEL=../../..

#
# List all of the subdirectories that we will compile.
#
# DIRS=mlang

#
# Give the name of a library.  This will build a dynamic version.
#
LIBRARYNAME=parser

BUILT_SOURCES = scanner.o parser.o

include $(LEVEL)/Makefile.common

$(PROJ_SRC_DIR)/mlang_parser.cpp: $(PROJ_SRC_DIR)/mlang_parser.yy
	$(YACC) -o $(PROJ_SRC_DIR)/mlang_parser.cpp --defines=$(PROJ_SRC_DIR)/mlang_parser.hh $(PROJ_SRC_DIR)/mlang_parser.yy

$(PROJ_SRC_DIR)/mlang_scanner.cpp: $(PROJ_SRC_DIR)/mlang_scanner.ll
	$(LEX) -o $(PROJ_SRC_DIR)/mlang_scanner.cpp $(PROJ_SRC_DIR)/mlang_scanner.ll

parser.o: $(PROJ_SRC_DIR)/mlang_parser.cpp
	$(CXX) $(CXXFLAGS) -I$(PROJ_SRC_ROOT)/include -I$(PROJ_SRC_DIR)/include -I. -I./include -I$(LLVM_OBJ_ROOT)/include -I$(LLVM_SRC_ROOT)/include -c -o $@ $<

scanner.o: $(PROJ_SRC_DIR)/mlang_scanner.cpp
	$(CXX) $(CXXFLAGS) -I$(PROJ_SRC_ROOT)/include -I$(PROJ_SRC_DIR)/include -I. -I./include -I$(LLVM_OBJ_ROOT)/include -I$(LLVM_SRC_ROOT)/include -c -o $@ $<