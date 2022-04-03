#include "../helpers/println.hpp"
#include <cstdint>

uint32_t fromRGB(uint8_t red, uint8_t green, uint8_t blue){
  return (red << 16) | (green<<8) | (blue);
}

uint8_t red(uint32_t rgb){
  return (rgb & 0xFF0000) >> 16;
}

uint8_t green(uint32_t rgb){
  return (rgb & 0xFF00) >> 8;
}

uint8_t blue(uint32_t rgb){
  return (rgb & 0xFF);
}

uint8_t luminosity(uint32_t rgb)
{
    return (uint8_t)(0.21 * red(rgb) + 0.72 * green(rgb) + 0.07 * blue(rgb));
}

uint32_t addColors(uint32_t a, uint32_t b)
{
    return (a | b);
}

int main(/*int argc, char** argv, char** envp*/){
  uint32_t pureRed = fromRGB(255,0,0);
  println("pure red is ", pureRed);
  println("pure blue is ", fromRGB(0,0,255));
  println("red part of pure red is ", red(pureRed) );
  
   println("Luminosity 0xFF0000: ", luminosity(0xff0000)); 

  return 0;
}

