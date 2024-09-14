/*
Problem page link:
https://projecteuler.net/problem=31

dax 2024-09-14 11:57:55
*/
#include "problem.h"
Solution::Solution()
{
	dp[0] = 1;
};

void Solution::answer()
{
	for(auto& coin : coins)
	{
		for(unsigned i = coin; i <= 200; ++i)
			dp[i] += dp[i - coin];
	}

	std::cout << "The answer is: " << dp[200] << std::endl;
}
