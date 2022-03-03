//  intStack.cpp
//  6_STD_stacks

#include "intStack.hpp"
#include <iostream>

const int intStack::capacity;

intStack::intStack()
: tos(0)
{
  
}

void intStack::push(int element){
  elements[tos++] = element;
}

int intStack::pop(){
  return elements[--tos];
}

int intStack::size(){ // number of elements pushed
  return tos;
}

bool intStack::isEmpty(){
  return tos == 0;
}

void intStack::clear(){
  tos = 0;
}

void intStack::print(){
  std::cout << size() << " of " << capacity << " allocated." << std::endl;
  for (int i=0; i<tos; i++){
    std::cout << i << ": " << elements[i] << std::endl;
  }
}
