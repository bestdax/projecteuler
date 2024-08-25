/*
Problem page link:
https://projecteuler.net/problem=55

dax 2024-08-17 10:34:45
*/
#include "problem.h"
#include <string>
#include <algorithm>
#include "bint.h"

void Solution::answer()
{
	unsigned count{};

	for(unsigned i = 1; i < 1e4; ++i)
	{
		bint bi(i);

		for(unsigned j = 0; j < 50; ++j)
		{
			bi += bi.reverse();

			if(bi.is_palindrome()) break;

			if(j == 49) ++count;
		}

	}

	std::cout << "The answer is: " << count << std::endl;
}
