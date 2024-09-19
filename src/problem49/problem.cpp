/*
Problem page link:
https://projecteuler.net/problem=49

dax 2024-09-19 14:55:17
*/
#include "problem.h"
#include <prime.h>
#include <algorithm>
#include <string>
#include <unordered_map>

bool has_same_digits(unsigned n, unsigned m)
{
	auto sn = std::to_string(n);
	auto sm = std::to_string(m);
	std::sort(sn.begin(), sn.end());
	std::sort(sm.begin(), sm.end());
	return sn == sm;
}

std::string sort_digits(unsigned n)
{
	auto ns = std::to_string(n);
	std::sort(ns.begin(), ns.end());
	return ns;
}

void Solution::answer()
{
	auto is_prime = dax::sieve_of_eratosthenes(1e4);

	for(unsigned i = 1001; i < 1e4; ++i)
	{
		if(i == 1487) continue;

		if(is_prime[i])
			for(unsigned j = i + 1; j < 1e4; ++j)
			{
				if(is_prime[j] && has_same_digits(i, j))
				{
					auto k = j + j - i;

					if(k < 1e4 && is_prime[k] && has_same_digits(i, k))
						std::cout << "The answer is: " << i << j << k << std::endl;
				}
			}
	}

}

void Solution::answer2()
{
	auto is_prime = dax::sieve_of_eratosthenes(1e4 - 1);

	std::unordered_map<std::string, std::vector<unsigned>> prime_groups;

	for(unsigned i = 1000; i < 1e4; ++i)
	{
		if(is_prime[i])
		{
			auto sorted_digits = sort_digits(i);
			prime_groups[sorted_digits].push_back(i);
		}
	}

	for(const auto& entery : prime_groups)
	{
		const auto& group = entery.second;

		if(group.size() < 3) continue;

		for(unsigned i = 0; i < group.size() - 2; ++i)
			for(unsigned j = i + 1; j < group.size() - 1; ++j)
			{
				unsigned k = 2 * group[j] - group[i];
				auto it = std::find(group.begin(), group.end(), k);

				if(it != group.end() && group[i] != 1487)
					std::cout << "The answer is: " << group[i] << group[j] << k << std::endl;
			}
	}
}
