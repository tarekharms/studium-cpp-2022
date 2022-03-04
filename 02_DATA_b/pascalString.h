#include <iostream>

#include <cstdint>

struct PascalString{
  uint8_t length;        // number of chars used as "unsigned integer type with width of exactly 8 bits"
  char characters[255];  // chars of some character string
};

// convenience functions for creation
PascalString fromString(std::string s);
PascalString fromChar(unsigned char c);


// returns all characters INCLUDING those at [indexLeft] and [indexRight]
PascalString SubStr(PascalString s, int indexLeft, int indexRight);

PascalString plus(PascalString left, PascalString right);

// helper function for print() and println()
// no need to understand it right now
std::string as_string(PascalString p);



