#include "println.hpp"

// using unsigned here, since narrowing signed is implementation-defined
void implicitConversions(){
  // non-narrowing
  unsigned char c = 127;
  unsigned int  i = c;
  unsigned long l = i;
  //TBD: add double
  println("implicit: c=", c, " l=", l);
  // narrowing
  unsigned long ln = 1024 + 127;
  unsigned int  in = ln;
  unsigned char cn = in;
  //TBD: add double
  println("implicit: ln=", ln, " cn=", cn);
}


// using unsigned here, since narrowing signed is implementation-defined
void exlicitConversions(){
  // non-narrowing
  unsigned char c = static_cast<unsigned char>(127);
  unsigned int  i = static_cast<unsigned int>(c);
  unsigned long l = static_cast<unsigned long>(i);
  println("exlicit: c=", c, " l=", l);
  //TBD: add double
  // narrowing
  unsigned long ln = static_cast<unsigned long>(1024 + 127);
  unsigned int  in = static_cast<unsigned int>(ln);
  unsigned char cn = static_cast<unsigned char>(in);
  //TBD: add double
  println("exlicit: ln=", ln, " cn=", cn);
}

void numbersToStrings(){
  unsigned int i = 1024 + 127;
  std::string  si = std::to_string(i);
  println("numbersToStrings: i=", i, " si=", si);
  double d = 355.0/113.0;
  std::string  sd = std::to_string(d);
  println("numbersToStrings: d=", d, " sd=", sd);
}

void stringsToNumbers(){
  std::string sd = "3.14159";
  double d = stod(sd);
  println("stringsToNumbers: sd=", sd, " d=", d);
  std::string si = "1151";
  int i = stoi(si);
  println("stringsToNumbers: si=", si, " i=", i);
}

/*TBD: {}-conversion */

int main()
{
  implicitConversions();
  exlicitConversions();
  numbersToStrings();
  stringsToNumbers();
}
