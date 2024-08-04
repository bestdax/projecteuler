#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution
{
	public:
		std::vector<unsigned long> proper_factors(unsigned long n);
		bool is_amicable(unsigned long n);
		void answer();
	private:
		std::vector<unsigned long> amicables;

};
