#include <iostream>
#include "println.hpp"


void foo(int& i)
{
   i = i + 1; 
}

int main()
{
    int i = 7;
    foo(i);
    println(i);

    float a = 0.1;
    float b = 0.2;

    float c = a + b;

    if( c == 0.3)
    {
        std::cout << "0.1 plus 0.2 ist gleich 0.3" << std::endl;;
    }
    
    float d = 0.5;
    float e = 0.25;

    float f = d + e;

    if ( f == 0.75)
    {
        std::cout << "0.5 plus 0.25 ist gleich 0.75" << std::endl;
    }

    std::cout << c << std::endl;
    return 0;
}
