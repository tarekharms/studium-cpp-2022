//  main.cpp
//  objectSlicing

#include <iostream>
#include <vector>

class Base{
  int _a;
public:
  Base(){}
  virtual ~Base() {}
  Base(int aa) :_a(aa) {}
  int value_a();
  virtual int value_virtual();
};

int Base::value_a(){
  return _a;
}

int Base::value_virtual(){
  return _a;
}

class Derived : public Base {
  int _b;
public:
  Derived(int x, int y) : Base(x), _b(y) {}
  virtual int value_virtual();
};

int Derived::value_virtual(){
  return _b;
}

void passByPointer(Base* bp){
  std::cout << "->value_a()        = " << bp->value_a() << std::endl;
  std::cout << "->value_virtual()  = " << bp->value_virtual() << std::endl;
}

void passByValue(Base b){
  std::cout << ".value_a()        = " << b.value_a() << std::endl;
  std::cout << ".value_virtual()  = " << b.value_virtual() << std::endl;
}

int main(int argc, const char * argv[]) {
  Derived d(1,2);
  
  std::cout << "d.value_virtual() = " << d.value_virtual() << std::endl;

  std::cout << std::endl << "pass pointer to base class " << std::endl;
  passByPointer(&d); // pass pointer to base class

  std::cout << std::endl << "pass by value (i.e. object of class Base) " << std::endl;
  passByValue(d);  // pass Base-object by value -> object slicing: d is "transformed" int an object of class Base
  
  std::cout << std::endl << "store Derived objects in std::vector<Base>" << std::endl;
  std::vector<Base> v;
  v.push_back(d); // object slicing
  std::cout << ".value_a()        = " << v[0].value_a() << std::endl;
  std::cout << ".value_virtual()  = " << v[0].value_virtual() << std::endl;
  
  return 0;
}



