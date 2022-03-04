//  LifeCycleProbe.cpp
//  DoubleDelete

#include "LifeCycleProbe.hpp"
#include <iostream>

LifeCycleProbe::LifeCycleProbe(){
  this->id=0;
  std::cout << "default ctor id=" << id << std::endl;
#ifdef HAS_RESOURCE_POINTER
  resource = new int;
#endif
}

LifeCycleProbe::LifeCycleProbe(int id){
  this->id=id;
  std::cout << "ctor(int) id=" << id << std::endl;
#ifdef HAS_RESOURCE_POINTER
  resource = new int;
#endif
}


LifeCycleProbe::LifeCycleProbe(const LifeCycleProbe& other){
  std::cout << "copy ctor (source id=" << other.id
            << " to id=" << other.id + 9 << ")" << std::endl;
  this->id=other.id + 9;
#ifdef HAS_RESOURCE_POINTER
  this->resource = other.resource;
#endif
}

LifeCycleProbe& LifeCycleProbe::operator=(const LifeCycleProbe& other){
  std::cout << "assignment (old id=" << this->id
            << " source id=" << other.id 
            << " new id=" << other.id + 11 << ")" << std::endl;
  this->id = other.id + 11;
  return *this;
}


LifeCycleProbe::~LifeCycleProbe(){
  std::cout << "dtor id=" << id << std::endl;
#ifdef HAS_RESOURCE_POINTER
  std::cout << "deleting resource" << *resource << std::endl;
  delete resource;
#endif
}

void LifeCycleProbe::printID(){
  std::cout << "printID() id=" << id << std::endl;
}


