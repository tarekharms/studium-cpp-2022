//
//  main.cpp
//  leistungstestatSurrogat
//
//  Created by clink on 11/12/14.
//  Copyright (c) 2014 HSEL. All rights reserved.
//

#include <iostream>


#include "OneByOneMatrix.h"

int failCounter=0;

typedef int NumberType;
//typedef OneByOneMatrix NumberType;
//typedef LargeCowMatrix NumberType;


void simpleTests(){
  NumberType i1(1);
  NumberType i2(2);
  NumberType i3=i1+i2;
  
  if (i3!=NumberType(3)){
    failCounter++;
    std::cout << "fail!" << std::endl;
  }
  
  i3++;
  if (i3!=NumberType(4)){
    failCounter++;
    std::cout << "fail!" << std::endl;
  }
  
  i3=i1;
  if (i3!=NumberType(1)){
    failCounter++;
    std::cout << "fail!" << std::endl;
  }
  
  if (OneByOneMatrix::instanceCountExceeds(3)){
    failCounter++;
  }
}

void arrayTests(){
  {
    const int BUFSIZE=1000;
    NumberType singletonValue(4711);
    NumberType numbers[BUFSIZE];
    bool didFail=false;
    
    for(int i=0; i<BUFSIZE;i++){
      numbers[i] = singletonValue;
    }
    
    for(int i=0; i<BUFSIZE;i++){
      if((int)numbers[i] != (int)singletonValue){
        didFail |= true;
      }
    }
    
    if(didFail) {
      failCounter++;
    }
  }
  if (OneByOneMatrix::instanceCountExceeds(1)){
    failCounter++;
  }
}


int main(int argc, const char * argv[]) {
  
  simpleTests();
  arrayTests();
  
  if (OneByOneMatrix::instanceCountExceeds(0)){
    failCounter++;
  }
  std::cout << failCounter << " failures" << std::endl;
  
  return 0;
}
