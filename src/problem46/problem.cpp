/*
Problem page link:
https://projecteuler.net/problem=46

dax 2024-08-12 15:50:53
*/
#include "problem.h"
#include "number.h"

void Solution::answer()
{
	auto primes = dax::sieve_of_Euler(1e6);

	for(unsigned i = 9; i < 1e6; ++i)
	{
		if(i % 2 != 0)
		{
			bool nobreak = true;

			for(auto p : primes)
			{
				if(p > i) break;

				auto q = i - p;

				if(q % 2 == 0 && dax::is_square(q / 2))
				{
					nobreak = false;
					break;
				}
			}

			if(nobreak)
			{
				std::cout << "The answer is: " << i << std::endl;
				return;
			}
		}
	}

}
