/*
Problem page link:
https://projecteuler.net/problem=36

dax 2024-09-16 11:03:11
*/
#include "problem.h"
#include <numutils.h>

void Solution::answer()
{
	uint sum{};

	for(uint i = 0; i < 1e6; ++i)
	{
		if(dax::is_palindrome(i) && dax::is_palindrome(i, 2))
			sum += i;
	}

	std::cout << "The answer is: " << sum << std::endl;
}
