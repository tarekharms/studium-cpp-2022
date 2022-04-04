#include "AnsiConsole.hpp"
#include "println.hpp"
#include <thread>
#include <chrono>
#include <future>
#include <functional>
#include "printSteps.hpp"






void start_Sequence(void){nop;
  nop;
  nop; 
  for(int i = 0; i < 12; i++) { if(i < 6) { nop; 
      }
      else { nop; } }
  nop;
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


  return 0;
}
