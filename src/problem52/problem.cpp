/*
Problem page link:
https://projecteuler.net/problem=52

dax 2024-08-14 14:30:07
*/
#include "problem.h"

std::string Solution::sorted_number_string(unsigned long n)
{
	auto ns = std::to_string(n);
	std::sort(ns.begin(), ns.end());
	return ns;
}

void Solution::answer()
{
	unsigned long number{1};

	while(true)
	{
		++number;

		unsigned count{};

		for(int i = 2; i < 7; ++i)
		{
			if(sorted_number_string(number) != sorted_number_string(number * i))
				break;

			++count;
		}

		if(count == 5)
		{
			std::cout << "The answer is: " << number << std::endl;
			break;
		}
	}

}
