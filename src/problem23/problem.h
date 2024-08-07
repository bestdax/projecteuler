#pragma once
#include <iostream>
#include "number.h"
#include <vector>
#include <algorithm>

class Solution
{
	public:
		bool is_sum_of_two_abundants(unsigned long n);
		void answer();
	private:
		std::vector<unsigned long> abundants{12};

};
