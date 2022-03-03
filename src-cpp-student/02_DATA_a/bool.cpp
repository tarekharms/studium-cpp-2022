#include "println.hpp"

int main(/*int argc, char** argv, char** envp*/){
  int seven         = 7;
  int eleven        = 11;
  char zulu         = '\0';

  bool b_true1      = (true);
  bool b_true2      = (!false);
  bool b_smaller    = (seven < eleven);
  bool b_int        = (seven);
  bool b_eqal       = (seven == 7);
  
  bool b_false1     = false;
  bool b_false2     = !true;
  bool b_char       = zulu;
  bool b_greater    = seven > eleven;
  bool b_neqal      = seven != 7;


  bool b_complex = seven < eleven && 5>3 && zulu != 'z';
  
  
  bool allTrue      =   b_true1   &&  b_true2  && b_smaller &&  b_int && b_eqal && b_complex;
  bool allFalse     =  !b_false1  && !b_false2 &&  !b_char  && !b_greater && !b_neqal;
  //bool allFalse2  = !(b_false1 ||   b_false2 ||   b_char  ||  b_greater ||  b_neqal);

  if (allTrue && allFalse /* && allFalse2*/) {
    println("all fine!");
    return 0;
  } else {
    println("error!");
    return 1;
  }
}

