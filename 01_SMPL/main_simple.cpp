#include "println.hpp"

int polynom1(int x)
{
    return 3*x*x*x - 2*x + 5;
}

int main()
{
    for(int i = 0; i <= 10; i++)
    {
        println("y(", i, ")=", polynom1(i));
    }
    return 0;
}
