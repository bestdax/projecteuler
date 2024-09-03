#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Remainder
{
	unsigned long numerator;
	unsigned long denominator;
};

bool operator==(const Remainder&lhs, const Remainder&rhs);

class ContinuedFractionOfSquareRoot
{
	public:
		ContinuedFractionOfSquareRoot(unsigned long n);
		std::vector<short> coefficients;
		std::vector<Remainder> remainders;
};

class Solution
{
	public:
		void answer();

};
