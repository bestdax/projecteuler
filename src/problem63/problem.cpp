/*
Problem page link:
https://projecteuler.net/problem=63

dax 2024-10-01 19:12:13
*/
#include "problem.h"
#include <bigint.h>

void Solution::answer()
{
	unsigned count{};

	for(BigUInt a = 1; a < 10; ++a)
	{
		unsigned exponent{1};

		while(a.power(exponent).length() == exponent)
		{
			++count;
			++exponent;
		}
	}

	print("The answer is:", count);

}
