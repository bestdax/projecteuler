#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>

class Solution
{
public:
	Solution();
	std::string get_text_from_file(std::string filename);
	std::string get_absolute_resource_path(std::string path);
	void get_names();
	void sort();
	unsigned get_rank(std::string name);
	unsigned get_char_sum(std::string name);
	unsigned get_name_score(std::string name);
	unsigned long sum_of_name_score();
	void answer();

	std::vector<std::string> names;
};
