//  typedMemory.hpp

#ifndef typedMemory_hpp
#define typedMemory_hpp
#include <iostream>
#include <ctype.h>

struct TypedMemory {
  static const int RAWMEMORYSIZE=128;//1024;
  uint8_t rawMemory[RAWMEMORYSIZE];
  TypedMemory(uint8_t defaultValue);
  
  void          putChar(int position, unsigned char c); // position in bytes starting at 0
  unsigned char getChar(int position);

  void          putUInt(int position, unsigned int i);
  unsigned int  getUInt(int position);

  void          putDouble(int position, double d);
  double        getDouble(int position);

  void          putAnything(int position, void* src, int size);
  void          getAnything(int position, void* dest, int size);

  std::string   hexDump();
};

#endif
