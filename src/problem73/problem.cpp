/*
Problem page link:
https://projecteuler.net/problem=73

dax 2024-10-05 16:38:33
*/
#include "problem.h"
#include <utility>
#include <compare>
#include <numeric>

std::strong_ordering operator<=>(const std::pair<uint, uint> &a, const std::pair<uint, uint>& b)
{
	return a.first * b.second <=> a.second * b.first;
}

void Solution::answer()
{
	std::pair<uint, uint> left_boundry{1, 3};
	std::pair<uint, uint> right_boundry{1, 2};
	uint count{};

	for(uint d = 2; d <= 12000; ++d)
	{
		uint n = left_boundry.first * d / left_boundry.second + 1;
		std::pair<uint, uint> fraction{n, d};

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
