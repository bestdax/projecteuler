/*
Problem description:
Problem 21
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The
proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

page link:
https://projecteuler.net/problem=21

dax 2023-04-28 11:22:52
*/
#include "problem.h"

unsigned Solution::sum_of_proper_divisors(unsigned n)
{
	unsigned sum{};
	unsigned root = std::round(std::sqrt(n));

	for(unsigned i = 1; i <= root; ++i)
	{
		if(n % i == 0)
		{
			sum += i;
			sum += n / i;
		}
	}

	if(root * root == n) sum -= root;

	sum -= n;
	return sum;
}

bool Solution::has_amicable(unsigned n)
{
	unsigned sum = sum_of_proper_divisors(n);

	if(sum != n && sum_of_proper_divisors(sum) == n) return true;

	return false;
}

unsigned Solution::sum_of_amicables(unsigned long n)
{
	unsigned sum{};

	for(unsigned long i = 1; i < n; ++i)
		if(has_amicable(i)) sum += i;

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_amicables(10000) << std::endl;
}
