#!/bin/bash
CPPFLAGS="-Wall -Wextra -Wpedantic -O0 -std=c++17"
clang -Wall -Wextra -Wpedantic -O0 -std=c11 -c libattopng.c
clang++ ${CPPFLAGS} -c pngWriter.cpp
clang++ ${CPPFLAGS} -c testPngWriter.cpp
clang++ ${CPPFLAGS} -o testPngWriter.out libattopng.o pngWriter.o testPngWriter.o

