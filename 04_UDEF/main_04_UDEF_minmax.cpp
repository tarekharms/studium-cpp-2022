#include "println.hpp"

#define numValues 10

// this declares an alias for type <see below>, which is called calctype
// CREATE makro is needed to create values in main()
#ifdef CALCTYPE_INT
typedef int calctype;
#define CREATE(x) x                     // no need for a constructor here
#endif

#ifdef CALCTYPE_DOUBLE
typedef double calctype;
#define CREATE(x) double(x*1.0)         // create double value from int
#endif

#ifdef CALCTYPE_RATIONAL
#include "RationalNumber.hpp"           // location 1
typedef RationalNumber calctype;        // location 2
#define CREATE(x) RationalNumber(x,1)   // use constructor to create a (temporary) value
#endif

#ifdef CALCTYPE_RGB
#include "rgbColor.hpp"           // location 1
typedef RgbColor calctype;        // location 2
#define CREATE(x) RgbColor( (x) | (x) << 8 | (x) << 16 )   // use constructor to create a (temporary) value
#endif

void printMinMax(calctype values[], int length){
  calctype minimum = values[0];
  calctype maximum = values[0];
  calctype sum = CREATE(0); // calculate average
  for(int i=1; i<length; i++){
    if (values[i] < minimum){
      minimum = values[i];
    }
    if (values[i] > maximum){
      maximum = values[i];
    }
    sum = values[i] + sum;
  }

  calctype average = sum / length;

  println("minimum=", minimum, " maximum=", maximum, " avg=", average);
}


int main(){
  calctype values[numValues];
  for(int i=0; i<numValues; i++){
    values[i] = CREATE(5+i*7);
  }
  printMinMax(values, numValues);
  return 0;
}
