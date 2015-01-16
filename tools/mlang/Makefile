##===- projects/mlang/tools/mlang/Makefile ---------------*- Makefile -*-===##

#
# Indicate where we are relative to the top of the source tree.
#
LEVEL=../..

#
# Give the name of the tool.
#
TOOLNAME=mlang

#
# List libraries that we'll need
# We use LIBS because sample is a dynamic library.
#
USEDLIBS = mlang.a  parser.a codedom.a


LINK_COMPONENTS = all

#
# Include Makefile.common so we know what to do.
#
include $(LEVEL)/Makefile.common

LIBS += -luuid