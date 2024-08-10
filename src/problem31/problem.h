#pragma once
#include <iostream>
#include <vector>

class Solution
{
	public:
		Solution(): dp(201, 0) {};

		std::vector<unsigned> coins{1, 2, 5, 10, 20, 50, 100, 200};
		std::vector<unsigned> dp;
		void answer();

};
