/*
Problem description:
Non-abundant sums
Problem 23
A perfect number is a number for which the sum of its proper divisors is exactly
equal to the number. For example, the sum of the proper divisors of 28 would be
1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n
and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
number that can be written as the sum of two abundant numbers is 24. By
mathematical analysis, it can be shown that all integers greater than 28123 can
be written as the sum of two abundant numbers. However, this upper limit cannot
be reduced any further by analysis even though it is known that the greatest
number that cannot be expressed as the sum of two abundant numbers is less than
this limit.

Find the sum of all the positive integers which cannot be written as the sum of
two abundant numbers. page link: https://projecteuler.net/problem=23

dax 2023-04-28 14:19:10
*/
#include "problem.h"

bool Solution::is_abundant(unsigned n)
{
	unsigned sum_of_proper_divisors{};
	unsigned root = std::round(std::sqrt(n));

	for(unsigned i = 1; i <= root; ++i)
	{
		if(n % i == 0)
		{
			sum_of_proper_divisors += i;
			sum_of_proper_divisors += n / i;
		}
	}

	sum_of_proper_divisors -= n;

	if(root * root == n) sum_of_proper_divisors -= root;

	return sum_of_proper_divisors > n;
}

bool Solution::is_sum_of_two_abundants(unsigned n)
{
	unsigned middle = n / 2;

	for(unsigned i = 2; i <= middle; ++i)
	{
		if(is_abundant(i) && is_abundant(n - i)) return true;
	}

	return false;
}

unsigned Solution::non_abundant_sums()
{
	unsigned sum{};

	for(unsigned i = 1; i <= 28123; ++i)
	{
		if(!is_sum_of_two_abundants(i))
		{
			sum += i;
		}
	}

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << non_abundant_sums() << std::endl;
}
