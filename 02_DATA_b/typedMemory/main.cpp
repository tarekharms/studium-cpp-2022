//  main.cpp
//  typedMemory

#include <iostream>
#include <iomanip>
#include "typedMemory.hpp"
#include <stdint.h>


struct RGB {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};


struct compund {
  int theInt;
  double theDouble;
};


/* this illustrates that what the compiler needs to do
 to store local variables in the stack frame. Compare
 this to the code in main().*/
/*void foobar(){
  unsigned int x  = 0x04030201;
  char c1         = 'C';
  char c2         = '+';
  char c3         = '+';
  char c4         = '!';
  double d1       = 16.0;
  compund k1      = {0x04030201, 16.0};
  compund k2      = {0, 0.0};
}*/


int main() {
  TypedMemory mem(0xcc); // default memory value
  
  mem.putUInt(0x10, 1234);
  mem.putChar(0x20, '1');
  mem.putChar(0x21, '2');
  mem.putChar(0x22, '3');
  mem.putChar(0x23, '4');

  char* string = "1234";

  mem.putAnything(0x30, string, sizeof(string));
 
  /*
  std::cout << std::setbase(16);
  std::cout << "0x" << mem.getUInt(0) << std::endl;
  std::cout << mem.getChar(4)
            << mem.getChar(5)
            << mem.getChar(6)
            << mem.getChar(7) << std::endl;
  std::cout << "0x" << mem.getUInt(4) << std::endl;
  std::cout << mem.getDouble(0x30) << " (" << sizeof(double) << " bytes)" << std::endl;
  */
  
  compund a = {0x48382818, 16.0};
  mem.putAnything(0x40, &a, sizeof(compund));
  
  /*
  compund b = {0, 0.0};
  mem.getAnything(0x20, &b, sizeof(compund));
  std::cout << "a = (0x" << a.theInt << ", " << a.theDouble << ")" << std::endl;
  std::cout << "b = (0x" << b.theInt << ", " << b.theDouble << ")" << std::endl;
  std::cout << std::setbase(10);
  */
  
  RGB rgb = {0x33, 0x44, 0x55};
  mem.putAnything(0x50, &rgb, sizeof(rgb));

  std::cout << mem.hexDump() << std::endl;
  
  return 0;
}











