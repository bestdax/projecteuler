#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	Solution();
	unsigned compute_word_value(std::string word);
	unsigned how_many_triangle_words();

	void answer();
private:
	std::vector<std::string> words;

};
