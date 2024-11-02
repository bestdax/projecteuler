/*
Problem page link:
https://projecteuler.net/problem=53

dax 2024-09-23 17:09:51
*/
#include "problem.h"
#include <numeric>
#include <array>

ulong Solution::combination(uint n, uint r)
{
	if(r > n) return 0;

	if(r == 0 || r == n) return 1;

	// 根据对称性原则，可以减少运算量
	if(r > n / 2) r = n - r;

	ulong numerator = 1;
	ulong denominator = 1;

	for(uint i = 1; i <= r; ++i)
	{
		// r 从大到小，n - r + i 从小到大，可以提前约分而不至于溢出
		numerator *= (n - r + i);
		denominator *= r - i + 1;
		ulong gcd = std::gcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}

	return numerator;
}

void Solution::answer()
{
	uint count{};

	for(uint n = 1; n <= 100; ++n)
		for(uint r = 1; r <= n; ++r)
		{
			if(combination(n, r) > 1e6) ++count;
		}

	std::cout << "The answer is: " << count << std::endl;
}

void Solution::answer2()
{
	uint count{};

	std::array<std::array<ulong, 101>, 101> matrix;

	for(uint n = 1; n <= 100; ++n)
		for(uint r = 1; r <= n; ++ r)
		{
			if(r == 1) matrix[n][r] = n;
			else if(n == r) matrix[n][r] = 1;
			else
			{
				matrix[n][r] = matrix[n - 1][r - 1] + matrix[n - 1][r];

				if(matrix[n][r] > 1e6) ++count;
			}
		}

	std::cout << "The answer is: " << count << std::endl;
}
