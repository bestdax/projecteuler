#pragma once
#include <iostream>
#include <vector>

class Solution
{
	private:
		std::vector<unsigned long> pentagonals;
		unsigned n {};

	public:
		void next_pentagonal();
		void answer();

};
