#include "println.hpp"

int main()
{
  int   value = 0;
  int & reference = value;
  int & alias     = value;
  int & spitzname = value;
  int & verweis   = value;

  println("value before ", value);
  value     = value + 1;
  reference = reference + 20;
  alias     =     alias + 300;
  spitzname = spitzname + 4000;
  verweis   =   verweis + 50000;
  println("value after ", value);
  println(reference);
}

