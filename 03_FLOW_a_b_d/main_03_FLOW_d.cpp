#include "AnsiConsole.hpp"
#include "println.hpp"
#include <thread>
#include <chrono>
#include <future>
#include <functional>
#include "printSteps.hpp"

/*
 ggf. die Call Stack-Tiefe mit Farben darstellen: manuell mit color++ hochsetzen, mit color-- am Funktionsende wieder runter. Dann kann start_subroutine() f1() aufrufen, die f2(), f3() etc. (alle gleicher Inhalt) das illustriert den Zusammenhang Farbe/Call. Dann f_recursiv().
 */

/*
 Cmd-Shift-3                             Take snapshot of the whole screen
 Cmd-Shift-4                             Take snapshot of the selected area
 Cmd-Shift-4-Spacebar                    Take picture of a window
 Escape                                  Cancel
 Hold Spacebar after Drawing the region  Move the selected area
 Hold Option                             Resize selected area
 Hold Shift                              Resize selected area horizontally
 or vertically
*/


#define mop m.lock();nop;m.unlock();

std::mutex m;

int thread(){mop;
  int i=0;
  for (i=0;i<10;i++){
    mop;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
  return i;
}

int thread2(){mop;
  int i=0;
  for (i=0;i<10;i++){
    mop;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
  return i;
}

void start_Futures(){mop;
  auto handle = std::async(std::launch::async, thread); mop;
  auto handle2 = std::async(std::launch::async, thread2); mop;
  int sum = handle.get() + handle2.get(); mop;
mop;}


void thrower(){nop;
  nop;
  nop; throw std::string("Exception!"); nop;
  nop;
nop;}

void start_Exception(){nop;
  try{nop;
    nop; thrower(); nop;
    nop; }catch(std::string){nop;
    nop;
    nop; }
nop;}



void lambdaCaller(std::function<void()> lambda){nop;
  nop; lambda(); nop;
nop;}

void start_Lambda(){nop;
  nop;
  nop; lambdaCaller([](){nop;}); nop;
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
  performPattern(start_Futures, "Futures/Threads");
  performPattern(start_Exception, "Exception");
  performPattern(start_Lambda, "Lambda");
  
  return 0;
}
