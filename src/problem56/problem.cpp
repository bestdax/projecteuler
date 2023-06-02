/*
Problem description:

page link:
https://projecteuler.net/problem=56

dax 2023-06-03 06:45:00
*/
#include "problem.h"
#include "longint.h"

void Solution::answer()
{
	lint max_digit_sum{};

	for(unsigned a = 1; a < 100; ++a)
		for(unsigned b = 1; b < 100; ++b)
		{
			auto digit_sum = lint(a).power(b).digit_sum();
			max_digit_sum =  digit_sum > max_digit_sum ? digit_sum : max_digit_sum;
		}

	std::cout << "The answer is: " << max_digit_sum << std::endl;
}
