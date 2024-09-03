/*
Problem page link:
https://projecteuler.net/problem=64

dax 2024-09-03 10:35:46
*/
#include "problem.h"

bool operator==(const Remainder&lhs, const Remainder&rhs)
{
	return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
}

ContinuedFractionOfSquareRoot::ContinuedFractionOfSquareRoot(unsigned long n)
{
	unsigned long a = std::floor(std::sqrt(n));
	coefficients.push_back(a);
	Remainder remainder{1, a};

	while(std::find(remainders.begin(), remainders.end(), remainder) == remainders.end())
	{
		remainders.push_back(remainder);
		auto last_remainder = remainders.back();
		unsigned long coefficient = (a + last_remainder.denominator)  * last_remainder.numerator /
		                            (n  - last_remainder.denominator * last_remainder.denominator);
		coefficients.push_back(coefficient);
		unsigned long numerator = (n - last_remainder.denominator*last_remainder.denominator) / last_remainder.numerator;
		unsigned long denominator = coefficient * numerator - last_remainder.denominator;
		remainder = Remainder{numerator, denominator};

	}
}

void Solution::answer()
{
	unsigned count{};

	for(int i = 2; i < 10000; ++i)
	{
		unsigned long r = std::floor(std::sqrt(i));

		if(r * r != i)
		{
			ContinuedFractionOfSquareRoot root(i);

			if((root.coefficients.size() - 1) % 2 == 1) ++count;
		}
	}

	std::cout << "The answer is: " << count << std::endl;
}
