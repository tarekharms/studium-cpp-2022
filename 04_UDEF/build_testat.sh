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
#set -x


############################################
##            C O M P I L E R             ##
############################################

CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"


############################################
##               R G B                    ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_rgbcolor.out   R A T I O N A L"
clang++  ${CPPFLAGS} -c rgbColor.cpp
clang++  ${CPPFLAGS} -c main_rgbColor.cpp
#clang++  ${CPPFLAGS} -DCALCTYPE_RATIONAL -c  main_04_UDEF_minmax.cpp
ld_ez -o a.outrgbColor rgbColor.o main_rgbColor.o

