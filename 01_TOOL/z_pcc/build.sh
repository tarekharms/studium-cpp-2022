#!/bin/sh

# generate main.s, main.o, b.out
pcc -Wmissing-prototypes -O0 -S main.c
as -o main.o main.s
#ld -o b.out main.o /lib/crt0.o /lib/crti.o  -lc
pcc -o b.out main.o

# generate a.out
pcc -O0 -g main.c

# generate assembly intermixed with source code
objdump -S a.out > objdump-S_a.out.txt

