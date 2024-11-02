/*
Problem page link:
https://projecteuler.net/problem=10

dax 2024-09-10 08:32:48
*/
#include "problem.h"
#include <prime.h>

ulong Solution::sum_of_primes(ulong limit)
{
	auto is_prime = dax::sieve_of_eratosthenes(limit);
	ulong sum{};
	for(ulong i = 0; i <= limit; ++i)
	{
		if(is_prime[i]) sum += i;
	}
	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_primes(2e6) << std::endl;
}
