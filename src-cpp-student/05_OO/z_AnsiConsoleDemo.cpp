#include <iostream>
#include <cmath>
#include "AnsiConsole.h"

/*
 see
 https://en.wikipedia.org/wiki/ANSI_escape_code
 https://gist.github.com/vratiu/9780109
 https://gist.github.com/RobinMalfait/7881398
 */


int main(/*int argc, char **argv*/)
{
  ansiConsole.clearScreen();
  // x=1 and y=1 is the upper left corner
  // x and y are more like column and row
  ansiConsole.printText(4,4,"Hello, World!");

  // draw a pixel, sort of
  ansiConsole.printText(3,3,"*");
  // draw a line
  for(int i=0;i<10;i++){
    ansiConsole.printText(2+i,2,"-", Colors::GREEN);
  }
  ansiConsole.printText(5,15,"end.");

  return 0;
}
