/*
Problem page link:
https://projecteuler.net/problem=6

dax 2024-07-30 13:30:50
*/
#include "problem.h"

unsigned long Solution::square_sum_diff(unsigned cap)
{
	unsigned long sum_of_square{}, sum{};

	for(unsigned i = 1; i <= cap; ++i)
	{
		sum_of_square += i * i;
		sum += i;
	}

	return sum * sum - sum_of_square;
}

void Solution::answer()
{
	std::cout << "The answer is: " << square_sum_diff(100) << std::endl;
}
