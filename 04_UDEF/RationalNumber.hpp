// file: RationalNumber.hpp
#include <iostream>

struct RationalNumber{
	int zaehler;
	int nenner;
  RationalNumber(int z=0, int n=1);
  RationalNumber& operator/=(const RationalNumber&);
  RationalNumber& operator*=(const RationalNumber&);
  RationalNumber& operator=(const RationalNumber&);
  RationalNumber& operator++();     // prefix
  RationalNumber operator++(int);  // postfix
};

RationalNumber addRationalNumbers(RationalNumber left, RationalNumber right);
RationalNumber operator+ (RationalNumber left, RationalNumber right);
RationalNumber operator/ (RationalNumber left, RationalNumber right);
bool operator< (RationalNumber left, RationalNumber right);
bool operator> (RationalNumber left, RationalNumber right);
std::string as_string(RationalNumber);  // for println()
//std::ostream& operator<< (std::ostream& os, RationalNumber &toBePrinted); // for cout
