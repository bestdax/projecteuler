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
	std::unordered_map<uint, uint> triangle_count;

	uint length_limit = 1.5e6;

	for(uint m = 2; m * m < length_limit; ++m)
	{
		for(uint n = m % 2 + 1; n < m; n += 2)
		{
			if(std::gcd(m, n) != 1) continue;

			uint a = m * m - n * n;
			uint b = 2 * m * n;
			uint c = m * m + n * n;

			uint perimeter = a + b + c;

			for(uint k = 1; k * perimeter <= length_limit; ++k)
			{
				++triangle_count[k * perimeter];
			}

		}
	}

	uint count{};

	for(auto& [length, num] : triangle_count)
	{
		if(num == 1) ++count;
	}

	print("The answer is:", count);
}
