#include "println.hpp"

int global;

void foo(int param){ // param is local var, but initialized automatically
  int local=7;
  global = param;
  global = local;
  for(int i=0;i<1;++i){
    global = param;
    global = local;
    global = i;
    {
      int k=13;
      global = k;
    }
    //global = k; // k is not visible here
  }
  //global = i; // i is not visible here
}

int main()
{
  global = 11; // local, param, i, k are not visible here
  foo(9);
  println("s");
}
