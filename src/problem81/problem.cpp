/*
Problem page link:
https://projecteuler.net/problem=81

dax 2024-10-08 22:27:57
*/
#include "problem.h"
#include <fstream>
#include <filesystem>
#include <sstream>

void Solution::answer()
{
	// 读取矩阵
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

	for(unsigned row = 0; row < 80; ++row)
		for(unsigned col = 0; col < 80; ++ col)
		{
			if(row == 0 && col != 0) matrix[row][col] += matrix[row][col - 1];
			else if(row != 0 && col == 0) matrix[row][col] += matrix[row - 1][col];
			else if(row != 0 && col != 0) matrix[row][col] += std::min(matrix[row - 1][col], matrix[row][col - 1]);
		}

	print("The answer is:", matrix[79][79]);
}
