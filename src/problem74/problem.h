#pragma once
#include <utils.h>
#include <vector>

class Solution
{
	private:
		std::vector<unsigned> digit_factorials;
	public:
		Solution();
		unsigned long factorial_sum_of_digits(unsigned long n);
		void answer();

};
