/*
Problem page link:
https://projecteuler.net/problem=56

dax 2024-08-26 07:10:20
*/
#include "problem.h"
#include "bint.h"

void Solution::answer()
{
	bint max;

	for(bint a = 1; a < 100; ++a)
		for(bint b = 1; b < 100; ++b)
		{
			auto p = a.power(b);
			max = p.digtal_sum() > max ? p.digtal_sum() : max;
		}

	std::cout << "The answer is: " << max << std::endl;
}
