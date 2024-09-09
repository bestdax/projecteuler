/*
Problem page link:
https://projecteuler.net/problem=4

dax 2024-09-09 11:32:14
*/
#include "problem.h"
#include <numutils.h>

void Solution::answer()
{
	unsigned max_palindrome{};

	for(unsigned i = 100; i < 1000; ++i)
		for(unsigned j = 100; j < 1000; ++j)
		{
			unsigned product = i * j;

			if(dax::is_palindrome(product) && product > max_palindrome)
			{
				max_palindrome = product;
			}
		}

	std::cout << "The answer is: " << max_palindrome << std::endl;
}
