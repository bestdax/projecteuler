/*
Problem page link:
https://projecteuler.net/problem=27

dax 2024-09-12 11:13:46
*/
#include "problem.h"
#include <prime.h>

void Solution::brutal_solution()
{
	uint max{};
	int max_a{}, max_b{};

	for(int a = -999; a < 1000; ++a)
		for(int b = -1000; b <= 1000; ++b)
		{
			uint n = 0;

			while(dax::is_prime_improved(n * n + n * a + b))
			{
				++n;
			}

			if(n > max)
			{
				max = n;
				max_a = a, max_b = b;
			}
		}

	std::cout << "The answer is: " << max_a * max_b << std::endl;
}

void Solution::answer()
{
	auto is_prime = dax::sieve_of_eratosthenes(1000);
	uint max{};
	int max_a{}, max_b{};

	for(uint b = 0; b <= 1000; ++b)
	{
		if(is_prime[b])
		{
			for(int a = -999; a < 1000; ++a)
			{
				if((a + b) % 2 == 0)
				{
					uint n = 0;

					while(dax::is_prime_improved(n * n + a * n + b))
					{
						++n;
					}

					if(n > max)
					{
						max = n;
						max_a = a, max_b = b;
					}
				}
			}
		}
	}

	std::cout << "The answer is: " << max_a * max_b << std::endl;
}
