#include "pascalString.h"

// convenience function for creation
PascalString fromString(std::string s){
  PascalString p;
  p.length = s.length();
  for(size_t i=0; i<s.length(); i++){
    p.characters[i] = s[i];
  }
  return p;
}

// convenience function for creation
PascalString fromChar(unsigned char c){
  return {1,{static_cast<char>(c),}};
}


// returns all characters INCLUDING those at [indexLeft] and [indexRight]
PascalString SubStr(PascalString s, int indexLeft, int indexRight){
  PascalString result = {0,{0,}};
  result.length = indexRight-indexLeft+1;
  for(int i=0; i<result.length; i++){
    result.characters[i] = s.characters[i+indexLeft];
  }
  return result;
}

PascalString plus(PascalString left, PascalString right){
  PascalString result = left;
  for(int i=0; i<right.length; i++){
    result.characters[i+left.length] = right.characters[i];
  }
  result.length = left.length + right.length;
  return result;
}

// helper function for print() and println()
// no need to understand it right now
std::string as_string(PascalString p){
  p.characters[p.length]=0;
  std::string s(p.characters);
  return s;
}


