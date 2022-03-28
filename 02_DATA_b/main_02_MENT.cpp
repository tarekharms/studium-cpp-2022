// file: main_02_MENT.cpp
// THIS IS C++, use clang++

#include "../helpers/println.hpp"
#include "pascalString.h"


// maps symbols/characters '0' ... '9' ... 'a' ... 'f' to numbers 0 ... 15
int hexDigitToInt(char hexDigit){
  int value = (int)hexDigit;
  
  if(value >= 58)
  {
    value -= 87;
  }
  else
  {
      value -= 48;
  }

  return value;

}


// maps numbers 0 ... 15 to symbols/characters '0' ... '9' ... 'a' ... 'f' 
char intToHexDigit(int number){
  char hexChar = '?'; //FIXME

    if(number > 9)
    {
        hexChar = (char)number + 87;
    }
    else
    {
        hexChar = (char)number + 48;
    }

  return hexChar;
}


// see https://www.arndt-bruenner.de/mathe/scripts/Zahlensysteme.htm
int hexStringToInt(PascalString hexStr){
    int returnValue = 0;
    int faktor = 1;

    hexStr = reversed(hexStr);

    for(int i = 0; i < hexStr.length; i++)
    {
        returnValue += hexDigitToInt(hexStr.characters[i] * faktor);
        faktor * 16;
    }

    return returnValue;
}

int main(/*int argc, char** argv, char** envp*/){
  
    println("0x0 = ", hexDigitToInt('0'));
    println("0x1 = ", hexDigitToInt('1'));
    println("0xa = ", hexDigitToInt('a'));
    println("0x9 = ", hexDigitToInt('9'));
    println("0xf = ", hexDigitToInt('f'));

    println("0 = 0x", intToHexDigit(0));
    println("1 = 0x", intToHexDigit(1));
    println("10 = 0x", intToHexDigit(10));
    println("15 = 0x", intToHexDigit(15));

    println(fromString("Hello, World!"));
    PascalString s1 = fromString("100");      // s1 = {3, {'1', '0', '0',}};
    PascalString s2 = fromString("fffe");     // s2 = {4, {'f', 'f', 'f', 'e',}};
    println("s1 = 0x", s1, " = ", hexStringToInt(s1));
    println("s2 = 0x", s2, " = ", hexStringToInt(s2));
    return 0;
}

