#!/bin/bash
CPP_SRC_UTIL_PATH=${CPP_SRC_UTIL_PATH:-../90_aux_src}
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"
#TIDYFLAGS="-checks=-*,cppcoreguidelines*,cppcoreguidelines-narrowing-conversions,-cppcoreguidelines-avoid-magic-numbers"
#clang-tidy ${TIDYFLAGS}  conversions.cpp -- -I${CPP_SRC_UTIL_PATH}/helpers/
set -x 
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -o a.out_conversions conversions.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -o a.out_strings strings.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -o a.out_callby callby.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -o a.out_visibility visibility.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -o a.out_references1 references1.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -o a.out_references2 references2.cpp
clang++ ${CPPFLAGS} -I${CPP_SRC_UTIL_PATH}/helpers/  -o a.out_bool bool.cpp

