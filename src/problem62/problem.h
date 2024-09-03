#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
	private:
		std::vector<unsigned long> cubics{1};
	public:
		Solution();
		void answer();
		unsigned number_of_digits(unsigned long n);
		bool is_permutation(unsigned long a, unsigned long b);

};
