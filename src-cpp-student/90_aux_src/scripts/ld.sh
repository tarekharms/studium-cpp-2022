#!/usr/bin/env bash
echo "int main(){return 0;}" > zldmainXXX.cpp
clang++ -c zldmainXXX.cpp
LDOBJS=$@
LDCMD=$(clang++ -v -o z.out zldmainXXX.o 2>&1 | grep zldmainXXX | sed "s/zldmainXXX.o/$LDOBJS/g;s/\"/ /g")
#echo $LDCMD
$LDCMD
rm zldmainXXX.cpp zldmainXXX.o 
