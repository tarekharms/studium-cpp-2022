// file: main_02_MENT.cpp
// THIS IS C++, use clang++

#include "../helpers/println.hpp"
#include "pascalString.h"


// maps symbols/characters '0' ... '9' ... 'a' ... 'f' to numbers 0 ... 15
int hexDigitToInt(char hexDigit){
  int value = (int) hexDigit;

    if(value > 59)
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
        number += 87;
    }
    else
    {
        number += 48;
    }

    hexChar = (char) number;

  return hexChar;
}

void printPascalString(PascalString string)
{
    for(int i = 0; i < string.length; i++)
    {
        println(string.characters[i]);
    }
}


// see https://www.arndt-bruenner.de/mathe/scripts/Zahlensysteme.htm
int hexStringToInt(PascalString hexStr){
    int returnValue = 0;
    hexStr = reversed(hexStr);
    int faktor = 1;

    for(int i = 0; i < hexStr.length; i++)
    {
        returnValue += faktor * hexDigitToInt(hexStr.characters[i]);

        faktor *= 16;
    }

    return returnValue;
}

PascalString intToHexString(int zahl)
{
    PascalString string = {0,{0,}};
    
    do
    {
        string.characters[string.length] = intToHexDigit(zahl % 16);
        string.length++;
        zahl /= 16;
    }
    while(zahl > 0);

    return reversed(string);
}

int main(/*int argc, char** argv, char** envp*/){
    
    println("0x0 = ", hexDigitToInt('0'));
    println("0x9 = ", hexDigitToInt('9'));
    println("0xa = ", hexDigitToInt('a'));
    println("0xf = ", hexDigitToInt('f'));

    println("0 = 0x", intToHexDigit(0));
    println("9 = 0x", intToHexDigit(9));
    println("10 = 0x", intToHexDigit(10));
    println("15 = 0x", intToHexDigit(15));

    PascalString string = fromString("Hello Wordl!");
    PascalString strRev = reversed(string);

    println("string = ", string);
    println("reversed = ", strRev);

    printPascalString(string);


    println(255, " = 0x", intToHexString(255));
    println(256, " = 0x", intToHexString(256));


    println(fromString("Hello, World!"));
    PascalString s1 = fromString("100");      // s1 = {3, {'1', '0', '0',}};
    PascalString s2 = fromString("fffe");     // s2 = {4, {'f', 'f', 'f', 'e',}};
    println("s1 = 0x", s1, " = ", hexStringToInt(s1));
    println("s2 = 0x", s2, " = ", hexStringToInt(s2));
    return 0;
}

