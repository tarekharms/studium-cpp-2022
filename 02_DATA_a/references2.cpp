#include "println.hpp"
#include <cctype>

int alphaCount;
int numCount;
int other;

int& counterForChar(char c){ //note: returns a reference to an integer
  if(isalpha(c)){
    return alphaCount;
  } else if(isdigit(c)){
    return numCount;
  } else {
    return other;
  }
}

void countChars(std::string& s){
  for (size_t i=0; i<s.length(); ++i){
    counterForChar(s[i]) += 1; // note: return value is on left side of assignment
  }
  s="done."; // note: will modify caller's value
}

int main()
{
  std::string hex("0123456789abcdef");
  println("hex=", hex);
  countChars(hex);
  println("alphaCount=", alphaCount, "numCount=", numCount, " other=", other);
  println("hex=", hex);
}

