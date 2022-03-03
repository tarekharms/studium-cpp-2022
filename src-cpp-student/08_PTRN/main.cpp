#include "Car.hpp"
#include "Truck.hpp"
#include "Logger.hpp"
#include "VehicleFactory.hpp"

#include <iostream>
#include <vector>

void workOnCopy_naive(std::vector<Vehicle*> vehicles){
  std::vector<Vehicle*> tempVec;
  for (size_t i=0; i<vehicles.size(); i++){
    Vehicle * currentVehicle = vehicles[i];
    Car*   carToCopy   = dynamic_cast<Car*>(currentVehicle);  // RTTI type check
    Truck* truckToCopy = dynamic_cast<Truck*>(currentVehicle);// may be nullptr
    if(carToCopy){
      tempVec.push_back(new Car(carToCopy->model(), carToCopy->maxWeight())); // type dependency to Car
    }else if(truckToCopy){
      tempVec.push_back(new Truck(truckToCopy->model(), truckToCopy->payload_kg())); // type dependecy
    }else{
      // TODO: what do we do here?
      // Did someone add a new class to the code base?
      return; // BUG: copies aren't free'd
    }
  }
  // work on copies ...
  // ...
  for(auto vehi : tempVec){
    std::cout << vehi->model() << " " << vehi->payload_kg() << " kg" << std::endl;
  }
  for (size_t i=0; i<tempVec.size(); i++){
    delete tempVec[i];
  }
  tempVec.clear();
}

void workOnCopy_smart(std::vector<Vehicle*> vehicles){ // uses RAII, virtual ctor
  
  class RAIIvector { // local RAII helper class
  public:
    std::vector<Vehicle*> tempVec;
    ~RAIIvector(){
      for(auto vehi : tempVec){
        delete vehi;
      }
      tempVec.clear();
    }
  };
  RAIIvector rv;
  
  for(auto vehi : vehicles){
    rv.tempVec.push_back(vehi->clone());
  }
  // work on copies ...
  // ...
  for(auto vehi : rv.tempVec){
    std::cout << vehi->model() << " " << vehi->payload_kg() << " kg" << std::endl;
  }
  // compiler WILL invoke RAIIvector::~RAIIvector() here
}


int main(/*int argc, const char * argv[]*/) {
  std::vector<Vehicle*> vehicles;
  vehicles.push_back(vehicleForPayload("Volkswagen Golf", 900)); // use factory for construction
  vehicles.push_back(vehicleForPayload("Magirus Deutz", 18*1000));
  Logger::getInstance()->log("work naively", __FILE__, __LINE__);
  workOnCopy_naive(vehicles);
  Logger::getInstance()->log("work smartly", __FILE__, __LINE__);
  workOnCopy_smart(vehicles);
  return 0;
}
