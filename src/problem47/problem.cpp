/*
Problem description:
Distinct primes factors
Problem 47
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors
each. What is the first of these numbers?

page link:
https://projecteuler.net/problem=47

dax 2023-05-23 16:07:14
*/
#include "problem.h"
#include "number.h"
#include <algorithm>

void Solution::unique(std::vector<unsigned>& vec)
{
	std::sort(vec.begin(), vec.end());
	auto last = std::unique(vec.begin(), vec.end());
	vec.erase(last, vec.end());
}

unsigned long Solution::first_number(unsigned n)
{
	unsigned long number{2};

	while(true)
	{
		for(unsigned i = 0; i < n; ++i)
		{
			auto pf = dax::prime_factors(number + i);
			unique(pf);

			if(pf.size() != n)
			{
				number += i;
				break;
			}

			if(i == n - 1) return number;
		}

		++number;
	}
}

void Solution::answer()
{
	std::cout << "The answer is: " << first_number(4) << std::endl;
}
