/*
Problem page link:
https://projecteuler.net/problem=39

dax 2024-08-11 08:41:50
*/
#include "problem.h"

void Solution::answer()
{

	unsigned max{};
	unsigned n{};

	for(unsigned p = 12; p <= 1000; ++p)
	{
		unsigned solutions {};

		for(unsigned c = 5; c < p / 2; ++c)
		{

			for(unsigned a = 1;  a < c; ++a)
			{
				auto b = p - a - c;

				if(a * a + b * b == c * c) ++solutions;
			}

			if(solutions > max)
			{
				max = solutions;
				n = p;
			}

		}
	}

	std::cout << "The answer is: " << n << std::endl;
}
