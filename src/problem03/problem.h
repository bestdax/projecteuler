#pragma once
#include <iostream>
#include <vector>

class Solution
{
	public:
		bool is_prime_brutal(unsigned long n);
		unsigned get_the_greatest_prime_factor(unsigned long n);
		void answer();

	private:
		std::vector<unsigned> prime_factors;

};
