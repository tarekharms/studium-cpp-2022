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

CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17 -Wno-unused-variable"
clang++ ${CPPFLAGS} -c ${CPP_SRC_UTIL_PATH}/helpers/AnsiConsole.cpp 
clang++ ${CPPFLAGS} -c ${CPP_SRC_UTIL_PATH}/helpers/printSteps.cpp
#clang++ ${CPPFLAGS} -c mods.cpp 
clang++ ${CPPFLAGS} -c mods_0.cpp 
clang++ ${CPPFLAGS} -c mods_1.cpp 
#clang++ ${CPPFLAGS} -c mods_2.cpp 
#clang++ ${CPPFLAGS} -c mods_3.cpp 


############################################
##              L I N K E R               ##
############################################

#ld_ez -o a.out_mods AnsiConsole.o printSteps.o mods.o
ld_ez -o a.out_mods_0 AnsiConsole.o printSteps.o mods_0.o
ld_ez -o a.out_mods_1 AnsiConsole.o printSteps.o mods_1.o
#ld_ez -o a.out_mods_2 AnsiConsole.o printSteps.o mods_2.o
#ld_ez -o a.out_mods_3 AnsiConsole.o printSteps.o mods_3.o


