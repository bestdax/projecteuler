#pragma once
#include <iostream>
#include "number.h"
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include "timer.h"

class Solution
{
	private:
		std::vector<unsigned long> primes = dax::sieve_of_Euler(1e4);

	public:
		void answer();
		bool is_prime_set(std::set<std::vector<unsigned long>>&, std::vector<unsigned long>, unsigned long n);
		std::set<std::vector<unsigned long>> find_all_prime_pairs();
		std::set<std::vector<unsigned long>> find_all_sets_with_n_members(unsigned n);

};
