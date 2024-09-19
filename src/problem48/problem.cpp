/*
Problem page link:
https://projecteuler.net/problem=48

dax 2024-09-19 14:01:40
*/
#include "problem.h"
#include <stringint.h>
#include <bigint.h>

void Solution::answer()
{
	StringInt result;

	for(StringInt i = 1; i <= 1000; ++i)
	{
		result += i.power(i);
	}

	auto ns = result.to_string();

	std::cout << "The answer is: " << ns.substr(ns.size() - 10, 10) << std::endl;
}

void Solution::answer2()
{
	BigUInt result;

	for(BigUInt i = 1; i <= 1000; ++i)
	{
		result += i.power(i);
	}

	auto ns = result.to_string();
	std::cout << "The answer is: " << ns.substr(ns.size() - 10, 10) << std::endl;
}
