#!/usr/bin/env bash
clang -O0 -g -Wall -std=c99 -c main.c
clang -O0 -g -Wall -std=c99 -c twice.c
clang main.o twice.o
