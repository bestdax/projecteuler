#pragma once
#include <utils.h>
#include <set>

class Solution
{
	private:
		std::unordered_map<char, std::set<char>> graph;
	public:
		void read_pass();
		void answer();

};
