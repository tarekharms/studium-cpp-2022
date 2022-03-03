#include "println.hpp" // easy printing with println()

int function(int x){
  int y = 2 * x + 4; 
  return y;
}

void printValues(int first, int last){
  println("first=", first, "  last=", last);
  int k=first;
  while(k<=last){
    int y=function(k);
    println("y(",k,")=",y);
    k = k+1;
  }
}

int main(){           // program entry point
  printValues(0,9);
  return 0;           // no error occoured
}
