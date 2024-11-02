/*
Problem page link:
https://projecteuler.net/problem=43

dax 2024-09-18 10:03:00
*/
#include "problem.h"
#include <algorithm>

void Solution::build_pandigit(std::string current_number, uint depth)
{
	if(current_number.front() == '0')
		return;

	if(depth > 3 && depth <= 10)
	{
		auto seg = current_number.substr(depth - 3, 3);

		if(std::stoi(seg) % divisors[depth - 4] != 0) return; // 剪枝
	}

	if(depth == 10)
	{
		sum_of_pandigit += std::stoull(current_number);
		return;
	}

	for(int i = 0; i < 10; ++i)
	{
		if(!used_digits[i])
		{
			used_digits[i] = true;
			build_pandigit(current_number + std::to_string(i), depth + 1);
			used_digits[i] = false;
		}
	}
}

void Solution::answer()
{
	ulong sum{};

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

void Solution::answer2()
{
	build_pandigit("", 0);
	std::cout << "The answer is: " << sum_of_pandigit << std::endl;
}
