/*
Problem page link:
https://projecteuler.net/problem=3

dax 2024-09-07 07:01:15
*/
#include "problem.h"
#include <prime.h>

ulong Solution::greatest_prime_factor(ulong n)
{

	auto prime_status = dax::sieve_of_eratosthenes(std::sqrt(n));
	ulong largest_prime = 1;

	for(ulong i = 2; i <= n; ++i)
	{
		if(prime_status[i])
		{
			while(n % i == 0) n /= i;

			largest_prime = i;
		}

		if(n == 1) break;
	}

	if(n > 1) largest_prime = n;

	return largest_prime;
}

void Solution::answer()
{
	std::cout << "The answer is: " << greatest_prime_factor(600851475143) << std::endl;
}
