/*
Problem page link:
https://projecteuler.net/problem=4

dax 2024-07-29 13:15:04
*/
#include "problem.h"
#include <string>

bool Solution::is_palindrome(unsigned long n)
{
	auto nstr = std::to_string(n);
	auto left = nstr.begin();
	auto right = nstr.end() - 1;

	while(left < right)
	{

		if(*left != *right) return false;

		left++;
		right--;
	}

	return true;
}

unsigned long Solution::largest_palindrome_product()
{
	unsigned long result{};

	for(int i = 100; i < 1000; ++i)
		for(int j = 100; j < 1000; ++j)
		{
			auto product = i * j;

			if(is_palindrome(product) && product > result) result = product;

		}

	return result;
}

void Solution::answer()
{
	std::cout << "The answer is: " << largest_palindrome_product() << std::endl;
}
