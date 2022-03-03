// file main_mp5_POLY.cpp
#include <iostream>
#include <vector>

class Base {
public:
  void           overriddenMethod();
  void           overriddenMethod(int);
  void           overriddenMethod(std::string);
  void           nonVirtualMethod(void);
  virtual void      virtualMethod(void);
  virtual ~Base(){}
  /*
  virtual void  virtualAndOverridden(void);
  virtual void  virtualAndOverridden(int);
  virtual void  virtualAndOverridden(std::string);*/
};

class Derived_1 : public Base {
public:
  Derived_1();
  ~Derived_1();
  void           nonVirtualMethod(void);
  virtual void      virtualMethod(void);
  
/*  virtual void  virtualAndOverridden(void);
  virtual void  virtualAndOverridden(int);
  virtual void  virtualAndOverridden(std::string);*/
};

class Derived_2 : public Derived_1 {
public:
  void           nonVirtualMethod(void);
  virtual void      virtualMethod(void);
};

// see https://isocpp.org/wiki/faq/strange-inheritance#calling-virtuals-from-ctors
Derived_1::Derived_1(){
  virtualMethod();                     // 6a
}

Derived_1::~Derived_1(){
  virtualMethod();                     // 6b
}

// -------------------
void    Base::overriddenMethod(void){
  std::cout << "Base::overriddenMethod(void)" << std::endl;
}

void    Base::overriddenMethod(int){
  std::cout << "Base::overriddenMethod(int)" << std::endl;
}

void    Base::overriddenMethod(std::string){
  std::cout << "Base::overriddenMethod(std::string)" << std::endl;
}

void    Base::nonVirtualMethod(void){
  std::cout << "Base::nonVirtualMethod(void)" << std::endl;
}

void    Base::virtualMethod(void){
  std::cout << "Base::virtualMethod" << std::endl;
}


/*
void    Base::virtualAndOverridden(void){
  std::cout << "Base::virtualAndOverridden(void)" << std::endl;
}

void    Base::virtualAndOverridden(int){
  std::cout << "Base::virtualAndOverridden(int)" << std::endl;
}

void    Base::virtualAndOverridden(std::string){
  std::cout << "Base::virtualAndOverridden(std::string)" << std::endl;
}
*/

// -------------------
void    Derived_1::nonVirtualMethod(void){
  std::cout << "Derived_1::nonVirtualMethod" << std::endl;
}
void    Derived_1::virtualMethod(void){
  std::cout << "Derived_1::virtualMethod" << std::endl;
}


/*
void    Derived_1::virtualAndOverridden(void){
  std::cout << "Derived_1::virtualAndOverridden(void)" << std::endl;
}

void    Derived_1::virtualAndOverridden(int){
  std::cout << "Derived_1::virtualAndOverridden(int)" << std::endl;
}

void    Derived_1::virtualAndOverridden(std::string){
  std::cout << "Derived_1::virtualAndOverridden(std::string)" << std::endl;
}
*/


// -------------------
void    Derived_2::nonVirtualMethod(void){
  std::cout << "Derived_2::nonVirtualMethod" << std::endl;
}
void    Derived_2::virtualMethod(void){
  std::cout << "Derived_2::virtualMethod" << std::endl;
}



/*
 illustrates binding of method invocations
 compile time vs. run time binding
 */

void foobar(void){
  
  std::cout << "6a) ";
  Derived_2* pR = new Derived_2();
  
  Base*      pBase      = pR;
  Derived_1* pDerived_1 = pR;
  Derived_2* pDerived_2 = pR;
  
  std::cout << "1) ";
  pBase->virtualMethod();                 // 1)
  
  std::cout << "2) ";
  pBase->nonVirtualMethod();              // 2)
  
  std::cout << "3) ";
  pDerived_2->virtualMethod();            // 3)
  
  std::cout << "4) ";
  pDerived_2->nonVirtualMethod();         // 4)
  
  std::cout << "5) ";
  static_cast<Base*>(pDerived_2)->nonVirtualMethod(); // 5)
  
  std::cout << "7) ";
  static_cast<Derived_1*>(pDerived_2)->nonVirtualMethod(); // 7)
  
  std::cout << "8) ";
  pDerived_1->nonVirtualMethod();         // 8)
  
  std::cout << "9) ";
  pDerived_1->virtualMethod();            // 9)
  
  std::cout << "10a) ";
  pBase->Base::virtualMethod();           // 10a)
  
  std::cout << "10b) ";
  pDerived_2->Derived_1::virtualMethod(); // 10b)
  
  std::cout << "11 ";
  pDerived_2->overriddenMethod(17);       // 11)
  
  std::cout << "12 ";
  pDerived_2->overriddenMethod();         // 12)
  
  std::cout << "13 ";
  pDerived_2->overriddenMethod(std::string("x")); // 13)
  
  std::cout << "14 ";
  dynamic_cast<Derived_2*>(pBase)->virtualMethod(); // 14)
  
  std::cout << "15 ";
  Base* baseObject    = new Base();
  Derived_2* d2Object = dynamic_cast<Derived_2*>(baseObject);
  if(d2Object){                           // 15)
    std::cout << "+" << std::endl;
  }else{
    std::cout << "-" << std::endl;
  }
  
  /*
  std::cout << "16 ";
  pDerived_2->virtualAndOverridden(17);       // 16)
  
  std::cout << "17 ";
  pDerived_2->virtualAndOverridden();         // 17)
  
  std::cout << "18 ";
  pDerived_2->virtualAndOverridden(std::string("x")); // 18)
  */
  
  
  std::cout << "6b) ";
  delete pR;
}

/*
 void foo(){
 for(int i=0; i<LOOPS;i++){
 Base* ps = new Base();
 ps->nonVirtualMethod2();
 delete ps;
 }
 }
 
 void bar(int i){
 Base s;
 s.nonVirtualMethod2();
 if(i>0){
 bar(i-1);
 }
 }*/

typedef void (*funcPointer_void_void)(void);

void sing_gingle(void){
  std::cout << "gingle ";
}

void sing_bells(void){
  std::cout << "bells ";
}

void sing_surf(void){
  std::cout << "surf ";
}

void sing_safari(void){
  std::cout << "surfin safari ";
}

std::vector<funcPointer_void_void> songOfSeason(int currentTemperatureCelsius) {
  std::vector<funcPointer_void_void> result;
  
  if(currentTemperatureCelsius <= 0){
    result.push_back(sing_gingle);
    result.push_back(sing_bells);
    result.push_back(sing_gingle);
    result.push_back(sing_bells);
  }else{
    result.push_back(sing_surf);
    result.push_back(sing_surf);
    result.push_back(sing_safari);
    result.push_back(sing_surf);
    result.push_back(sing_surf);
    result.push_back(sing_safari);
  }

  return result;
}

void sing(int currentTemperatureCelsius){
  std::vector<funcPointer_void_void> song = songOfSeason(currentTemperatureCelsius);
  
  // traditional C-style for-loop
  for(size_t i=0; i<song.size(); ++i){
    song[i](); // invoke funtion (pointed to by function pointer at song[i])
  }
  std::cout << std::endl;
  
  // C++11 range-based for-loop looks better:
  for(auto func: song){
    func();
  }
  std::cout << std::endl;
}

int main(/*int argc, const char * argv[]*/) {
  
  foobar();
  
  sing(-17);
  
  /*
   std::cout << "foo " << std::endl;
   foo();
   
   std::cout << "bar " << std::endl;
   bar(LOOPS);
   */
  return 0;
}
