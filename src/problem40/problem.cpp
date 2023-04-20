/*
Problem description:
Champernowne's constant
Problem 40
An irrational decimal fraction is created by concatenating the positive
integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the
following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

page link:
https://projecteuler.net/problem=40

dax 2023-05-22 15:55:52
*/
#include "problem.h"
#include "number.h"

unsigned Solution::nth_digit(unsigned n)
{
	unsigned number_of_digits{}, number{};

	while(number_of_digits < n)
	{
		++number;
		number_of_digits += dax::size(number);
	}

	auto digits = dax::get_digits(number);
	return *(digits.end() - (number_of_digits - n) - 1);
}

unsigned Solution::champernowne_constant()
{
	return nth_digit(1) * nth_digit(10) * nth_digit(100) * nth_digit(1'000) * nth_digit(10'000) * nth_digit(100'000) * nth_digit(1'000'000);
}

void Solution::answer()
{
	std::cout << "The answer is: " << champernowne_constant() << std::endl;
}
