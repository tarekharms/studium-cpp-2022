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
clang++ ${CPPFLAGS} -c ${CPP_SRC_UTIL_PATH}/helpers/AnsiConsole.cpp
clang++ ${CPPFLAGS} -c z_AnsiConsoleDemo.cpp
clang++ ${CPPFLAGS} -c z_main_mp4_OO_a_vehicles.cpp


############################################
##              L I N K E R               ##
############################################

ld_ez -o a.out_z_ansiConsoleDemo AnsiConsole.o z_AnsiConsoleDemo.o
ld_ez -o a.out_z_vehicles z_main_mp4_OO_a_vehicles.o





