#pragma once
#include <iostream>
#include <vector>
#include <prime.h>

class Solution
{
		std::vector<bool> is_prime;
	public:
		Solution(): is_prime(dax::sieve_of_eratosthenes(1e6)) {};

		unsigned count_distinct_prime_factors(unsigned long n);
		void answer();

};
