/*
Problem page link:
https://projecteuler.net/problem=52

dax 2024-09-23 16:35:12
*/
#include "problem.h"
#include <string>
#include <algorithm>

bool has_same_digits(ulong a, ulong b)
{
	auto nsa = std::to_string(a);
	std::sort(nsa.begin(), nsa.end());
	auto nsb = std::to_string(b);
	std::sort(nsb.begin(), nsb.end());

	return nsa == nsb;
}

void Solution::answer()
{

	for(ulong n = 2; n < 1e6; ++n)
	{
		bool found = true;

		for(uint i = 2; i < 6; ++i)
		{
			if(!has_same_digits(n, n * i))
			{
				found = false;
				break;
			}
		}

		if(found)
		{
			std::cout << "The answer is: " << n << std::endl;
			return;
		}
	}
}
