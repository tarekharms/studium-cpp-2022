#ifndef Truck_hpp
#define Truck_hpp

#include "Vehicle.hpp"


class Truck : public Vehicle {
  int _payload_kg; // max number kilograms to load
public:
  Truck(std::string model, int payload_kg);
  virtual int payload_kg();
  virtual Vehicle* clone();
  //virtual Vehicle* newInstance();
};

#endif

