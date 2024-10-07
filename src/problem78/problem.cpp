/*
Problem page link:
https://projecteuler.net/problem=78

dax 2024-10-07 16:24:01
*/
#include "problem.h"

BigUInt Solution::coin_partitions(unsigned n)
{
	std::vector<BigUInt> dp(n + 1);
	dp[0] = 1;

	for(unsigned pile = 1; pile <= n; ++pile)
		for(unsigned i = pile; i <= n; ++i)
		{
			dp[i] += dp[i - pile];
		}

	return dp.back();
}

void Solution::answer()
{
	std::vector<std::vector<BigUInt>> dp;
	unsigned coins = 0;
	dp.push_back({1});

	while(dp[coins].back() % 1e6 != 0)
	{
		++coins;
		std::vector<BigUInt> row(coins + 1);
		row[0] = 1;
		dp.push_back(row);

		for(unsigned i = 1; i <= coins; ++i)
		{
			dp[coins][i] = i == coins ? 1 : dp[coins-1][i] + dp[coins - 1][i - i];
		}

		print(dp[coins]);

		if(coins > 10) break;

		// print("The answer is:", coin_partitions(coins));
	}
}
