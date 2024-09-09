/*
Problem page link:
https://projecteuler.net/problem=7

dax 2024-09-09 16:08:58
*/
#include "problem.h"
#include <cmath>
#include <numbertools.h>

unsigned long Solution::nth_prime(unsigned n)
{
	unsigned a = n * (std::log(n) + std::log(std::log(n)));
	auto prime_status = dax::sieve_of_eratosthenes(a);
	unsigned count{};

	for(unsigned i = 0; i <= prime_status.size(); ++i)
	{
		if(prime_status[i]) ++count;

		if(count == n) return i;
	}

	return 0;
}

void Solution::answer()
{
	auto np = nth_prime(10001);
	std::cout << "The answer is: " << np << std::endl;
}
