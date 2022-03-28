#!/usr/bin/env bash
# enable warnings etc.
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"

# add a path to search for header files
CPP_SRC_UTIL_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
export CPLUS_INCLUDE_PATH=${CPP_SRC_UTIL_PATH}/helpers 

## let the shell print commands prior to execution
#set -x                                                 

# finally, let the compiler driver do the actual work
echo "compiling $1 with clang++ ..."
clang++  ${CPPFLAGS} $1
