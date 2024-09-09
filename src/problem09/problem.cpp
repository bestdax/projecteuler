/*
Problem page link:
https://projecteuler.net/problem=9

dax 2024-09-09 17:30:05
*/
#include "problem.h"

void Solution::answer()
{
	for(unsigned c = 334; c < 500; ++c)
		for(unsigned a = 1; a < c; ++a)
		{
			auto b = 1000 - a - c;

			if(a * a + b * b == c * c)
			{
				std::cout << "The answer is: " << a * b * c << std::endl;
				return;
			}
		}

}
