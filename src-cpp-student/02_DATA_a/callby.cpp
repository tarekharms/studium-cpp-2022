#include "println.hpp"

void call_by_value(int seven){
  // "int seven" is a local variable, which is
  // initialized with a COPY of caller's value (e.g. copy of 7)
  seven = seven + 1;
}

int return_by_value(void){
  int result = 11;
  return result; // returns a COPY of result's value (e.g. copy of 11)
}

int main()
{
  int seven = 7;
  call_by_value(seven);
  println("seven=", seven);
  int eleven = return_by_value();
  println("eleven=", eleven);
}
