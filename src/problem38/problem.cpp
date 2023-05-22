/*
Problem description:
Pandigital multiples
Problem 38
Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will
call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and
5, giving the pandigital, 918273645, which is the concatenated product of 9 and
(1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the
concatenated product of an integer with (1,2, ... , n) where n > 1?

page link:
https://projecteuler.net/problem=38

dax 2023-05-21 11:46:39
*/
#include "problem.h"
#include "number.h"

unsigned Solution::pandigital_multiple(unsigned number)
{
	unsigned n = 2;

	if(has_digit(number, 0) || has_same_digit(number))
		return 0;
	else
	{
		unsigned pm{number};

		while(true)
		{
			if(has_same_digit(pm, number * n) || has_digit(number * n, 0) || has_same_digit(pm) || has_same_digit(number * n)) break;
			else
			{
				pm = concatenate(pm, number * n);
				++n;
			}
		}

		return pm;
	}
}

unsigned Solution::max_pandigital_multiple()
{
	unsigned max{0};

	for(unsigned i = 1; i < 50'000; ++i)
	{
		auto pm = pandigital_multiple(i);
		max = size(pm) == 9 && pm > max ? pm : max;
	}

	return max;
}

void Solution::answer()
{
	std::cout << "The answer is: " << max_pandigital_multiple() << std::endl;
}
