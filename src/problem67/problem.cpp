/*
Problem page link:
https://projecteuler.net/problem=67

dax 2024-10-02 21:40:01
*/
#include "problem.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void Solution::read_matrix()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0067_triangle.txt");

	std::ifstream file(p);

	std::string line;
	uint row = 0;

	while(std::getline(file, line))
	{
		std::stringstream ss(line);

		std::string sn;
		uint column = 0;

		while(ss >> sn)
		{
			matrix[row][column] = std::stoul(sn);
			++column;
		}

		++row;

	}

}

void Solution::answer()
{
	read_matrix();
	std::vector<uint> floating_row(100);

	for(uint i = 0; i < 100; ++i)
	{
		std::vector<uint> temprow(100);

		for(uint j = 0; j <= i; ++j)
		{
			uint upper_left = j == 0 ? 0 : floating_row[j - 1];
			uint upper_right = i == j ? 0 : floating_row[j];
			temprow[j] = std::max(upper_left, upper_right)  + matrix[i][j];
		}

		floating_row = temprow;
	}

	print("The answer is:", *std::max_element(floating_row.begin(), floating_row.end()));
}
