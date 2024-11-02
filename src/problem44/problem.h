#pragma once
#include <utils.h>
#include <vector>

class Solution
{
	private:
		std::vector<ulong> pentagonals;
		unsigned n {};

	public:
		void next_pentagonal();
		void answer();

};
