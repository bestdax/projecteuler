/*
Problem page link:
https://projecteuler.net/problem=75

dax 2024-10-06 16:48:09
*/
#include "problem.h"
#include <cmath>
#include <numutils.h>
#include <set>

void Solution::answer()
{
	std::set<Triangle> right_triangles;
	std::unordered_map<unsigned, unsigned> triangle_count;

	unsigned length_limit = 1.5e6;

	unsigned limit = (std::sqrt(length_limit * 2 - 1) - 1) / 2;
	unsigned m = 1;
	unsigned n = m + 1;

	while(m <= limit)
	{
		unsigned a = n * n - m * m;
		unsigned b = 2 * m * n;
		unsigned c = n * n + m * m;

		if(a + b + c > length_limit)
		{
			++m;
			n = m + 1;
			continue;
		}

		Triangle t{a < b ? a : b, a < b ? b : a, c};
		unsigned k = 0;

		if(not right_triangles.contains(t))
		{
			while(true)
			{
				++k;
				auto copy(t);

				copy.a *= k;
				copy.b *= k;
				copy.c *= k;

				if(copy.perimeter() > length_limit) break;

				if(not right_triangles.contains(copy))
				{
					right_triangles.insert(copy);
					++triangle_count[copy.perimeter()];
				}
			}
		}

		++n;
	}

	unsigned count{};

	for(auto& [length, num] : triangle_count)
	{
		if(num == 1) ++count;
	}

	print("The answer is:", count);
}
