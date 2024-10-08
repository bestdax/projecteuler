/*
Problem page link:
https://projecteuler.net/problem=78

dax 2024-10-07 16:24:01
*/
#include "problem.h"

void Solution::answer()
{

	unsigned n = 60'000;
	std::vector<unsigned> dp(n + 1);
	dp[0] = 1;

	for(unsigned pile = 1; pile <= n; ++pile)
	{
		for(unsigned i = pile; i <= n; ++i)
		{
			dp[i] += dp[i - pile];

			dp[i] %= 1'000'000;

			if(i == pile  && dp[i]  == 0)
			{

				{
					print("The answer is:", pile);
					return;
				}

			}

		}

	}

}

void Solution::answer2()
{

	std::vector<unsigned long> p{1};
	unsigned long n = 1;

	while(true)
	{
		long pn = 0;
		unsigned long k = 1;

		while(true)
		{
			unsigned long gk1 = k * (3 * k - 1) / 2;
			unsigned long gk2 = k * (3 * k + 1) / 2;

			if(gk1 > n and gk2 > n)
				break;

			int sign = k % 2 == 0 ? -1 : 1;

			if(gk1 <= n)
				pn += sign * p[n - gk1];

			if(gk2 <= n)
				pn += sign * p[n - gk2];

			k += 1;

		}

		pn %= 1'000'000;
		p.push_back(pn);

		if(pn == 0)
		{
			print("The answer is:", n);
			return;
		}

		++n;
	}

}
