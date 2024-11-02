#pragma once
#include <utils.h>
#include <vector>

class Solution
{
	private:
	bool _is_abundant(unsigned n);
	public:
		std::vector<bool> is_abundant;
		Solution();
		bool is_sum_of_two_abundants(unsigned n);
		void answer();

};
