/*
Problem description:
Special Pythagorean triplet
Problem 9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
page link:
https://projecteuler.net/problem=9

dax 2023-04-23 16:30:59
*/
#include "problem.h"

long Solution::product_of_abc()
{
	for(int a = 1; a < 333; ++a)
	{
		for(int b = a + 1; b < 1000 - a - b; ++b)
		{
			int c = 1000 - a - b;

			if(a * a + b * b == c * c) return a * b * c;
		}
	}

	return 0;
}

void Solution::answer()
{
	std::cout << "The answer is: " << product_of_abc() << std::endl;
}
