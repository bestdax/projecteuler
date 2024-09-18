/*
Problem page link:
https://projecteuler.net/problem=43

dax 2024-09-18 10:03:00
*/
#include "problem.h"
#include <algorithm>

void Solution::answer()
{
	unsigned long sum{};

	do
	{
		bool all_divisible = true;

		for(int i = 0; i < divisors.size(); ++i)
		{
			auto seg = pandigit.substr(i + 1, 3);

			if(std::stoul(seg) % divisors[i] != 0)
			{
				all_divisible = false;
				break;
			}
		}

		if(all_divisible) sum += std::stoul(pandigit);
	}
	while(std::next_permutation(pandigit.begin(), pandigit.end()));

	std::cout << "The answer is: " << sum << std::endl;
}
