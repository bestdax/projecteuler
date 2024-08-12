/*
Problem page link:
https://projecteuler.net/problem=45

dax 2024-08-12 15:42:23
*/
#include "problem.h"
#include "number.h"

void Solution::answer()
{
	unsigned n = 144;

	while(true)
	{
		unsigned long hex = n * (2 * n - 1);

		if(dax::is_triangle(hex) && dax::is_pentagonal(hex))
		{
			std::cout << "The answer is: " << hex << std::endl;
			break;
		}

		++n;
	}
}
