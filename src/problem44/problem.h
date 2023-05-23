#pragma once
#include <iostream>
#include <vector>

class Solution
{
public:
	Solution();
	void find_next_pentagonal_number();
	unsigned long find_pairs_difference();
	void answer();
private:
	std::vector<unsigned long> pentagonal_numbers;

};
