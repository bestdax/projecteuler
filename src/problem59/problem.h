#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <numeric>

class Solution
{
	public:
		void read_file();
		void answer();
		std::string ciphered;
		std::string deciphered;
		bool is_english(std::string& text);
		void decipher();

};
