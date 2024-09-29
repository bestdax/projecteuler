/*
Problem page link:
https://projecteuler.net/problem=60

dax 2024-09-26 12:49:33
*/
#include "problem.h"
#include <prime.h>
#include <vector>
#include <numutils.h>
#include <numeric>
#include <utils.h>

bool Solution::is_prime_pair(unsigned long a, unsigned long b)
{
	return dax::is_prime_improved(dax::concatenate(a, b)) && dax::is_prime_improved(dax::concatenate(b, a));
}

bool Solution::is_prime_group(std::vector<unsigned long> group)
{
	if(group.empty()) return true;

	if(group.size() == 1 && dax::is_prime_improved(group.back())) return true;

	for(unsigned i = 0; i < group.size() - 1; ++i)
		for(unsigned j = i + 1; j < group.size(); ++j)
		{
			if(not group_set.contains({group[i], group[j]})) return false;
		}

	return true;
}

void Solution::init_groups()
{
	for(unsigned long i = 3; i < limit; ++i)
		for(unsigned long j = i + 1; j <= limit; ++j)
		{
			if(is_prime[i] && is_prime[j] && is_prime_pair(i, j))
			{
				group_set.insert({i, j});
				prime_groups.push_back({i, j});
			}
		}
}

void Solution::answer()
{
	is_prime = dax::sieve_of_eratosthenes(limit);
	init_groups();
	std::set<unsigned long> sum_set;

	for(unsigned loop = 0; loop < 3; ++loop)
	{
		std::vector<std::vector<unsigned long>> temp_groups;

		for(const auto& group : prime_groups)
		{
			for(unsigned long i = group.back() + 1; i <= limit; ++i)
			{
				if(is_prime[i])
				{
					auto copy(group);
					copy.push_back(i);

					if(is_prime_group(copy))
					{
						temp_groups.push_back(copy);
						if(copy.size() == 5)
						{
							sum_set.insert(std::accumulate(copy.begin(), copy.end(), 0));
						}
					}

				}
			}
		}

		prime_groups = temp_groups;
	}

	std::cout << "The answer is: " << *sum_set.begin() << std::endl;
}
