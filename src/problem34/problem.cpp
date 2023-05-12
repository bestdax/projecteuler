/*
Problem description:
Digit factorials
Problem 34
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their
digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.

page link:
https://projecteuler.net/problem=34

dax 2023-05-12 16:22:54
*/
#include "problem.h"
unsigned Solution::length()
{
	unsigned len = 1;

	while(lint(10).power(len) < lint(9).factorial() * len)
	{
		++len;
	}

	return len;
}

bool Solution::is_curious(lint number)
{
	lint sum_of_digit_factorial{};

	for(auto d : number.number())
	{
		sum_of_digit_factorial += lint(d - 48).factorial();
	}

	return sum_of_digit_factorial == number;
}

lint Solution::sum_of_curious_number()
{
	lint sum{};
	unsigned len = length();
	lint cap = lint(9).factorial() * len;
	std::cout << cap << std::endl;
	lint n = 3;

	while(n <= cap)
	{
		auto digits = n.number();
		lint sum_of_digit_factorial{};

		if(is_curious(n))
		{
			sum += n;
			std::cout << n << '\t' << sum << std::endl;
		}

		++n;
	}

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_curious_number() << std::endl;
}
