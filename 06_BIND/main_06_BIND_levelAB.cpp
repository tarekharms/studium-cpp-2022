#include "println.hpp"

class Base {
public:
          void   nonVirtualMethod(void);
  virtual void      virtualMethod(void);
  virtual ~Base(){}
};

class Derived : public Base {
public:
          void   nonVirtualMethod(void);
  virtual void      virtualMethod(void);
  virtual ~Derived(){}
};


// -------------------

void    Base::nonVirtualMethod(void){
  std::cout << "Base::nonVirtualMethod" << std::endl;
}

void    Base::virtualMethod(void){
  std::cout << "Base::virtualMethod" << std::endl;
}



// -------------------
void    Derived::nonVirtualMethod(void){
  println("Derived::nonVirtualMethod");
}
void    Derived::virtualMethod(void){
  println("Derived::virtualMethod");
}




/*
 illustrates binding of method invocations
 compile time vs. run time binding
 */

void lookupMethods(void){
  Derived* theObject = new Derived();
  Base* theDerivedObject = new Derived();
  Base* theBaseObject = new Base();
  
  Base*      pBase  = theObject;
  Derived* pDerived = theObject;
  
  print("2) ");
  pBase->nonVirtualMethod();              // 2)
  
  print("8) ");
  pDerived->nonVirtualMethod();         // 8)
  
  print("5) ");
  static_cast<Base*>(pDerived)->nonVirtualMethod(); // 5)
  
  print("1) ");
  pBase->virtualMethod();                 // 1)
  
  print("9) ");
  pDerived->virtualMethod();            // 9)

  print("10_0) ");
  static_cast<Derived*>(theBaseObject)->virtualMethod();
  
  print("10_1) ");
  static_cast<Base*>(pDerived)->virtualMethod();           // 10_1)

  print("10a) ");
  pBase->Base::virtualMethod();           // 10a)

  
  print("15 :");
  Base* baseObject    = new Base();
  Derived* d2Object = dynamic_cast<Derived*>(baseObject);
  if(d2Object){                           // 15)
    println("ok, lets invoke methods on d2Object!");
    d2Object->virtualMethod();
  }else{
    println("I'm sorry, Dave. I'm afraid I can't do that.");
  }
    
  delete theObject;
}

void foobar()
{
  Derived* theObject = new Derived();

  Base*      pBase  = theObject;
  Derived* pDerived = theObject;

  pBase->virtualMethod();
  pDerived->virtualMethod();

  pBase->nonVirtualMethod();
  static_cast<Base*>(pDerived)->nonVirtualMethod();
}


int main(/*int argc, const char * argv[]*/) {  
  //lookupMethods();
  foobar();
  return 0;
}
