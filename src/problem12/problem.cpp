/*
Problem page link:
https://projecteuler.net/problem=12

dax 2024-08-02 17:41:31
*/
#include "problem.h"
#include <cmath>

void Solution::next_triangle()
{
	++nth;
	triangle += nth;
}

unsigned Solution::count_factors(unsigned long n)
{
	unsigned count{};
	auto root = std::floor(std::sqrt(n));

	for(unsigned i = 1; i <= root; ++i)
	{
		if(n % i == 0) count += 2;
	}

	return count;
}

void Solution::answer()
{
	while(true)
	{
		next_triangle();

		if(count_factors(triangle) > 500) break;
	}

	std::cout << "The answer is: " << triangle << std::endl;
}
