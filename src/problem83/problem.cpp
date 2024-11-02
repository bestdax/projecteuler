/*
Problem page link:
https://projecteuler.net/problem=83

dax 2024-11-02 13:02:15
*/
#include "problem.h"
#include <filesystem>
#include <fstream>
#include <limits>
#include <queue>

void Solution::read_matrix()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0083_matrix.txt");

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

ulong Solution::dijkstra()
{
	uint mwidth = matrix[0].size();
	uint mheight = matrix.size();

	// 存储距离的数组
	std::vector<std::vector<ulong>> dist(matrix.size(), std::vector<ulong>(matrix.size(),
	                                     std::numeric_limits<ulong>::max()));

	// 初始化左上角的距离为零
	dist[0][0] = 0;

	// 用一个最小堆来存储当前的距离及坐标
	MinHeap<std::pair<ulong, std::pair<uint, uint>>> min_heap;

	min_heap.push({matrix[0][0], {0, 0}});

	// 上下左右四个方向
	std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

	while(not min_heap.empty())
	{
		auto [current_dist, pos] = min_heap.top();
		min_heap.pop();
		auto x = pos.first, y = pos.second;

		// 遍历四个方向
		for(const auto& [dx, dy] : directions)
		{
			auto nx = x + dx, ny = y + dy;

			if(nx >= 0 && nx < mwidth && ny >= 0 && ny <= mheight) // 检查边界
			{
				ulong new_dist = current_dist + matrix[nx][ny];

				if(new_dist < dist[nx][ny])
				{
					dist[nx][ny] = new_dist;
					min_heap.push({new_dist, {nx, ny}});
				}
			}
		}
	}

	return dist[mheight - 1][mwidth - 1];
}

void Solution::answer()
{
	read_matrix();
	auto result = dijkstra();
	print("The answer is:", result);
}
