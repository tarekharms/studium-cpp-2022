#include "println.hpp"

int polynom1(int x);

int polynom2(int x)
{
    return x * x - 1; 
}

int numZeros(int start, int end)
{
    int anzahl = 0;

    for(int i = start; i <= end; i++)
    {
        if(polynom2(i) == 0)
        {
            anzahl++;
        }
    }

    return anzahl;
}


int main()
{
    int summe = 0;

    int i = 0;
    while(i <= 10)
	{
        summe += polynom1(i);
		println("y(", i, ")=", polynom1(i));
        println("f(", i, ")=", polynom2(i));
        i++;
	}

    println("Summe y(x): ",summe);
    
    println("Anzahl Nullstellen y(x) von -20 bis 20: ", numZeros(-20, 20));

	return 0;
}

int polynom1(int x)
{
	return 4 * x * x + 6 * x - 5;
}
