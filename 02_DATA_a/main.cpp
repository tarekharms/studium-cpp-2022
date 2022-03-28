#include "println.hpp"


void foo(int & i)
{
    i = i + 1;
}

int main()
{
    int i = 7;
//    int* iPointer = &i;

    float a = 0.2;
    float b = 0.1;
    float c = a+b;

    std::cout << c << std::endl;
    println((a+b));

    foo(i);
    println(i);

    return 0;
}
