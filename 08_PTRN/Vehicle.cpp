#include "Vehicle.hpp"

Vehicle::Vehicle(std::string model){
  this->_model = model;
}

Vehicle::~Vehicle(){
}

std::string Vehicle::model(){
  return _model;
}



