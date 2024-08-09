/*
Problem page link:
https://projecteuler.net/problem=27

dax 2024-08-09 08:34:23
*/
#include "problem.h"
#include "number.h"

void Solution::answer()
{
	unsigned max{};
	int maxa{}, maxb{};

	for(int a = -999; a < 1000; ++a)
		for(int b = -1000; b <= 1000; ++b)
		{
			unsigned n{};

			while(dax::is_prime(n * n + a * n + b)) ++n;

			if(n > max)
			{
				maxa = a, maxb = b;
				max = n;
			}
		}

	std::cout << "The answer is: " << maxa * maxb << std::endl;
}
