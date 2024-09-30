#pragma once
#include <iostream>
#include <vector>
#include <prime.h>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <set>
#include <limits>

class Solution
{
	private:
		unsigned long limit;
		unsigned target_len{5};
		std::vector<unsigned long> primes;
		std::unordered_map<unsigned long, std::set<unsigned long>> group_map;
		unsigned long min{std::numeric_limits<unsigned long>::max()};
		std::set<unsigned long> target;

	public:
		Solution(): limit(1e4)
		{
			primes = dax::sieve_of_euler(limit);
			primes.erase(primes.begin()); //移除2
			primes.erase(primes.begin() + 1); //移除5

			for(unsigned i = 0; i < primes.size() - 1; ++i)
				for(unsigned j = i + 1; j < primes.size(); ++j)
				{
					if(is_prime_pair(primes[i], primes[j]))
					{
						group_map[primes[i]].insert(primes[j]);
						group_map[primes[j]].insert(primes[i]);
					}
				}
		};

		void find_groups(unsigned long start_node);

		bool is_prime_pair(unsigned long a, unsigned long b);
		void answer();
};
