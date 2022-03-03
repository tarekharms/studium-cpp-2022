#include <iostream>
#include <cassert>
#include <vector>
#include "println.hpp"


struct StackObject {
private:
    void* operator new(size_t size) noexcept {
        bool noStackObjectOnHeap = false;
        assert(noStackObjectOnHeap);
        return nullptr;
    }
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

typedef double MoneyUnitType; // should be fixed point class

class Cash : public HeapObject {
public:
  MoneyUnitType _value;
  Cash(MoneyUnitType value) : _value(value){}
};

typedef std::vector<Cash*> Wallet;

Wallet consumerWallet_A;
Wallet consumerWallet_B;

Cash * createCashFor(int i){
  return new Cash(static_cast<MoneyUnitType>(i));
}

void flushWallet(Wallet& toBeEmptied){ // should be in dtor of sorrounding class
  for(int i=0; i<toBeEmptied.size();i++){
    delete toBeEmptied[i];
  }
  toBeEmptied.clear();
}

void setup(){
  println("setup()...");
  // fill A's wallet
  for(int i=1;i<=10;i++){
    consumerWallet_A.push_back(createCashFor(i));
  }
  println("setup() - done");
}

void simulate(){
  println("simulate()...");
  // move A's last Cash object to B's wallet
  Cash * toBeMoved = consumerWallet_A.back();
  consumerWallet_B.push_back(toBeMoved);
  consumerWallet_A.pop_back();
  
  // delete A's last Cash object
  delete consumerWallet_A.back();
  consumerWallet_A.pop_back();
  println("simulate() - done");
}

void teardown(){
  println("cleaning up...");
  flushWallet(consumerWallet_A);
  flushWallet(consumerWallet_B);
  println("cleaning up - done");
}


int main(int argc, const char * argv[]) {
  setup();
  simulate();
  teardown();
  
  HeapObject::assertionsHold();
  std::cout << " ---- errors above? ----" << std::endl;
  return 0;
}



