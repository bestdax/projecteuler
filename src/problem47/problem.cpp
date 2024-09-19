/*
Problem page link:
https://projecteuler.net/problem=47

dax 2024-09-19 13:03:31
*/
#include "problem.h"

unsigned Solution::count_distinct_prime_factors(unsigned long n)
{
	unsigned count{};

	unsigned i = 2;

	while(i <= n)
	{
		if(is_prime[i] && n % i == 0)
		{
			while(n % i == 0) n /= i;

			++count;
		}

		++i;
	}

	return count;
}

void Solution::compute_prime_factors()
{
	for(unsigned i = 2; i <= limit; ++i)
	{
		if(is_prime[i])
		{
			++prime_factor_count[i];
			unsigned j = 2;

			while(i * j <= limit)
			{
				++prime_factor_count[i * j];
				++j;
			}

		}
	}
}

void Solution::answer()
{
	unsigned n = 2;

	while(true)
	{
		bool found = true;

		for(unsigned i = 0; i < 4; ++i)
		{
			if(count_distinct_prime_factors(n + i) != 4)
			{
				n += i + 1;
				found = false;
				break;
			}
		}

		if(found)
		{
			std::cout << "The answer is: " << n << std::endl;
			return;
		}

	}

}

void Solution::answer2()
{
	compute_prime_factors();

	for(unsigned i = 2; i <= limit - 3; ++i)
	{
		if(
		    prime_factor_count[i] == 4 &&
		    prime_factor_count[i + 1] == 4 &&
		    prime_factor_count[i + 2] == 4 &&
		    prime_factor_count[i + 3] == 4
		)
		{
			std::cout << "The answer is: " << i << std::endl;
			return;
		}
	}
}
