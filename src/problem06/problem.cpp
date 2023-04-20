/*
Problem description:
Sum square difference
Problem 6
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,
(1+2+...+10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
page link:
https://projecteuler.net/problem=6

dax 2023-04-23 13:54:18
*/
#include "problem.h"

long Solution::sum_of_squares(int range)
{
	long sum{};

	for(int i = 1; i <= range; ++i)
		sum += i * i;

	return sum;
}

long Solution::square_of_sum(int range)
{
	long sum{};

	for(int i = 1; i <= range; ++i) sum += i;

	return sum * sum;
}

long Solution::sum_square_difference(int range)
{
	return square_of_sum(range) - sum_of_squares(range);
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_square_difference(100) << std::endl;
}
