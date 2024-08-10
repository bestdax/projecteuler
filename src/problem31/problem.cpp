/*
Problem page link:
https://projecteuler.net/problem=31

dax 2024-08-10 10:40:50
*/
#include "problem.h"

void Solution::answer()
{
	dp[0] = 1;

	for(auto coin : coins)
	{
		for(int i = coin; i <= 200; ++i)
		{
			dp[i] += dp[i - coin];
		}
	}

	std::cout << "The answer is: " << dp.back() << std::endl;
}
