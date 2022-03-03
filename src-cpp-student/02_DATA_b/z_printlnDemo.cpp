#include "println.hpp"


int main()
{
  println("this program shows how to use println()");
  int i=1;
  println(i);           // type int
  double d=2.78;
  println(d);           // type double
  println("");          // just an empty line
  println("i=", i, " d=", d);// more than one
  print("i=", i);       // print all with separate statements
  print(" d=", d);      // no "ln" -> no newline
  println();            // just an empty line
  println("1.0 = ",1.0);
  println("10000.0 = ",10000.0);
  println("10000.125 = ",10000.125);
}

