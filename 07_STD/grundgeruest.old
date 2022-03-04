// based on example from http://en.cppreference.com/w/cpp/numeric/random/rand
#include <cstdlib>
#include <iostream>
#include <ctime>

struct BinaryOctet {
  bool evenParity;
  char bitsAsDigits[bitsPerOctet];
};

int main()
{
    std::srand(std::time(0)); // use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: "
              << random_variable << '\n';
}
