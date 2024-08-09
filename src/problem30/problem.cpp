/*
Problem page link:
https://projecteuler.net/problem=30

dax 2024-08-09 17:37:42
*/
#include "problem.h"
#include <cmath>

void Solution::answer()
{
	unsigned sum{};

	for(unsigned i = 2; i < 1e6; ++i)
	{
		unsigned p = i;
		unsigned digit_fifth_power {};

		while(p)
		{
			digit_fifth_power += std::pow(p % 10, 5);
			p /= 10;
		}

		if(digit_fifth_power == i) sum += i;
	}

	std::cout << "The answer is: " << sum << std::endl;
}
