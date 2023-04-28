/*
Problem description:
Factorial digit sum
Problem 20
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
page link:
https://projecteuler.net/problem=20

dax 2023-04-28 11:12:14
*/
#include "problem.h"

void Solution::answer()
{
	std::cout << "The answer is: " << lint(100).factorial().digit_sum() << std::endl;
}

