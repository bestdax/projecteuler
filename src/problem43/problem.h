#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution
{
	private:
		std::vector<unsigned> divisors{2, 3, 5, 7, 11, 13, 17};
		std::string pandigit = "1023456789";
	public:
		void answer();

};
