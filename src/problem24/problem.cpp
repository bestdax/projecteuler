/*
Problem page link:
https://projecteuler.net/problem=24

dax 2024-08-07 14:56:58
*/
#include "problem.h"

void Solution::next_permutation()
{

	while(p != digits.rend() - 1)
	{
		if(*p > *(p + 1))
		{
			for(auto it = digits.rbegin(); it <= p; ++it)
			{
				if(*it > *(p + 1))
				{
					std::swap(*it, *(p + 1));
					std::sort(digits.rbegin(), p + 1, std::greater<short>());
					p = digits.rbegin();
					return;
				}
			}
		}

		++p;

		if(p == digits.rend() - 1)
		{
			std::sort(digits.begin(), digits.end());
			p = digits.rbegin();
			break;
		}
	}

}

void Solution::print()
{
	for(auto i : digits)
		std::cout << i;

	std::cout << std::endl;
}

void Solution::answer()
{
	for(int i = 0; i < 1e6; ++i)
		next_permutation();

	std::cout << "The answer is: " ;
	print();
	std::cout << std::endl;
}
