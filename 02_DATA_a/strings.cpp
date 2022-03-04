#include "println.hpp"

int main()
{
  std::string hello = "Hello";
  std::string world = "world";
  std::string greeting = hello + ", " + world + '!';
  println("greeting=", greeting);
  if(hello == "Hallo"){
    println("Hallo == ", hello);
  }else{
    println("Hallo != ", hello);
  }
  std::string a = "Aachen";
  std::string z = "Zwickau";
  std::string cmp;
  if (a < z){
    cmp = " before ";
  }else{
    cmp = " after ";
  }
  println(a, cmp, z);
}
