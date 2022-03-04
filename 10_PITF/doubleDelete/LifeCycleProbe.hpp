//  LifeCycleProbe.hpp
//  DoubleDelete

#ifndef LifeCycleProbe_hpp
#define LifeCycleProbe_hpp

//#define HAS_RESOURCE_POINTER

class LifeCycleProbe {
  int id;
#ifdef HAS_RESOURCE_POINTER
  int *resource;
#endif
public:
  LifeCycleProbe();
  LifeCycleProbe(int id);
  LifeCycleProbe(const LifeCycleProbe&);
  LifeCycleProbe& operator=(const LifeCycleProbe&);
  ~LifeCycleProbe();
  void printID();
};

#endif 
