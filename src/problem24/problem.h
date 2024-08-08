#pragma once
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Solution
{
	public:
		Solution(): p(digits.rbegin()) {};

		std::vector<short> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		void next_permutation();
		void answer();
		typeof(digits.rbegin()) p;
		void print();

};
