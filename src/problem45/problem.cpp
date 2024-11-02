/*
Problem page link:
https://projecteuler.net/problem=45

dax 2024-09-19 11:11:23
*/
#include "problem.h"
#include <numutils.h>

void Solution::answer()
{
	uint n = 143;

	while(true)
	{
		++n;
		ulong h = n * (2 * n - 1);

		if(dax::is_triangle(h) && dax::is_pentagonal(h))
		{
			std::cout << "The answer is: " << h << std::endl;
			return;
		}
	}

}
