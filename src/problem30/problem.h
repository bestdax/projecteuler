#pragma once
#include <iostream>
#include <vector>

class Solution
{
	private:
		std::vector<unsigned> digital_powers;
	public:
		Solution();
		unsigned digital_power_sum(unsigned n);
		void answer();

};
