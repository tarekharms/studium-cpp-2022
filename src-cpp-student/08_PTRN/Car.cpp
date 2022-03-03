#include "Car.hpp"

Car::Car(std::string model, int maxWeight)
: Vehicle(model)
{
  _maxWeight = maxWeight;
}

int Car::maxWeight(){
  return _maxWeight;
}

int Car::payload_kg(){
  return _maxWeight - 75 * 5; // subtract weight of passangers
}

Vehicle* Car::clone(){
  return new Car(model(), _maxWeight);
}
