#include "println.hpp"
#include <limits>
#include <cstdint>

int main()
{
  println("type\t sizeof\t\t lowest\t\t\t\t highest\n");
  println("int   \t ",sizeof(int), "\t\t",
          std::numeric_limits<int>::lowest(), "\t\t\t",
          std::numeric_limits<int>::max());
  println("long  \t ",sizeof(long), " \t\t",
          std::numeric_limits<long>::lowest(), '\t',
          std::numeric_limits<long>::max());
  println("uint32_t ",sizeof(uint32_t), "\t\t\t",
          std::numeric_limits<uint32_t>::lowest(), "\t\t\t",
          std::numeric_limits<uint32_t>::max());
  println("float \t ",sizeof(float), "\t\t",
          std::numeric_limits<float>::lowest(), "\t\t\t",
          std::numeric_limits<float>::max());
  println("double\t ",sizeof(double), "\t\t",
          std::numeric_limits<double>::lowest(), "\t\t\t",
          std::numeric_limits<double>::max());
  }

