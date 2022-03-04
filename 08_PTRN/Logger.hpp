// file Logger.hpp
#ifndef Logger_hpp
#define Logger_hpp

#include <iostream>

class Logger {
  static Logger* _theInstance;
public:
  virtual void log(std::string message, std::string file="", int line=0) = 0;
  static Logger* getInstance();
};

class StdoutLogger: public Logger {
public:
  void log(std::string message, std::string file="", int line=0);
};

#endif
