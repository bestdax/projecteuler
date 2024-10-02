/*
Problem page link:
https://projecteuler.net/problem=65

dax 2024-10-02 16:05:03
*/
#include "problem.h"
#include <bigint.h>
#include <vector>

void Solution::answer()
{
	std::vector<BigUInt> P{0, 1};
	P.reserve(110);
	std::vector<BigUInt> Q{1, 0};
	Q.reserve(110);
	int ai = 0;

	for(int i = 0; i < 100; ++i)
	{
		if(i == 0)
			ai = 2;
		else if(i % 3 == 0 || i % 3 == 1)
			ai = 1;
		else
			ai = (i + 1) / 3 * 2;

		auto pi = ai * P[i + 1] + P[i];
		auto qi = ai * Q[i + 1] + Q[i];

		P.push_back(pi);
		Q.push_back(qi);
	}

	print("The answer is:", P.back().digital_sum());
}
