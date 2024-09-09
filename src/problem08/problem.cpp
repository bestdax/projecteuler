/*
Problem page link:
https://projecteuler.net/problem=8

dax 2024-09-09 16:57:49
*/
#include "problem.h"

unsigned long Solution::largest_product(unsigned n)
{
	unsigned long lp{};

	for(auto it = ns.begin(); it < ns.end() - n; ++it)
	{
		unsigned long product{1};

		for(unsigned i = 0; i < n; ++i)
		{
			// 如果遇到零则将it跳到这个位置并中断当前循环
			if(*(it + i) == '0')
			{
				it += i;
				break;
			}

			product *= (*(it +i) - '0');
		}

		lp = product > lp ? product : lp;
	}

	return lp;
}

void Solution::answer()
{
	auto result = largest_product(13);
	std::cout << "The answer is: " << result << std::endl;
}
