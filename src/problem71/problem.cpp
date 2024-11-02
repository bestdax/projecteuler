/*
Problem page link:
https://projecteuler.net/problem=71

dax 2024-10-05 15:28:06
*/
#include "problem.h"
#include <numeric>
#include <utility>
#include <compare>

std::strong_ordering operator<=>(const std::pair<uint, uint> &a, const std::pair<uint, uint>& b)
{
	return a.first * b.second <=> a.second * b.first;
}

void Solution::answer()
{
	std::pair<uint, uint> right_boundry{3, 7};
	std::pair<uint, uint> next_to_right_boundry{0, 1};

	for(uint denominator = 1; denominator <= 1e6; ++denominator)
	{
		int numerator = denominator * right_boundry.first / right_boundry.second;

		do
		{
			std::pair<uint, uint> fraction{numerator, denominator};

			if(fraction < next_to_right_boundry) break;

			if(std::gcd(numerator, denominator) == 1 &&
			        fraction > next_to_right_boundry && fraction < right_boundry)
			{
				next_to_right_boundry.first = numerator;
				next_to_right_boundry.second = denominator;
				break;
			}

			--numerator;

		}
		while(numerator >= 0);

	}

	print("The answer is:", next_to_right_boundry.first);

}
