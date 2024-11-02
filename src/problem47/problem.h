#pragma once
#include <utils.h>
#include <vector>
#include <prime.h>

class Solution
{
		unsigned limit;
		std::vector<bool> is_prime;
		std::vector<char> prime_factor_count;
	public:
		Solution(): is_prime(dax::sieve_of_eratosthenes(limit)), limit(1e6)
		{
			prime_factor_count.resize(limit + 1);
		};

		void compute_prime_factors();
		unsigned count_distinct_prime_factors(ulong n);
		void answer();
		void answer2();

};
