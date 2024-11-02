/*
Problem page link:
https://projecteuler.net/problem=1

dax 2024-09-06 16:33:46
*/
#include "problem.h"

uint Solution::sum_of_multipliers(uint limit)
{
	uint sum{};

	for(uint i = 1; i < limit; ++i)
	{
		if(i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	return sum;
}

void Solution::answer()
{
	auto sum = sum_of_multipliers(1000);
	std::cout << "The answer is: " << sum << std::endl;
}
