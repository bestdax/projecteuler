/*
Problem page link:
https://projecteuler.net/problem=66

dax 2023-06-09 16:06:21
*/
#include "problem.h"
#include "number.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
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
	bint max;
	unsigned d;

	for(unsigned n = 2; n <= 1000; ++n)
	{
		if(!dax::is_square(n))
		{
			ContinuedFractionOfSquareRoot cf(n);
			unsigned i = 0;
			std::vector<bint> pn = {0, 1};
			std::vector<bint> qn = {1, 0};
			bint p = cf.coefficients[i];
			bint q = 1;
			pn.push_back(p);
			qn.push_back(q);

			while(p * p != n * q * q + 1)
			{
				++i;

				if(i == cf.coefficients.size())
					i = 1;

				p = cf.coefficients[i] * pn.back() + (*(pn.end() - 2));
				q = cf.coefficients[i] * qn.back() + (*(qn.end() - 2));
				pn.push_back(p);
				qn.push_back(q);
			}

			if(pn.back() > max)
			{
				max = pn.back();
				d = n;
			}

			// std::cout << pn.back() << '\t' << n << '\t' << qn.back() << '\t' <<  std::endl;
		}
	}

	std::cout << "The answer is: " << d << std::endl;
}
