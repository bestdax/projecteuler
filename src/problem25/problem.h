#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution
{
	public:
		std::vector<char> fiba{1};
		std::vector<char> fibb{1};
		std::vector<char> temp{};
		void next_fib();
		std::string fib();
		unsigned nth{};
		void answer();

};
