//  file main_mp4_OO_b.cpp
#include <iostream>
#include <cassert>

//=======================================


struct ValueType {
  ValueType(int initialValue=0);
  ~ValueType();
private:
  int _someValue;
};

class BaseEntity {
  ValueType _value;
public:
  BaseEntity();
  BaseEntity(int initialValue);
  virtual ~BaseEntity();
};

class DerivedEntity : public BaseEntity {
public:
  DerivedEntity();
  ~DerivedEntity();
};

ValueType::ValueType(int initialValue)
: _someValue(initialValue)
{
  std::cout << "ValueType::ValueType(" << _someValue << ")" << std::endl;
}

ValueType::~ValueType(){
  std::cout << "ValueType::~ValueType()" << std::endl;
}

BaseEntity::BaseEntity()
: _value(0)
{
  std::cout << "BaseEntity::BaseEntity()" << std::endl;
}

BaseEntity::BaseEntity(int initialValue)
: _value(initialValue)
{
  std::cout << "BaseEntity::BaseEntity(int)" << std::endl;
}

BaseEntity::~BaseEntity(){
  std::cout << "BaseEntity::~BaseEntity(" << std::endl;
}

DerivedEntity::DerivedEntity()
: BaseEntity(17)
{
  std::cout << "DerivedEntity::DerivedEntity()" << std::endl;
}

DerivedEntity::~DerivedEntity(){
  std::cout << "DerivedEntity::~DerivedEntity()" << std::endl;
}


class Bar {
  BaseEntity *_helperObject;
public:
  Bar();
  ~Bar();
};

Bar::Bar(){
  _helperObject =  new DerivedEntity();
}

Bar::~Bar(){
  delete _helperObject;
}


struct StackObject {
private:
    void* operator new(size_t ) noexcept {
        bool noStackObjectOnHeap = false;
        assert(noStackObjectOnHeap);
        return nullptr;
    }
};


struct A : public StackObject {
    A(){std::cout << "+A ";}
    //A(const A&){std::cout << "*A";}
    ~A(){std::cout << "-A ";}
};

struct B : public StackObject {
    B(){std::cout << "+B ";}
    //B(const B&){std::cout << "*B";}
    ~B(){std::cout << "-B ";}
};


struct C : public StackObject {
    C(){std::cout << "+C ";}
    //C(const C&){std::cout << "*C";}
    ~C(){std::cout << "-C ";}
};

class HeapObject{
public:
    void*   operator new (size_t size);
    HeapObject();
    virtual ~HeapObject();
    static bool assertionsHold();
protected:
private:
    static int ctorCount;
    static int dtorCount;
    static int newCount;
    //    static void remove(HeapObject *);
    HeapObject(const HeapObject&) = delete;
    HeapObject& operator=(const HeapObject&) = delete;
};

int HeapObject::ctorCount = 0;
int HeapObject::dtorCount = 0;
int HeapObject::newCount  = 0;

void*   HeapObject::operator new (size_t size){
    newCount++;
    return new char[size];
}

HeapObject::HeapObject(){
    ctorCount++;
}

HeapObject::~HeapObject(){
    dtorCount++;
}

bool HeapObject::assertionsHold(){
    assert(ctorCount == newCount);   // all objects have been allocated on heap
    assert(ctorCount == dtorCount);  // all objects have been deleted
    return true;
}


class K : public HeapObject
{
public:
  K(){std::cout << "+K ";}
    ~K(){std::cout << "-K ";}
};

class L {
public:
  L(){std::cout << "+L ";}
  ~L(){std::cout << "-L ";}
};


class M {
public:
    M(){std::cout << "+M ";}
    ~M(){std::cout << "-M ";}
};



int main(/*int argc, const char * argv[]*/) {
  Bar * bar = new Bar();
  // ...
  delete bar; // implies "delete _helperObject";

  BaseEntity *obj = new DerivedEntity();
  delete obj;

  {
    C val_c;               // val => value
    K* p2o_k = new K();    // p2o => pointer to object
    delete p2o_k;
  }

  HeapObject::assertionsHold();
  std::cout << " ENDE" << std::endl;
  return 0;
}



