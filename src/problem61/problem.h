#pragma once
#include <iostream>
#include <set>
#include <vector>

struct Polygonal
{
	unsigned sides;
	unsigned number;
	unsigned n;
};

class Solution
{
	private:
		std::vector<Polygonal> polygonals;
	public:
		Solution();
		bool is_cyclic(unsigned, unsigned);
		void answer();

};
