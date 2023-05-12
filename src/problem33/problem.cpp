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
#include <numeric>

unsigned Solution::curious_fraction_pairs()
{
	unsigned product_of_denominators{1};
	unsigned product_of_numberator{1};

	for(size_t i = 11; i < 100; ++i)
		for(size_t j = i + 1; j < 100; ++j)
		{
			if(has_digit(i, 0) || has_digit(j, 0)) continue; // if has zero, continue the loop

			if(!has_same_digit(i, j)) continue;

			auto numbers_cancelled_same_digit = cancel_same_digit(i, j);

			if(static_cast<double>(i) / j == static_cast<double>(numbers_cancelled_same_digit[0]) / numbers_cancelled_same_digit[1])
			{
				product_of_denominators *= j;
				product_of_numberator *= i;
			}
		}

	return product_of_denominators / std::gcd(product_of_denominators, product_of_numberator);
}

void Solution::answer()
{
	std::cout << "The answer is: " << curious_fraction_pairs() << std::endl;
}
