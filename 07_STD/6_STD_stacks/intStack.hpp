//  intStack.hpp
//  6_STD_stacks

#ifndef intStack_hpp
#define intStack_hpp

// good: encapsulation
// good: separation of interface and implementation
// bad: fixed element type
// bad: fixed capacity

struct intStack {
  static const int capacity=1024;
  int tos; // top of stack, i.e. index of next write/push
  int elements[capacity];
public:
  intStack();
  void push(int element);
  int pop();
  int size(); // number of elements pushed
  bool isEmpty();
  void clear();
  void print();
};

#endif
