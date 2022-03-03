// file Logger.cpp
#include "Logger.hpp"

Logger* Logger::_theInstance = nullptr;

Logger* Logger::getInstance(){
  if (!_theInstance){
    _theInstance = new StdoutLogger();
  }
  return _theInstance;
}

void StdoutLogger::log(std::string message, std::string file, int line){
  std::cerr << message << " in " << file << " line " << line << std::endl;
}
