/*
Problem page link:
https://projecteuler.net/problem=66

dax 2024-10-02 16:53:47
*/
#include "problem.h"
#include <bigint.h>

SqrtCF::SqrtCF(int n)
{
	int root = std::sqrt(n);

	if(root * root == n) return;

	int coefficient = root;
	std::pair<int, int> pair{0, 1};

	while(not remainders.contains(pair))
	{
		remainders.insert(pair);
		coefficients.push_back(coefficient);

		// generate next item
		std::pair<int, int> new_pair;
		new_pair.first = coefficient * pair.second - pair.first;
		new_pair.second = (n - new_pair.first * new_pair.first) / pair.second;

		coefficient = (root + new_pair.first) / new_pair.second;
		pair = new_pair;
	}

}

int SqrtCF::period()
{
	return coefficients.size() - 1;
}

void Solution::answer()
{
	BigUInt maxp{};
	uint maxd{};

	for(uint d = 1; d <= 1000; ++d)
	{
		SqrtCF cf(d);

		if(cf.period() > 0)
		{
			std::vector<BigUInt> P{0, 1};
			std::vector<BigUInt> Q{1, 0};
			BigUInt p, q;
			uint i = 0;
			uint ai = 0;

			while(p * p !=  d * q * q + 1)
			{
				if(i == 0)
					ai = cf.coefficients.front();
				else
					ai = cf.coefficients[(i - 1) % cf.period() + 1];

				p = ai * P[i + 1] + P[i];
				q = ai * Q[i + 1] + Q[i];
				P.push_back(p);
				Q.push_back(q);
				++i;
			}

			if(p > maxp)
			{
				maxp = p;
				maxd = d;
			}
		}
	}

	print("The answer is:", maxd);

}
