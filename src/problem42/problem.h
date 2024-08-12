#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

class Solution
{
	public:
		Solution();
		void answer();
		unsigned long calculate_name_score(std::string name);
	private:
		std::vector<std::string> names;

};
