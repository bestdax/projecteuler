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
