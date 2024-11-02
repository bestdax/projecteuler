/*
Problem page link:
https://projecteuler.net/problem=28

dax 2024-09-12 12:09:07
*/
#include "problem.h"

void Solution::answer()
{
	ulong sum{1};
	uint side = 1;
	uint dnum = 1;

	while(side < 1001)
	{
		side += 2;

		for(int i = 0; i < 4; ++i)
		{
			dnum += (side - 1);
			sum += dnum;
		}
	}

	std::cout << "The answer is: " << sum << std::endl;
}
