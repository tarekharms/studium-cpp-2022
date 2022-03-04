//  typedMemory.cpp

#include "typedMemory.hpp"
#include <iomanip>
#include <sstream>


TypedMemory::TypedMemory(uint8_t defaultValue){
  for (int i=0; i<RAWMEMORYSIZE;++i){
    rawMemory[i] = defaultValue;
  }
}

void TypedMemory::putChar(int position, unsigned char c)
{
  rawMemory[position] = reinterpret_cast<uint8_t>(c);
}

unsigned char TypedMemory::getChar(int position){
  return reinterpret_cast<unsigned char>(rawMemory[position]);
}

void TypedMemory::putUInt(int position, unsigned int i){
  int numBytes = sizeof(i);
  unsigned int byteMask = 0xff << ((numBytes-1)*8);
  for(int k=0; k<numBytes;k++){
    rawMemory[position+k] = (i & byteMask) >> ((numBytes-1-k)*8);
    byteMask >>= 8;
  }
  /* equvalent code for sizeof(unsigned int) == 4:
   uint8_t byte_a = (i &       0xff);
   uint8_t byte_b = (i &     0xff00) >> 8;
   uint8_t byte_c = (i &   0xff0000) >> 16;
   uint8_t byte_d = (i & 0xff000000) >> 24;
   
   rawMemory[position+0] = byte_d;
   rawMemory[position+1] = byte_c;
   rawMemory[position+2] = byte_b;
   rawMemory[position+3] = byte_a;
   */
  
}


unsigned int TypedMemory::getUInt(int position){
  unsigned int result = 0;
  int numBytes = sizeof(result);
  for(int i=0; i<numBytes;i++){
    result |= rawMemory[position+i] << ((numBytes-1-i)*8);
  }
  return result;
}


void TypedMemory::putDouble(int position, double d){
  void * pv = reinterpret_cast<void*>(&rawMemory[position]);
  double * pd = reinterpret_cast<double*>(pv);
  *pd=d;
}

double TypedMemory::getDouble(int position){
  void * pv = reinterpret_cast<void*>(&rawMemory[position]);
  double * pd = reinterpret_cast<double*>(pv);
  return *pd;
}

void TypedMemory::putAnything(int position, void* src, int size){
  for (int i=0; i<size; i++){
    rawMemory[position+i] = reinterpret_cast<uint8_t*>(src)[i];
  }
}

void TypedMemory::getAnything(int position, void* dest, int size){
  for (int i=0; i<size; i++){
    reinterpret_cast<uint8_t*>(dest)[i] = rawMemory[position+i];
  }
}


std::string TypedMemory::hexDump(){
  std::string result;
  std::string printables;
  std::ostringstream os;
  
  os << std::setbase(16);
  int i=0;
  while(i<RAWMEMORYSIZE){
    os << std::setfill('0');
    os << std::setw(4);
    os << i << ":  ";
    for (int j=0;j<16;j++){
      os << std::setfill('0');
      os << std::setw(2);
      os << static_cast<int>(rawMemory[i]);
      os << " ";
      if(std::isprint(rawMemory[i])){
        printables += static_cast<char>(rawMemory[i]);
      }else{
        printables += '.';
      }
      i++;
    }
    os << printables << std::endl;
    printables = "";
  }
  
  os << std::setbase(10);
  result = os.str();
  return result;
}
