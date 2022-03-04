#ifndef Car_hpp
#define Car_hpp

#include "Vehicle.hpp"


class Car : public Vehicle {
  int _maxWeight;
public:
  Car(std::string model, int maxWeight);
  int maxWeight();
  virtual int payload_kg();
  virtual Vehicle* clone();
  //virtual Vehicle* newInstance();
};


#endif 
