/*
Problem page link:
https://projecteuler.net/problem=76

dax 2024-10-07 14:25:30
*/
#include "problem.h"
#include <vector>

void Solution::answer()
{
	unsigned sum{100};
	std::vector<unsigned long> dp(sum + 1);
	dp[0] = 1;

	for(unsigned i = 1; i < sum; ++i)
	{
		for(unsigned j = i; j <= sum; ++j)
		{
			dp[j] += dp[j - i];
		}

	}

	print("The answer is:", dp[sum]);
}
