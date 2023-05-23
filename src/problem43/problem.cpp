/*
Problem description:
Sub-string divisibility
Problem 43
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of
each of the digits 0 to 9 in some order, but it also has a rather interesting
sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note
the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.

page link:
https://projecteuler.net/problem=43

dax 2023-05-23 13:39:57
*/
#include "problem.h"
#include <vector>
#include <algorithm>

bool Solution::is_divisible()
{
	std::vector<std::string> substrings{};
	std::vector<unsigned> divisors{2, 3, 5, 7, 11, 13, 17};

	for(unsigned i = 1; i < 8; ++i)
		substrings.push_back(digits.substr(i, 3));

	for(unsigned i = 0; i < 7; ++i)
	{
		if(std::stoi(substrings[i]) % divisors[i] != 0) return false;
	}

	return true;
}

unsigned long Solution::sum_of_all_divisible()
{
	unsigned long sum{};

	do
	{
		if(is_divisible()) sum += std::stoul(digits);
	}
	while(std::next_permutation(digits.begin(), digits.end()));

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_all_divisible() << std::endl;
}
