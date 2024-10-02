/*
Problem page link:
https://projecteuler.net/problem=64

dax 2024-10-01 20:00:05
*/
#include "problem.h"
#include <numeric>

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
	unsigned count{};

	for(int i = 1; i <= 10000; ++i)
	{
		int period = SqrtCF(i).period();

		if(period > 0 and period % 2 == 1)
			++count;
	}

	print("The answer is:", count);
}
