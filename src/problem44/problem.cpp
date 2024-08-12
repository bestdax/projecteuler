/*
Problem page link:
https://projecteuler.net/problem=44

dax 2024-08-12 14:43:14
*/
#include "problem.h"

void Solution::answer()
{
	unsigned long n{1};

	while(true)
	{
		auto p = n * (3 * n - 1) / 2;

		for(auto m : pentagonals)
		{
			if(dax::is_pentagonal(p - m) && dax::is_pentagonal(p + m))
			{
				std::cout << "The answer is: " << p - m << std::endl;
				return;
			}

		}

		pentagonals.push_back(p);

		++n;

	}

}
