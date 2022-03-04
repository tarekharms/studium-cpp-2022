// file VehicleFactory.cpp
#include "VehicleFactory.hpp"
#include "Car.hpp"
#include "Truck.hpp"

/*
  A factory creates objects based un runtime information 
  a) within the process (data values, Types i.e.e virtual methods)
  b) input from files or user input
  Th is simple Factory differentiates only based on a value.
 */
Vehicle* vehicleForPayload(std::string model, int weight){
  if (weight < 3500){
    return new Car(model, weight);
  }else{
    return new Truck(model, weight);
  }
}

