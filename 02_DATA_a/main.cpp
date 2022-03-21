#include "println.hpp"


void foo(int* i)
{
    *i = *i + 1;
}

int main()
{
    int i = 7;
    int* iPointer = &i;

    foo(iPointer);

    return 0;
}
