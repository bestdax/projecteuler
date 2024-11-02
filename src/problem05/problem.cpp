/*
Problem page link:
https://projecteuler.net/problem=5

dax 2024-09-09 14:06:34
*/
#include "problem.h"
#include <numeric>

void Solution::answer()
{
	ulong result{1};
	for(uint i = 1; i <= 20; ++i)
	{
		result = std::lcm(i, result);
	}
	std::cout << "The answer is: " << result << std::endl;
}
