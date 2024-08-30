/*
Problem page link:
https://projecteuler.net/problem=60

dax 2024-08-27 08:01:28
*/
#include "problem.h"

unsigned long concatenate(unsigned long a, unsigned long b)
{
	unsigned long multiplier = 1;

	while(b > multiplier) multiplier *= 10;

	return a * multiplier + b;
}

std::set<std::vector<unsigned long>> Solution::find_all_prime_pairs()
{
	std::set<std::vector<unsigned long>> pairs;

	for(auto it1 = primes.begin(); it1 != primes.end() - 1; ++it1)
		for(auto it2 = it1 + 1; it2 != primes.end(); ++it2)
		{
			if(dax::is_prime(concatenate(*it1, *it2)) && dax::is_prime(concatenate(*it2, *it1)))
			{
				pairs.insert({*it1, *it2});
			}
		}

	return pairs;
}

bool Solution::is_prime_set(std::set<std::vector<unsigned long>>& sets, std::vector<unsigned long> set,
                            unsigned long n)
{
	if(n <= set.back()) return false;

	for(int i = 0 ; i < set.size(); ++i)
	{
		auto copy = set;
		copy.erase(copy.begin() + i);

		copy.push_back(n);

		if(!sets.contains(copy)) return false;
	}

	return true;
}

std::set<std::vector<unsigned long>> Solution::find_all_sets_with_n_members(unsigned n)
{
	auto sets = find_all_prime_pairs();

	while(n > 2)
	{
		std::set<std::vector<unsigned long>> level_sets;

		for(auto& set : sets)
		{
			for(auto &p : primes)
			{
				if(is_prime_set(sets, set, p))
				{
					auto copy = set;
					copy.push_back(p);
					level_sets.insert(copy);
				}
			}
		}

		--n;
		sets = level_sets;
	}

	return sets;
}

void Solution::answer()
{
	auto result = find_all_sets_with_n_members(5);
	unsigned long min_sum{std::numeric_limits<unsigned long>::max()};

	for(auto&set : result)
	{
		auto sum = std::accumulate(set.begin(), set.end(), 0);

		if(sum < min_sum)
		{
			min_sum = sum;
		}
	}

	std::cout << "The answer is: " << min_sum << std::endl;

}
