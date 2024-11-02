/*
Problem page link:
https://projecteuler.net/problem=35

dax 2024-09-16 10:17:15
*/
#include "problem.h"
#include <prime.h>
#include <cmath>

Solution::Solution()
{
	is_prime = dax::sieve_of_eratosthenes(1e6);
}

bool Solution::is_circular_prime(uint n)
{
	if(!is_prime[n]) return false;

	uint num_of_digits{};
	auto temp = n;

	while(temp)
	{
		temp /= 10;
		++num_of_digits;
	}

	uint multiplier{1};

	for(int i = 0; i < num_of_digits - 1; ++i)
		multiplier *= 10;

	auto circular = n;

	for(uint i = 0; i < num_of_digits; ++i)
	{
		circular = circular % 10 * multiplier + circular / 10;

		if(!is_prime[circular])
			return false;
	}

	return true;
}

void Solution::answer()
{
	uint count{};

	for(uint i = 0; i < 1e6; ++i)
	{
		if(is_circular_prime(i))
			++count;
	}

	std::cout << "The answer is: " << count << std::endl;
}
