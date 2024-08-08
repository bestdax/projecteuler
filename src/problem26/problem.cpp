/*
Problem page link:
https://projecteuler.net/problem=26

dax 2024-08-08 17:14:11
*/
#include "problem.h"

unsigned Solution::reciprocal(unsigned long n)
{
	unsigned long numerator{1};
	std::vector<unsigned long> numerators{1};

	while(true)
	{

		while(numerator < n) numerator *= 10;

		numerator %= n;

		if(!numerator) return numerators.size();

		auto it = std::find(numerators.begin(), numerators.end(), numerator);

		if(it != numerators.end())
			return numerators.end() - it;
		else
			numerators.push_back(numerator);
	}
}

void Solution::answer()
{
	int max = 0;
	unsigned long n{};

	for(int i = 2; i < 1000; ++i)
	{
		auto l = reciprocal(i);

		if(l > max)
		{
			max = l;
			n = i;
		}
	}

	std::cout << "The answer is: " << n << std::endl;
}
