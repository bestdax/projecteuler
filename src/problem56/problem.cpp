/*
Problem page link:
https://projecteuler.net/problem=56

dax 2024-09-24 13:29:06
*/
#include "problem.h"
#include <bigint.h>

void Solution::answer()
{
	BigUInt max{};

	for(BigUInt a = 1; a < 100; ++a)
		for(unsigned b = 1; b < 100; ++b)
		{
			auto c = a.power(b);
			auto digital_sum = c.digital_sum();

			if(digital_sum > max)
				max = digital_sum;
		}

	std::cout << "The answer is: " << max << std::endl;
}
