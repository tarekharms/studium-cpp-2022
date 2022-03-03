//  main.cpp
//  DoubleDelete


#include "LifeCycleProbe.hpp"
#include <iostream>

void callByPointer(LifeCycleProbe* p){
  p->printID();
}

void callByReference(LifeCycleProbe& r){
  r.printID();
}

void callByValue(LifeCycleProbe v){
  v.printID();
}

int main(int argc, const char * argv[]) {

  LifeCycleProbe probe(1000);
  
  std::cout << "three invocations ===========" << std::endl;
  callByPointer(&probe);
  callByReference(probe);
  callByValue(probe);
  
  {
    std::cout << "assigment ===========" << std::endl;
    LifeCycleProbe blockProbe(2000);
    blockProbe = probe;
    blockProbe.printID();
  }
  
  std::cout << "The End. ===========" << std::endl;
    return 0;
}
