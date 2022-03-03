#include "cxx-prettyprint/prettyprint.hpp"
#include "println.hpp"
#include <iostream>
#include <vector>
#include <list>

struct comp {
  comp() : a(0), b(0) {}
  int a;
  int b;
};

std::string as_string(comp c){
  std::string result("comp(");
  result += as_string(c.a);
  result += std::string(",");
  result += as_string(c.b);
  result += std::string(")");

  return result;
}

int main()
{
  print("this program shows how to use println()");
  println(", number types and chars are emphasized");
  println('c');
  int i=1;
  println(i);           // type int
  signed int i2=-1;
  println(i2);           // type int
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
  println("10000.0001 * 1000.0  * 1000.0 = ",10000.125 * 1000.0 * 1000.0);
  char c1='c',c2='h',c3='a',c4='r',c5='s';
  println("chars=", c1, c2, c3, c4, c5);
  println("chars=", static_cast<signed char>(c1), static_cast<unsigned char>(c2), c3, c4, c5);
  comp co;
  println("comp:",co);
  println("bool ", 3>4);

#ifdef H_PRETTY_PRINT
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  std::cout << "A-" << v << "-B" << std::endl;
  println(1, v, "v");
  std::list<double> l;
  l.push_back(1.1);
  l.push_back(2.2);
  println("list> ", l, " <list");


  comp compo;
  std::vector<comp> cv;
  cv.push_back(compo);
  cv.push_back(compo);
  cv.push_back(compo);
  println("vector<comp>  ", cv, "  vector<comp>");
#endif
  
}

