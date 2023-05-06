/*
Problem description:
Digit cancelling fractions
Problem 33
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in
attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is
correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than
one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find
the value of the denominator.

page link:
https://projecteuler.net/problem=33

dax 2023-05-06 15:22:21
*/
#include "problem.h"
#include "number.h"

void Solution::curious_fraction_pairs()
{
	for(size_t i = 11; i < 100; ++i)
		for(size_t j = i + 1; j < 100; ++j)
		{
			if(has_zero(i) || has_zero(j)) continue;

			if(!has_same_digit(i, j)) continue;

			std::cout << i << '\t' << j << std::endl;
		}
}

void Solution::answer()
{
	curious_fraction_pairs();
}
