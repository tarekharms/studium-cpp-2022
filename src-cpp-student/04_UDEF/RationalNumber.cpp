// file: RationalNumber.cpp
#include "RationalNumber.hpp"

RationalNumber addRationalNumbers(RationalNumber left, RationalNumber right){
	RationalNumber result;
	// add left and right
  if(left.nenner == right.nenner){
    result = RationalNumber(left.nenner+right.nenner, left.nenner);
  }else{
    int z = left.zaehler * right.nenner + left.nenner * right.zaehler;
    int n = left.nenner * right.nenner;
    // TODO: simplify quotient
    result = RationalNumber(z, n);
  }
	return result;
}

RationalNumber::RationalNumber(int z, int n){
  this->zaehler=z;
  this->nenner=n;
}

RationalNumber& RationalNumber::operator=(const RationalNumber& other){
  this->zaehler=other.zaehler;
  this->nenner=other.nenner;
  return *this;
}

RationalNumber& RationalNumber::operator/=(const RationalNumber& other){
  this->zaehler *= other.nenner;
  this->nenner  *= other.zaehler;
  return *this;
}

RationalNumber& RationalNumber::operator*=(const RationalNumber& other){
  this->zaehler *= other.zaehler;
  this->nenner  *= other.nenner;
  return *this;
}

RationalNumber& RationalNumber::operator++(){     // prefix
  zaehler += 1;
  return *this;
}

RationalNumber RationalNumber::operator++(int){  // postfix
  RationalNumber result = *this;
  return ++result;
}

RationalNumber operator+ (RationalNumber left, RationalNumber right){
	return addRationalNumbers(left, right);
}

bool operator< (RationalNumber left, RationalNumber right){
  return (1.0*left.zaehler/left.nenner)<(1.0*right.zaehler/right.nenner);
}

bool operator> (RationalNumber left, RationalNumber right){
  return (1.0*left.zaehler/left.nenner)>(1.0*right.zaehler/right.nenner);
}


// for println()
std::string as_string(RationalNumber r){
  std::string result = "(";
  result += std::to_string(r.zaehler);
  result += "/";
  result += std::to_string(r.nenner);
  result += ")";
  return result;
}

/*std::ostream& operator<< (std::ostream& os, RationalNumber &toBePrinted){
	os << "(" << toBePrinted.zaehler << "/"
	<< toBePrinted.nenner << ")";
	return os;
}*/
