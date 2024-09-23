/*
Problem page link:
https://projecteuler.net/problem=53

dax 2024-09-23 17:09:51
*/
#include "problem.h"
#include <numeric>

unsigned long Solution::combination(unsigned n, unsigned r)
{
	if(r > n) return 0;

	if(r == 0 || r == n) return 1;

	// 根据对称性原则，可以减少运算量
	if(r > n / 2) r = n - r;

	unsigned long numerator = 1;
	unsigned long denominator = 1;

	for(unsigned i = 1; i <= r; ++i)
	{
		numerator *= (n - i  + 1);
		// r 从大到小，可以提前约分而不至于溢出
		denominator *= r - i + 1;
		unsigned long gcd = std::gcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}

	return numerator;
}

void Solution::answer()
{
	unsigned count{};

	for(unsigned n = 1; n <= 100; ++n)
		for(unsigned r = 1; r <= n; ++r)
		{
			if(combination(n, r) > 1e6) ++count;
		}

	std::cout << "The answer is: " << count << std::endl;
}
