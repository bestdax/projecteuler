/*
Problem page link:
https://projecteuler.net/problem=82

dax 2024-10-19 12:33:39
*/
#include "problem.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <limits>

void Solution::read_matrix()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0082_matrix.txt");

	std::ifstream file(p);
	std::string line;

	while(std::getline(file, line))
	{
		std::string ns;
		std::vector<uint> row;
		std::stringstream ss(line);

		while(std::getline(ss, ns, ','))
		{
			row.push_back(std::stoul(ns));
		}

		matrix.push_back(row);

	}
}

void Solution::answer()
{
	read_matrix();

	// 定义一个与matrix尺寸一样的vector
	uint size = matrix.size();
	std::vector<std::vector<uint>> dp(size, std::vector<uint>(size));

	// 初始化dp数组的第一列
	for(uint row = 0; row < size; ++row)
		dp[row][0] = matrix[row][0];

	for(uint col = 1; col < size; ++col)
	{

		// 从左到右更新
		for(uint row = 0; row < size; ++row)
		{
			dp[row][col] = matrix[row][col] + dp[row][col - 1];
		}

		// 从上到下更新
		for(uint row = 1; row < size; ++row)
		{
			dp[row][col] = std::min(dp[row - 1][col] + matrix[row][col], dp[row][col]);
		}

		// 从下到上更新
		for(uint row = size - 2; row - 1 < row; --row)
		{
			dp[row][col] = std::min(dp[row + 1][col] + matrix[row][col], dp[row][col]);
		}
	}

	uint result = std::numeric_limits<uint>::max();

	for(uint row = 0; row < 80; ++row)
		result = std::min(result, dp[row][size - 1]);

	print("The answer is:", result);
}
