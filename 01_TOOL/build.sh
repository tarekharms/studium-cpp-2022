#!/usr/bin/env bash
echo -e "\033[01;34m============== preprocess ... ==============\033[0m"
clang -o main.i -E main.c
clang -o polynom1.i -E polynom1.c
clang -o polynom2.i -E polynom2.c
clang -o poly_all.i -E poly_all.c

echo -e "\033[01;34m============== compile ... ==============\033[0m"
clang -S main.i
clang -S polynom1.i
clang -S polynom2.i
clang -S poly_all.i

echo -e "\033[01;34m============== assemble ... ==============\033[0m"
clang -c main.s
clang -c polynom1.s
clang -c polynom2.s
clang -c poly_all.s

echo -e "\033[01;34m============== link ... ==============\033[0m"
clang main.o polynom1.o polynom2.o poly_all.o

#echo -e "\033[01;34m============== disassemble ... ==============\033[0m"
#echo "put disassemble command here!"
