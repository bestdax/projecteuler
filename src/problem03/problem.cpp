/*
Problem page link:
https://projecteuler.net/problem=3

dax 2024-07-28 09:26:08
*/
#include "problem.h"
#include <cmath>
bool Solution::is_prime(unsigned long n)
{
	if(n < 2) return false;

	auto root = std::floor(std::sqrt(n));

	for(unsigned long i = 2; i <= root; ++i)
	{
		if(n % i == 0) return false;
	}

	return true;
}

unsigned Solution::get_the_greatest_prime_factor(unsigned long n)
{
	while(! is_prime(n))
	{
		for(unsigned i = 2; i <= n; ++i)
		{
			if(is_prime(i) && n % i == 0)
			{
				prime_factors.push_back(i);
				n = n / i;
				break;
			}
		}
	}

	prime_factors.push_back(n);

	return prime_factors.back();
}

void Solution::answer()
{
	std::cout << "The answer is: " << get_the_greatest_prime_factor(600851475143) << std::endl;
}
