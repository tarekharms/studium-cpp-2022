// based on example from http://en.cppreference.com/w/cpp/numeric/random/rand
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>
#include "println.hpp"
#include "FixedPoint.hpp"

int main()
{
  std::vector<FixedPoint> fixedNums;
  std::srand(std::time(0)); // use current time as seed for random generator
  fixedNums.push_back(std::rand());
}
