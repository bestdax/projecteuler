/*
Problem description:
Digit fifth powers
Problem 30
Surprisingly there are only three numbers that can be written as the sum of
fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers
of their digits.

page link: https://projecteuler.net/problem=30

dax 2023-05-04 09:37:22
*/
#include "problem.h"

lint Solution::sum_of_nth_power_numbers(unsigned n)
{
	unsigned number_of_digits{2};

	while(true)
	{
		if(lint(10).power(number_of_digits) > lint(9).power(n) * number_of_digits)  break;

		number_of_digits++;
	}

	lint sum;
	lint cap = lint(9).power(n) * number_of_digits;

	for(lint i = 10; i < cap; ++i)
	{
		lint digit_nth_power_sum;

		for(char c : i.number())
		{
			digit_nth_power_sum += lint(c - 48).power(n);
		}

		if(digit_nth_power_sum == i) sum += i;
	}

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_nth_power_numbers(5) << std::endl;
}
