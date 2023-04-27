#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	Solution();
	int find_max_parents(unsigned row, unsigned col);
	std::vector<std::vector<int>> handled_row_by_row();
	int max_sum();
	void answer();

private:
	std::vector<std::vector<int>> triangle;


};
