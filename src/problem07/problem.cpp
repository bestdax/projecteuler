/*
Problem page link:
https://projecteuler.net/problem=7

dax 2024-07-31 09:34:31
*/
#include "problem.h"
#include "number.h"
#include <cmath>

unsigned long Solution::nth_prime(unsigned n)
{
	unsigned long limit = n * (std::log(n) + std::log(std::log(n)));
	auto prime_status = dax::sieve_of_Eratosthenes(limit);
	unsigned count = 0;

	for(unsigned i = 0; i <= limit; ++i)
	{
		if(prime_status[i]) ++count;

		if(count == n) return i;
	}

	return 0;
}

void Solution::answer()
{
	std::cout << "The answer is: " << nth_prime(10001) << std::endl;
}
