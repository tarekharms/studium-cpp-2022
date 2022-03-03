// file: main_04_UDEF.cpp
#include "println.hpp"

// this declares an alias for type <see below>, which is called calctype
#ifdef TYPEDEFINT
typedef int calctype;
#endif 

#ifdef TYPEDEFDOUBLE
typedef double calctype;
#endif 

#ifdef TYPEDEFRATION
#include "RationalNumber.hpp"     // location 1
typedef RationalNumber calctype;  // location 2
#endif 

calctype doCalculation(calctype a, calctype b){
  calctype c = a + b;
  calctype result = c;
  // here is some advanced computation on arguments a and b
  for (int i=0; static_cast<calctype>(i)<b;i++){
    if(a<b){
      result++;
      result = result + (a/=b);
    }
  }

#ifdef DEBUG
  println("a = ", a);
  println("b = ", b);
  println("c = ", c);
#endif

  return result;
}

//int main(int argc, char** argv, char** envp){
int main(){
  calctype a = 100;
  calctype b = 7;
  a = doCalculation(a,b);
  println("a=", a);
  return 0;
}
