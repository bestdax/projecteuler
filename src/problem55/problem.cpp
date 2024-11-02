/*
Problem page link:
https://projecteuler.net/problem=55

dax 2024-09-24 12:25:52
*/
#include "problem.h"
#include <bigint.h>

void Solution::answer()
{
	uint count{};

	for(uint i = 1; i < 1e4; ++i)
	{
		BigUInt number(i);

		for(uint j = 0; j < 50; ++j)
		{
			number += number.reverse();

			if(number.is_palindrome())
			{
				break;
			}

			if(j == 49) ++count;
		}

	}

	std::cout << "The answer is: " << count << std::endl;
}
