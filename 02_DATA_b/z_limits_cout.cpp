#include <limits>
#include <iostream>

int main()
{
  std::cout << "type\tsizeof\tlowest\t\thighest\n";
  std::cout << "float\t" << sizeof(float) << '\t'
            << std::numeric_limits<float>::lowest() << '\t'
            << std::numeric_limits<float>::max() << '\n';
  std::cout << "double\t" << sizeof(double) << '\t'
            << std::numeric_limits<double>::lowest() << '\t'
            << std::numeric_limits<double>::max() << '\n';
  std::cout << "int\t" << sizeof(int) << '\t'
            << std::numeric_limits<int>::lowest() << '\t'
            << std::numeric_limits<int>::max() << '\n';
  std::cout << "long\t" << sizeof(long) << '\t'
            << std::numeric_limits<long>::lowest() << '\t'
            << std::numeric_limits<long>::max() << '\n';
}

