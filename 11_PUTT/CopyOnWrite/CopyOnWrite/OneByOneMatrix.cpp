//
//  OneByOneMatrix.cpp
//  CopyOnWrite
//
//  Created by clink on 17/05/16.
//  Copyright (c) 2016 HSEL. All rights reserved.
//

#include "OneByOneMatrix.h"


#include <iostream>

int OneByOneMatrix::s_instanceCounter=0;


OneByOneMatrix::OneByOneMatrix()
: m_value(-1), m_referenceCounter(0)
{
  s_instanceCounter++;
}

OneByOneMatrix::OneByOneMatrix(int initialValue)
: m_value(initialValue), m_referenceCounter(0)
{
  s_instanceCounter++;
}

OneByOneMatrix::OneByOneMatrix(const OneByOneMatrix& source)
: m_value(source.m_value), m_referenceCounter(source.m_referenceCounter)
{
  s_instanceCounter++;
}

OneByOneMatrix::~OneByOneMatrix(){
  s_instanceCounter--;
}

/*
 int OneByOneMatrix::value(void) const {
 return m_value;
 }*/

OneByOneMatrix OneByOneMatrix::operator+(const OneByOneMatrix & other){
  return OneByOneMatrix(m_value + other.m_value);
}

OneByOneMatrix::operator int(){
  return m_value;
}

OneByOneMatrix& OneByOneMatrix::operator ++(int i){
  m_value++;
  return *this;
}


bool OneByOneMatrix::operator==(const OneByOneMatrix& other){
  return this->m_value == other.m_value;
}

bool OneByOneMatrix::operator!=(const OneByOneMatrix& other){
  return !(*this==other);
}



bool OneByOneMatrix::instanceCountExceeds(int max)
{
  bool retval = s_instanceCounter>max;
  if (retval){
    std::cout << OneByOneMatrix::s_instanceCounter << " >  max=" << max << std::endl;
  }
  return retval;
}


