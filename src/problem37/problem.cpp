/*
Problem page link:
https://projecteuler.net/problem=37

dax 2024-09-16 13:55:00
*/
#include "problem.h"

Solution::Solution()
{
	is_prime = dax::sieve_of_eratosthenes(1e6);
}

bool Solution::is_truncatable_prime(unsigned n)
{
	if(n < 10 || !is_prime[n]) return false;

	unsigned base = 10;

	while(n % base != n)
	{
		// 从右边取
		if(!is_prime[n % base]) return false;

		// 从左边取
		if(!is_prime[n / base]) return false;

		base *= 10;
	}

	return true;
}

void Solution::answer()
{
	unsigned count{};
	unsigned n = 10;
	unsigned sum{};

	while(count != 11)
	{
		if(is_truncatable_prime(n))
		{
			++count;
			sum += n;
		}

		++n;
	}

	std::cout << "The answer is: " << sum << std::endl;
}
