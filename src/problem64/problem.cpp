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
	Remainder remainder{-root, 1};

	while(not remainders.contains(remainder))
	{
		remainders.insert(remainder);
		coefficients.push_back(coefficient);

		// generate next item
		coefficient = remainder.denominator / (std::sqrt(n) + remainder.numerator);
		int denominator = n - remainder.numerator * remainder.numerator;
		int numerator = remainder.denominator * -remainder.numerator - coefficient * denominator;
		auto gcd = std::gcd(denominator, remainder.denominator);
		numerator /= gcd;
		denominator /= gcd;
		remainder = Remainder{numerator, denominator};
	}

	coefficients.push_back(coefficient);
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
