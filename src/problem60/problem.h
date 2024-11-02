#pragma once
#include <utils.h>
#include <utils.h>
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
		ulong limit;
		unsigned target_len{5};
		std::vector<ulong> primes;
		std::unordered_map<ulong, std::set<ulong>> group_map;
		ulong min{std::numeric_limits<ulong>::max()};
		std::set<ulong> target;

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

		void find_groups(ulong start_node);

		bool is_prime_pair(ulong a, ulong b);
		void answer();
};
