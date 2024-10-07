/*
Problem page link:
https://projecteuler.net/problem=77

dax 2024-10-07 15:55:13
*/
#include "problem.h"
#include <prime.h>

void Solution::answer()
{

	unsigned target = 10;
	auto primes = dax::sieve_of_euler(100);
	std::vector<unsigned long> dp(target + 1, 0);
	dp[0] = 1;

	while(dp.back() <= 5000)
	{
		++target;
		dp.clear();
		dp.resize(target);
		dp[0] = 1;

		for(auto& prime : primes)
		{
			if(prime > target) break;

			for(unsigned i = prime; i <= target; ++i)
			{
				dp[i] += dp[i - prime];
			}
		}

	}

	print("The answer is:", target - 1);
}
