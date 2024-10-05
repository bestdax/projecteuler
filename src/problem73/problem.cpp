/*
Problem page link:
https://projecteuler.net/problem=73

dax 2024-10-05 16:38:33
*/
#include "problem.h"
#include <utility>
#include <compare>
#include <numeric>

std::strong_ordering operator<=>(const std::pair<unsigned, unsigned> &a, const std::pair<unsigned, unsigned>& b)
{
	return a.first * b.second <=> a.second * b.first;
}

void Solution::answer()
{
	std::pair<unsigned, unsigned> left_boundry{1, 3};
	std::pair<unsigned, unsigned> right_boundry{1, 2};
	unsigned count{};

	for(unsigned d = 2; d <= 12000; ++d)
	{
		unsigned n = left_boundry.first * d / left_boundry.second + 1;
		std::pair<unsigned, unsigned> fraction{n, d};

		while(fraction < right_boundry)
		{
			if(std::gcd(fraction.first, fraction.second) == 1)
			{
				++count;
			}

			++fraction.first;
		}

	}

	print("The answer is:", count);
}
