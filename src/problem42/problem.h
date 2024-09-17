#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution
{
		std::vector<std::string> names;
		unsigned max_length{};
		std::unordered_set<unsigned> triangles{1};
	public:
		void read_names();
		void gen_triangles();
		unsigned name_score(std::string&);
		void answer();

};
