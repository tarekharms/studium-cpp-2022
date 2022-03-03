#include <typeinfo>
#include "println.hpp"


//======================================

class Vehicle {
protected:
    int _numSeats;
public:
    Vehicle(int numSeats=0);// may serve as default ctor (i.e. no arguments)
    virtual ~Vehicle();
    virtual int payload() = 0;
    int numSeats();         // a 'getter' method to get a value; no 'setter' here
};

//======================================

class Car : public Vehicle {
protected:
    int _maxWeight;     // german: zulässiges Gesamtgewicht
public:
    Car(int numSeats, int maxWeight);
    virtual int payload();
    
};

//======================================

class Truck : public Vehicle {
protected:
    int _payload;
    double _volume;
public:
    Truck(int numSeats, int payload, double volume);
    virtual int payload();
};

//======================================

Vehicle::Vehicle(int numSeats){
    _numSeats = numSeats;
}

Vehicle::~Vehicle(){
    println("destroying a Vehicle");
}

int Vehicle::numSeats(){
    return _numSeats;
}

//======================================

Car::Car(int numSeats, int maxWeight){
    _numSeats = numSeats;
    _maxWeight = maxWeight;
}

int Car::payload(){
    return _maxWeight - (_numSeats*75);
}

//======================================

Truck::Truck(int numSeats, int payload, double volume){
    _numSeats = numSeats;
    _payload = payload;
    _volume = volume;
}

int Truck::payload(){
    return _payload;
}

//======================================


void printVehicleInfo(Vehicle* v){
    println("typeid=`", typeid(*v).name(), "`",
            " numSeats=", v->numSeats(), // invoke via pointer to base class
            " payload=", v->payload());  // invoke via pointer to base class
}


//======================================
// for println()
std::string as_string(Vehicle* v){
    return v ? // check for null pointer
    std::string("typeid=`") // otherwise, we get "error: invalid operands to binary expression ('const char *' and 'const char *')"
            + typeid(*v).name() + "`"
            + " numSeats=" + std::to_string(v->numSeats())
            + " payload="  + std::to_string(v->payload()) : "nullptr";
}

//======================================

int main(/*int argc, const char * argv[]*/) {
    Car* c   = new Car(5, 1000);    // create a new object of class Car in free store
    Truck* t = new Truck(3, 7500, 80000.0);
    println("1 --------- ");
    println("c: numSeats=", c->numSeats(), " payload=", c->payload());
    println("t: numSeats=", t->numSeats(), " payload=", t->payload());
    println("");
    println("2 --------- ");
    Vehicle* v = nullptr;             
    v = c;                      // a Car `is a` Vehicle => implicitly convertible
    printVehicleInfo(v);        // println(v); does work, too
    v = t;                      // a Truck `is a` Vehicle => implicitly convertible
    printVehicleInfo(v);        // println(v); does work, too    
    // release memory occupied by t,c for use by future objects created by `new`
    // do NOT release v  -- it is only an alias
    delete t;
    delete c;
    return 0;
}
