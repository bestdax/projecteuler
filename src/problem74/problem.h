#pragma once
#include <utils.h>
#include <vector>

class Solution
{
	private:
		std::vector<unsigned> digit_factorials;
	public:
		Solution();
		ulong factorial_sum_of_digits(ulong n);
		void answer();

};
