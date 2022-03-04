#!/bin/bash
CPP_SRC_UTIL_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"
#echo CPP_SRC_UTIL_PATH is ${CPP_SRC_UTIL_PATH}
#echo CPPFLAGS is ${CPPFLAGS}
# compile
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -c typedMemory.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -c main.cpp
# link
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -o typedMemory.out main.o typedMemory.o
