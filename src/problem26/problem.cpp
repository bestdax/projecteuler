/*
Problem page link:
https://projecteuler.net/problem=26

dax 2024-09-12 08:25:26
*/
#include "problem.h"
#include <vector>
#include <algorithm>

unsigned Solution::unit_reciprocal_cycle(unsigned n)
{
	std::vector<unsigned> numerators;
	unsigned numerator = 1;

	while(true)
	{
		if(numerator % n == 0) return 0;

		auto it = std::find(numerators.begin(), numerators.end(), numerator);

		if(it != numerators.end()) return numerators.end() - it;

		if(numerator >= n)
		{
			numerator %= n;
		}
		else
		{
			numerators.push_back(numerator);
			numerator *= 10;
		}
	}
}

void Solution::answer()
{
	unsigned max{};
	unsigned number{};
	for(int i = 2; i < 1000; ++i)
	{
		auto cycle = unit_reciprocal_cycle(i);
	 if(cycle > max)
		{
			max = cycle;
			number = i;
		}
	}
	std::cout << "The answer is: " << number << '\t' << max << std::endl;
}
