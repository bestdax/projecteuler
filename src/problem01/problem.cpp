/*
Problem page link:
https://projecteuler.net/problem=1

dax 2024-09-06 16:33:46
*/
#include "problem.h"

void Solution::answer()
{
	unsigned sum{};
	for(unsigned i = 1; i < 1000; ++i)
	{
		if(i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	std::cout << "The answer is: " << sum << std::endl;
}
