/*
Problem page link:
https://projecteuler.net/problem=5

dax 2024-07-30 08:58:54
*/
#include "problem.h"
#include "number.h"

unsigned long Solution::smallest_multiple(unsigned range)
{

	unsigned long result{1};

	for(int i = 1; i <= range; ++i)
	{
		result = dax::lcm(result, i);
	}

	return result;
}

void Solution::answer()
{

	std::cout << "The answer is: " << smallest_multiple(20) << std::endl;
}
