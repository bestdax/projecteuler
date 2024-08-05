#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>

class Solution
{
	public:
		void read_file(std::string filename);
		unsigned long namescore();
		void answer();

	private:
		std::vector<std::string> names;

};
