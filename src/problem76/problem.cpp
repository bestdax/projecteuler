/*
Problem page link:
https://projecteuler.net/problem=76

dax 2024-10-07 14:25:30
*/
#include "problem.h"
#include <vector>

void Solution::answer()
{
	uint sum{100};
	std::vector<ulong> dp(sum + 1);
	dp[0] = 1;

	for(uint i = 1; i < sum; ++i)
	{
		for(uint j = i; j <= sum; ++j)
		{
			dp[j] += dp[j - i];
		}

	}

	print("The answer is:", dp[sum]);
}
