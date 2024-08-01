/*
Problem page link:
https://projecteuler.net/problem=9

dax 2024-08-01 09:48:07
*/
#include "problem.h"

unsigned long Solution::find_abc_product()
{
	// c < a + b 所以不会超过一半
	for(int c = 334; c < 500; ++c)
		for(int a = 1; a < c; ++a)
		{
			int b = 1000 - a - c;

			if(a * a + b * b == c * c) return a * b * c;
		}
}

void Solution::answer()
{
	std::cout << "The answer is: " << find_abc_product() << std::endl;
}
