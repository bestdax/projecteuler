/*
Problem page link:
https://projecteuler.net/problem=61

dax 2024-09-30 18:45:55
*/
#include "problem.h"
#include <utils.h>
#include <stack>

std::ostream& operator<<(std::ostream& os, const Polygon& polygon)
{
	os << polygon.number;
	return os;
}

Solution::Solution()
{
	// generate Polygon numbers
	uint n = 1;
	std::vector<uint> current_polygonals;

	while(true)
	{
		current_polygonals = {n * (n + 1) / 2, n * n, n * (3 * n - 1) / 2, n * (2 * n - 1), n * (5 * n - 3) / 2, n * (3 * n - 2)};

		if(current_polygonals.front() > 10000) break;

		for(uint i = 3; i < 9; ++i)
		{
			if(current_polygonals[i - 3] > 999 && current_polygonals[i - 3] < 10000)
				polygons.push_back({current_polygonals[i - 3], i});
		}

		++n;
	}

	// generate graph
	for(auto& polygon_a : polygons)
		for(auto &polygon_b : polygons)
		{
			if(polygon_a.sides != polygon_b.sides && is_cyclic(polygon_a.number, polygon_b.number))
			{
				graph[polygon_a].push_back(polygon_b);
			}
		}
}

bool Solution::is_cyclic(uint a, uint b)
{
	return a % 100 == b / 100;
}

void Solution::answer()
{
	std::stack<std::vector<Polygon>> stack;

	for(auto& start_polygon : polygons)
	{
		stack.push({start_polygon});

		while(not stack.empty())
		{
			auto current_chain = stack.top();
			stack.pop();

			for(const auto& next_polygon : graph[current_chain.back()])
			{
				bool is_valid{true};

				// 检查是否可以添加到当前的数据链中
				for(const auto& poly_in_chain : current_chain)
				{
					if(poly_in_chain.sides == next_polygon.sides)
					{
						is_valid = false;
						break;
					}
				}

				if(is_valid)
				{
					auto new_chain(current_chain);
					new_chain.push_back(next_polygon);
					stack.push(new_chain);

					// 检查是否有合乎要求的6个元素的链形成
					if(new_chain.size() == 6 and is_cyclic(new_chain.back().number, new_chain.front().number))
					{
						print(new_chain);
						uint sum{};

						for(const auto&poly : new_chain)
						{
							sum += poly.number;
						}

						print("The answer is:", sum);

						return;
					}
				}
			}
		}
	}
}
