/*
Problem page link:
https://projecteuler.net/problem=62

dax 2024-10-01 18:28:36
*/
#include "problem.h"
#include <utils.h>
#include <unordered_map>
#include <string>
#include <algorithm>

void Solution::answer()
{
	std::unordered_map<std::string, std::vector<ulong>> cubic_map;
	ulong n = 0;

	while(true)
	{
		++n;

		auto cubic = n * n * n;

		auto ns = std::to_string(cubic);
		std::sort(ns.begin(), ns.end());

		cubic_map[ns].push_back(cubic);

		if(cubic_map[ns].size() == 5)
		{
			print("The answer is:", cubic_map[ns].front());
			return;
		}

	}

}
