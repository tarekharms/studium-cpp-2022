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
clang++ ${CPPFLAGS} -c main_06_BIND_levelAB.cpp
clang++ ${CPPFLAGS} -c main_06_BIND_levelC.cpp


############################################
##              L I N K E R               ##
############################################

ld_ez -o a.out_06_BIND_levelAB main_06_BIND_levelAB.o
ld_ez -o a.out_06_BIND_levelC main_06_BIND_levelC.o



