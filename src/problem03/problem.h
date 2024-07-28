#pragma once
#include <iostream>
#include <vector>

class Solution
{
	public:
		bool is_prime_brutal(unsigned long n);
		unsigned get_prime_factors(unsigned long n);
		void answer();

	private:
		std::vector<unsigned> prime_factors;

};
