/*
Problem description:
Coin sums
Problem 31
In the United Kingdom the currency is made up of pound (£) and pence (p). There
are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
page link:
https://projecteuler.net/problem=31

dax 2023-05-04 10:26:21
*/
#include "problem.h"

unsigned Solution::coin_sums()
{
	std::vector<unsigned> dp(total + 1, 0);
	dp[0] = 1;

	for(auto coin : coins)
		for(unsigned i = coin; i <= total; ++i)
		{
			dp[i] += dp[i - coin];
		}

	return dp.back();
}

void Solution::answer()
{
	std::cout << "The answer is: " << coin_sums() << std::endl;
}
