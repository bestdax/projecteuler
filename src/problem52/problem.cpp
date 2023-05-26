/*
Problem description:
Permuted multiples
Problem 52
It can be seen that the number, 125874, and its double, 251748, contain exactly
the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain
the same digits.

page link:
https://projecteuler.net/problem=52

dax 2023-05-26 12:11:40
*/
#include "problem.h"
#include "number.h"

void Solution::answer()
{
	unsigned long target{};
	unsigned long start = 123455;

	while(true)
	{
		++start;

		if(has_same_digit(start)) continue;

		for(unsigned n = 2; n < 7; ++n)
		{
			if(!has_exact_same_digits(start, start * n)) break;

			if(n == 6) target = start;
		}

		if(target) break;
	}

	std::cout << "The answer is: " << target << std::endl;
}
