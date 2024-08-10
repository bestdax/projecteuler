/*
Problem page link:
https://projecteuler.net/problem=36

dax 2024-08-11 07:10:43
*/
#include "problem.h"
bool Solution::is_palindrome(unsigned long n)
{
	auto sn = std::to_string(n);
	auto l = sn.begin();
	auto r = sn.end() - 1;

	while(l < r)
	{
		if(*l != *r) return false;

		++l, --r;
	}

	return true;
}

bool Solution::is_binary_palindrome(unsigned long n)
{
	std::string sn{};

	while(n)
	{
		sn = std::to_string(n % 2) + sn;
		n /= 2;
	}

	auto l = sn.begin();
	auto r = sn.end() - 1;

	while(l < r)
	{
		if(*l != *r) return false;

		++l, --r;
	}

	return true;
}

void Solution::answer()
{
	unsigned long sum{};

	for(unsigned i = 1; i < 1e6; ++i)
	{
		if(is_palindrome(i) && is_binary_palindrome(i))
			sum += i;
	}

	std::cout << "The answer is: " << sum << std::endl;
}
