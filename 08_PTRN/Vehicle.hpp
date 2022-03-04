#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <iostream>

class Vehicle {
  std::string _model;
public:
  Vehicle(std::string model);
  virtual ~Vehicle();
  std::string model();
  virtual int payload_kg() = 0;
  virtual Vehicle* clone() {return nullptr;} // idiom "virtual constructor"
  //virtual Vehicle* newInstance() = 0;        // idiom "virtual constructor"
};


#endif
