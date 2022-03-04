#include "AnsiConsole.hpp"
#include "println.hpp"
#include <thread>
#include <chrono>
#include <future>
#include <functional>
#include "printSteps.hpp"


void func_test2(int arg){nop;
  nop; if(arg==2){ nop;
    nop;
    nop;
    nop;
    nop;
  nop; }else{ nop;
    nop;
    nop;
    nop;
    nop;
  nop;}
nop;}



void start_test2(void){nop;
  nop; func_test2(1); nop;
  nop;for(int j=0;j<7;j++){
    nop;
  }nop;
  nop;
}



void recurse(int); // forward declaration because of firstLine initialization
void start_Recursion(){
  recurse(3);
}


void recurse(int turns){colorOffset++; nop;
  nop;
  nop; if(turns>0) { nop;
          nop;
          nop; recurse(turns - 1); nop;
          nop;}
  nop;
nop;colorOffset--;}


void start_Iteration(void){nop;
  nop; int i=0; const int loops=6;
  for(int k=0;k<loops;k++){
    nop;
  }
nop;}

void start_Iteration_all(void){nop;
  nop; int i=0; const int loops=6;
  while(i<loops){
    nop; i++;
  }
  for(int k=0;k<loops;k++){
    nop;
  }
  do {
    nop;
  } while (--i); nop;
nop;}


void start_Sequence(void){nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
}

void start_Selection(void){nop;
  nop;  if (13 == 17){
    nop;
    nop;
    nop;
  }else{
      nop;
      nop;
      nop;
    }nop;
nop;}



int func_1(int arg);

void start_subroutine(void){nop;
  nop; int x = func_1(3); nop;
  nop;
nop;}

int func_1(int arg){nop;
  nop; int local_1 = arg;
  nop;
  nop;
  nop;
  nop; return arg * local_1;
}


void start_GotoHarmful(void){nop;
        nop; goto label1;
label2: nop; goto label5;
label1: nop;
        nop; goto label7;
        nop;
label5: nop; goto lexit;
label7: nop; goto label2;
        nop;
lexit:  nop;
        nop;
}


typedef void (*voidFunc)();

void performPattern(voidFunc func, std::string title){
  TITLE(title);
  func();
  printCommands(__FILE__);
  resetCommands();
  getchar();
}

int main(/*int argc, const char * argv[]*/) {
  performPattern(start_Sequence, "Sequence");
  performPattern(start_Selection, "Selection");
  performPattern(start_Iteration, "Iteration");
  performPattern(start_Iteration_all, "Iteration_all");
  performPattern(start_subroutine, "Subroutine");
  performPattern(start_Recursion, "Recursion");
  performPattern(start_GotoHarmful, "goto (considered harmful)");

  return 0;
}
