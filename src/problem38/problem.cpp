/*
Problem page link:
https://projecteuler.net/problem=38

dax 2024-09-16 14:24:46
*/
#include "problem.h"
#include <algorithm>
#include <string>

void Solution::answer()
{
	std::string ns = "987654321";

	do
	{
		// 每次循环从左边多取一个数字
		for(int i = 1; i < 5; ++i)
		{
			uint first_seg = std::stoul(ns.substr(0, i));

			auto seg_start_index = i;
			uint n = 2;
			std::string calculated_ns = std::to_string(first_seg);

			while(calculated_ns.size() < ns.size())
			{
				calculated_ns += std::to_string(first_seg * n);

				if(!ns.starts_with(calculated_ns)) break;

				++n;

			}

			if(calculated_ns == ns)
			{
				std::cout << "The answer is: " << ns << std::endl;
				return;
			}
		}

	}
	while(std::prev_permutation(ns.begin(), ns.end()));

}
