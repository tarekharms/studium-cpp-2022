#include "polynom1.h"
#include "polynom2.h"
#include "poly_all.h"
#include <stdio.h>

int main()
{
    for(int x = 0; x <= 20; x++)
    {
       int y = poly_all(x);
       printf("x=%d y=%d\n", x, y);
    }

    return 0;
}


