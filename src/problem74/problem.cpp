/*
Problem page link:
https://projecteuler.net/problem=74

dax 2024-10-06 14:17:25
*/
#include "problem.h"
#include <numutils.h>
#include <set>
#include <unordered_map>

void Solution::answer()
{
	// 预先计算好数字0-9的阶乘
	std::vector<unsigned>digit_factorial;

	for(unsigned i = 0; i < 10; ++i)
	{
		digit_factorial.push_back(dax::factorial(i));
	}

	unsigned count{};

	std::unordered_map<unsigned, unsigned long> factorials_map;

	for(unsigned i = 1; i < 1e6; ++i)
	{
		std::unordered_map<unsigned, std::set<unsigned long>> chains_map;
		chains_map[i].insert(i);

		auto number = i;

		while(true)
		{
			unsigned long chain_member{};

			// 计算数字阶乘和
			if(factorials_map[number])
			{
				chain_member = factorials_map[number];
			}
			else
			{
				while(number)
				{
					chain_member += digit_factorial[number % 10];
					number /= 10;
				}

				factorials_map[number] = chain_member;

			}

			if(chains_map[i].contains(chain_member))
			{
				if(chains_map[i].size() == 60)
				{
					++count;
					print(chains_map[i]);
				}

				break;
			}
			else
			{
				chains_map[i].insert(chain_member);
				number = chain_member;
			}
		}

	}

	print("The answer is:", count);
}
