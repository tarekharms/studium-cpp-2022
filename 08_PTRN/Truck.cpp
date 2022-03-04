#include "Truck.hpp"

Truck::Truck(std::string model, int payload_kg)
: Vehicle(model)
{
  _payload_kg = payload_kg;
}

int Truck::payload_kg(){
  return _payload_kg;
}


Vehicle* Truck::clone(){
  return new Truck(model(),_payload_kg);
}
