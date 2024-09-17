/*
Problem page link:
https://projecteuler.net/problem=41

dax 2024-09-17 23:03:50
*/
#include "problem.h"
#include <prime.h>
#include <algorithm>
#include <string>

void Solution::answer()
{
	std::string pandigit = "7654321";

	do
	{
		if(dax::is_prime_improved(std::stoul(pandigit)))
		{
			std::cout << "The answer is: " << pandigit << std::endl;
			break;
		}
	}
	// 并没有考虑在7位数时找不到的情况
	while(std::prev_permutation(pandigit.begin(), pandigit.end()));
}
