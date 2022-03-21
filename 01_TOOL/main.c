#include "polynom1.h"
#include <stdio.h>

int main()
{
    for(int x = 0; x <= 20; x++)
    {
       int y = polynom1(x);
       printf("x=%d y=%d\n", x, y);
    }

    return 0;
}


