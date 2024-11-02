#pragma once
#include <utils.h>
#include <vector>

template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

class Solution
{
	private:
		std::vector<std::vector<uint>> matrix;
	public:
		void read_matrix();
		ulong dijkstra();
		void answer();

};
