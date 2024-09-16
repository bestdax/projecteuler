/*
Problem page link:
https://projecteuler.net/problem=39

dax 2024-09-16 15:08:36
*/
#include "problem.h"

void Solution::answer()
{
	unsigned max{};
	unsigned max_p{};

	for(unsigned p = 12; p <= 1000; ++p)
	{
		unsigned count{};

		for(unsigned a = 1; a < p / 2; ++a)
			for(unsigned b = a; (p - a) / 2; ++b)
			{
				auto c = p - a - b;

				if(c < a || c < b) break;

				if(c * c == b * b + a * a)
					++count;
			}

		if(count > max)
		{
			max = count;
			max_p = p;
		}
	}

	std::cout << "The answer is: " << max_p << std::endl;
}
