/*
Problem page link:
https://projecteuler.net/problem=75

dax 2024-10-06 16:48:09
*/
#include "problem.h"
#include <unordered_map>
#include <numeric>

void Solution::answer()
{
	std::unordered_map<unsigned, unsigned> triangle_count;

	unsigned length_limit = 1.5e6;

	for(unsigned m = 2; m * m < length_limit; ++m)
	{
		for(unsigned n = m % 2 + 1; n < m; n += 2)
		{
			if(std::gcd(m, n) != 1) continue;

			unsigned a = m * m - n * n;
			unsigned b = 2 * m * n;
			unsigned c = m * m + n * n;

			unsigned perimeter = a + b + c;

			for(unsigned k = 1; k * perimeter <= length_limit; ++k)
			{
				++triangle_count[k * perimeter];
			}

		}
	}

	unsigned count{};

	for(auto& [length, num] : triangle_count)
	{
		if(num == 1) ++count;
	}

	print("The answer is:", count);
}
