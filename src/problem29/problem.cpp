/*
Problem page link:
https://projecteuler.net/problem=29

dax 2024-09-12 12:31:21
*/
#include "problem.h"
#include <vector>
#include <stringint.h>
#include <algorithm>
#include <bigint.h>

void Solution::answer()
{
	std::vector<StringInt> powers;

	for(StringInt a = 2; a <= 100; ++a)
		for(unsigned b = 2; b <= 100; ++b)
		{
			powers.push_back(a.power(b));
		}

	std::sort(powers.begin(), powers.end());
	auto last = std::unique(powers.begin(), powers.end());
	powers.erase(last, powers.end());

	std::cout << "The answer is: " << powers.size() << std::endl;
}

void Solution::answer_bint()
{

	std::vector<BigUInt> powers;

	for(BigUInt a = 2; a <= 100; ++a)
		for(unsigned b = 2; b <= 100; ++b)
		{
			powers.push_back(a.power(b));
		}

	std::sort(powers.begin(), powers.end());
	auto last = std::unique(powers.begin(), powers.end());
	powers.erase(last, powers.end());

	std::cout << "The answer is: " << powers.size() << std::endl;
}
