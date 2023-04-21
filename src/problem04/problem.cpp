/*
Problem description:
Largest palindrome product

Problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is
9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
page link:
https://projecteuler.net/problem=4

dax 2023-04-21 13:41:23
*/
#include "problem.h"

bool Solution::is_palindrome(long number)
{
	auto number_string = std::to_string(number);
	int middle = number_string.size() / 2;

	for(int i = 0; i < middle; ++i)
	{
		if(*(number_string.begin() + i) != *(number_string.end() - 1 - i)) return false;
	}

	return true;
}

long Solution::largest_palindrome(int digits)
{
	int cap = std::pow(10, digits);
	long max{0};

	for(int i = 0; i < cap; ++i)
		for(int j = 0; j < cap; ++j)
		{
			long product = i * j;

			if(is_palindrome(product) && product > max) max = product;
		}

	return max;
}
void Solution::answer()
{
	std::cout << "The answer is: " << largest_palindrome(3) << std::endl;
}
