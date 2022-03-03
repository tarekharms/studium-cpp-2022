#!/bin/bash
############################################
##          E N V I R O N M E N T         ##
############################################
echo -e "\033[01;34m============== building ... ==============\033[0m"
CPP_SRC_UTIL_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
export CPLUS_INCLUDE_PATH=${CPP_SRC_UTIL_PATH}/helpers 
echo "using CPLUS_INCLUDE_PATH=${CPLUS_INCLUDE_PATH}"
alias ld_ez="clang++"  # ez = easy
shopt -s expand_aliases
set -x


############################################
##            C O M P I L E R             ##
############################################

CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -c z_limits_println.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -c z_printlnDemo.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -c z_printlnDemo_cmplx.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -c z_aggregates.cpp

############################################
##              L I N K E R               ##
############################################


ld_ez -o a.out_z_limits z_limits_println.o
ld_ez -o a.out_z_printlnDemo z_printlnDemo.o
ld_ez -o a.out_z_printlnDemo_cmplx z_printlnDemo_cmplx.o
ld_ez -o a.out_z_aggregates z_aggregates.o


