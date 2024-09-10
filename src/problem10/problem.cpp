/*
Problem page link:
https://projecteuler.net/problem=10

dax 2024-09-10 08:32:48
*/
#include "problem.h"
#include <numbertools.h>

unsigned long Solution::sum_of_primes(unsigned long limit)
{
	auto is_prime = dax::sieve_of_eratosthenes(limit);
	unsigned long sum{};
	for(unsigned long i = 0; i <= limit; ++i)
	{
		if(is_prime[i]) sum += i;
	}
	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_primes(2e6) << std::endl;
}
