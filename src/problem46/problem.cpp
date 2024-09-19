/*
Problem page link:
https://projecteuler.net/problem=46

dax 2024-09-19 12:02:05
*/
#include "problem.h"
#include <numutils.h>
#include <prime.h>

void Solution::answer()
{
	auto is_prime = dax::sieve_of_euler(1e5);
	unsigned n = 9;

	while(true)
	{
		if(is_prime[n])
		{
			n += 2;
			continue;
		}

		bool found = true;

		for(unsigned i = 2; i < n; ++i)
		{
			if(is_prime[i])
			{
				unsigned remainder = n - i;

				if(remainder % 2 == 0 && dax::is_square(remainder / 2))
				{
					found = false;
				}
			}
		}

		if(found)
		{
			std::cout << "The answer is: " << n << std::endl;
			return;
		}

		n += 2;

	}

}
