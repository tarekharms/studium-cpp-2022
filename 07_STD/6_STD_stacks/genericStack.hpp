//  genericStack.hpp
//  6_STD_stacks

#ifndef genericStack_hpp
#define genericStack_hpp
#include <iostream>

// good: encapsulation
// good: separation of interface and implementation
// good: arbitrary element type
// good: arbitrary capacity
// bad: implementation in .hpp
// bad: compiler error messages are difficult to read

template <typename ElementType, int capacity>
struct genericStack {
  int tos; // top of stack, i.e. index of next write/push
  ElementType elements[capacity];
public:
  genericStack();
  void push(ElementType element);
  ElementType pop();
  int size(); // number of elements pushed
  bool isEmpty();
  void clear();
  void print();
};


// ============= implementation =============

template <typename ElementType, int capacity>
genericStack<ElementType, capacity>::genericStack()
: tos(0)
{
  
}

template <typename ElementType, int capacity>
void genericStack<ElementType, capacity>::push(ElementType element){
  elements[tos++] = element;
}

template <typename ElementType, int capacity>
ElementType genericStack<ElementType, capacity>::pop(){
  return elements[--tos];
}

template <typename ElementType, int capacity>
int genericStack<ElementType, capacity>::size(){ // number of elements pushed
  return tos;
}

template <typename ElementType, int capacity>
bool genericStack<ElementType, capacity>::isEmpty(){
  return tos == 0;
}

template <typename ElementType, int capacity>
void genericStack<ElementType, capacity>::clear(){
  tos = 0;
}

template <typename ElementType, int capacity>
void genericStack<ElementType, capacity>::print(){
  std::cout << size() << " of " << capacity << " allocated." << std::endl;
  for (int i=0; i<tos; i++){
    std::cout << i << ": " << elements[i] << std::endl;
  }
}

#endif
