/*
Problem description:
Self powers
Problem 48
The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

page link:
https://projecteuler.net/problem=48

dax 2023-05-24 09:11:55
*/
#include "problem.h"

lint Solution::self_power(unsigned n)
{
	return lint(n).power(n);
}

// TODO optimise this algorithm;
lint Solution::sum_of_self_power(unsigned cap)
{
	lint sum{};

	for(unsigned i = 1; i <= cap; ++i)
	{
		sum += self_power(i);
	}

	return sum;
}


void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_self_power(1000) << std::endl;
}
