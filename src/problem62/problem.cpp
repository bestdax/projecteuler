/*
Problem description:

page link:
https://projecteuler.net/problem=

dax 2023-06-05 14:42:04
*/
#include "problem.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

void Solution::answer()
{
	unsigned n{2};
	std::map<std::string, std::vector<unsigned long>> cube_map{};
	unsigned target = 5;

	while(true)
	{
		unsigned long number = std::pow(n, 3);
		auto number_str = std::to_string(number);
		std::sort(number_str.begin(), number_str.end());
		cube_map[number_str].push_back(number);

		if(cube_map[number_str].size() == target)
		{
			std::cout << "The answer is: " << cube_map[number_str].front() << std::endl;
			break;
		}

		++n;
	}
}
