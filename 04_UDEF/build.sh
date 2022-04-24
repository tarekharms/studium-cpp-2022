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
##             I N T E G E R              ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_minmax_int.out        I N T E G E R"
clang++  ${CPPFLAGS} -DCALCTYPE_INT -c main_04_UDEF_minmax.cpp
ld_ez -o a.out_minmax_int main_04_UDEF_minmax.o


############################################
##              D O U B L E               ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_minmax_double.out     D O U B L E"
clang++  ${CPPFLAGS} -DCALCTYPE_DOUBLE -c main_04_UDEF_minmax.cpp
ld_ez -o a.out_minmax_double main_04_UDEF_minmax.o


############################################
##            R A T I O N A L             ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_minmax_rational.out   R A T I O N A L"
clang++  ${CPPFLAGS} -c RationalNumber.cpp
clang++  ${CPPFLAGS} -DCALCTYPE_RATIONAL -c  main_04_UDEF_minmax.cpp
ld_ez -o a.out_minmax_rational RationalNumber.o main_04_UDEF_minmax.o


############################################
##               R G B                    ##
############################################
echo -en "\033[01;34minfo: \033[0m" #31 for red
echo "building aout_minmax_rational.out   R G B"
#clang++ ${CPPFLAGS} -c main


