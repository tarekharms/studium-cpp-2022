#include <thread>
#include <chrono>
#include <future>
#include <functional>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include "AnsiConsole.hpp"
#include "println.hpp"
#include "printSteps.hpp"

const int maxSignals = 3;
const bool doPrintDebug = false;

struct TimeStamps {
  int slotsUsed;
  time_t slots[maxSignals];
};


volatile int j;
volatile TimeStamps timeStamps;
volatile sigset_t blockedSignals;

void ISR(int iarg);

void install_ISR(void){
  signal(SIGUSR1, ISR);
}


//extern "C" {
void ISR(int iarg){
  if (doPrintDebug) println("ISR j=",j, "iarg=", iarg);nop;
  if(timeStamps.slotsUsed<maxSignals){nop;
    time((time_t*)&timeStamps.slots[timeStamps.slotsUsed++]);nop;
    nop;}
nop;}
//}

void mainloop(){
  for(int i=0; i<20; i++){
    sigprocmask(SIG_BLOCK, (sigset_t *)&blockedSignals, NULL);
    int slotsUsed = timeStamps.slotsUsed;nop;
    sigprocmask(SIG_UNBLOCK, (sigset_t *)&blockedSignals, NULL);
    if(slotsUsed>=maxSignals){
      if (doPrintDebug) println("finished at ", i);
      break;
    }
    j=i;
    if (doPrintDebug) println("main for loop at i=", i);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

void start_ISR(){
  if (doPrintDebug) println("process ID = ", getpid());
  timeStamps.slotsUsed = 0;
  sigemptyset ((sigset_t *)&blockedSignals);
  sigaddset((sigset_t *)&blockedSignals, SIGUSR1);
  install_ISR();
  mainloop();
  if (doPrintDebug) println("done.");
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
  performPattern(start_ISR, "ISR");

  
  return 0;
}
