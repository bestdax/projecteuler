#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	Solution();
	int find_max_parent(unsigned row, unsigned col);
	void handle_row_by_row();
	int max_sum();
	void answer();

private:
	std::vector<std::vector<int>> triangle;


};
