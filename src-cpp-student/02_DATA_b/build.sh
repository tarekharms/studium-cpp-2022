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
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -c pascalString.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -c main_colors.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -c main_02_DATA.cpp


############################################
##              L I N K E R               ##
############################################

ld_ez -o a.out_main_02_DATA main_02_DATA.o pascalString.o
ld_ez -o a.out_colors main_colors.o


