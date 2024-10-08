/*
Problem page link:
https://projecteuler.net/problem=81

dax 2024-10-08 22:27:57
*/
#include "problem.h"
#include <fstream>
#include <filesystem>
#include <sstream>
#include <utility>
#include <limits>

void Solution::answer()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0081_matrix.txt");
	std::ifstream file(p);

	std::string line;

	while(std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string ns;
		std::vector<unsigned> row;

		while(std::getline(ss, ns, ','))
		{
			row.push_back(std::stoul(ns));
		}

		matrix.push_back(row);
	}

	std::pair<unsigned, unsigned> coordinate{0, 0};

	unsigned long sum{matrix[0][0]};

	while(coordinate.first < 80 && coordinate.second < 80)
	{
		unsigned below = std::numeric_limits<unsigned>::max();
		unsigned right = std::numeric_limits<unsigned>::max();

		if(coordinate.second < 79)
			right = matrix[coordinate.first][coordinate.second + 1];

		if(coordinate.first < 79)
			below = matrix[coordinate.first + 1][coordinate.second];

		if(right < below)
		{
			sum += right;
			++coordinate.second;
		}
		else
		{
			sum += below;
			++coordinate.first;
		}

	}
	sum -= std::numeric_limits<unsigned>::max();

	print("The answer is:", sum);
}
