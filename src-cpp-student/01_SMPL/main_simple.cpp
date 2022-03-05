#include "println.hpp"

int polynom1(int x)
{
	return 4 * x * x + 6 * x - 5;
}

int main()
{
	for(int i = 0; i < 11; i++)
	{
		println("y(", i, ")=", polynom1(i));
	}

	return 0;
}
