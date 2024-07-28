/*
Problem page link:
https://projecteuler.net/problem=1

dax 2024-07-28 08:09:44
*/
#include "problem.h"

long Solution::sum_of_multiples_of_three_and_five(unsigned cap)
{
	long sum{};

	for(unsigned i = 1; i < cap; ++i)
	{
		if(i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_multiples_of_three_and_five(1000) << std::endl;
}
