#pragma once
#include <iostream>
#include <vector>

class Solution
{
	private:
		std::vector<short> combination{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	public:
		bool next_permutation();
		void answer();

};
