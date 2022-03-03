// file: main_02_MENT.cpp
// THIS IS C++, use clang++

#include "../helpers/println.hpp"
#include "pascalString.h"


// maps symbols/characters '0' ... '9' ... 'a' ... 'f' to numbers 0 ... 15
int hexDigitToInt(char hexDigit){
  int value = -1;
  // TODO
  return value;
}


// maps numbers 0 ... 15 to symbols/characters '0' ... '9' ... 'a' ... 'f' 
char intToHexDigit(int number){
  char hexChar = '?'; //FIXME
  return hexChar;
}


// see https://www.arndt-bruenner.de/mathe/scripts/Zahlensysteme.htm
int hexStringToInt(PascalString hexStr){
  int returnValue = -1;
  // TODO
  return returnValue;
}

int main(/*int argc, char** argv, char** envp*/){
  println(fromString("Hello, World!"));
  PascalString s1 = fromString("100");      // s1 = {3, {'1', '0', '0',}};
  PascalString s2 = fromString("fffe");     // s2 = {4, {'f', 'f', 'f', 'e',}};
  println("s1 = 0x", s1, " = ", hexStringToInt(s1));
  println("s2 = 0x", s2, " = ", hexStringToInt(s2));
  return 0;
}

