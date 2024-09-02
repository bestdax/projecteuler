/*
Problem page link:
https://projecteuler.net/problem=61

这道题目需要注意的是多边形数不一定会按照边数来排列
dax 2024-09-02 08:47:35
*/
#include "problem.h"

// 生成4位数的所有目标多边形数
Solution::Solution()
{
	bool notstop = true;
	unsigned n = 1;

	while(notstop)
	{
		if(!polygonals.empty())
			notstop = false;

		std::vector<unsigned> temp =
		{
			n * (n + 1) / 2,
			n * n,
			n * (3 * n - 1) / 2,
			n * (2 * n - 1),
			n * (5 * n - 3) / 2,
			n * (3 * n - 2)
		};

		for(unsigned i = 0; i < temp.size(); ++i)
		{
			if(temp[i] > 999 && temp[i] < 10000)
			{
				polygonals.push_back(Polygonal{i + 3, temp[i], n});
				notstop = true;
			}
		}

		++n;
	}

}

bool Solution::is_cyclic(unsigned a, unsigned b)
{
	return a % 100 == b / 100;
}

void Solution::answer()
{
	// 将每个多边形数做为一个单独的循环数集合的开始
	std::vector<std::vector<Polygonal>> cyclic_sets;

	for(auto & p : polygonals)
	{
		cyclic_sets.push_back({p});
	}

	unsigned index = 1;

	while(index < 6)
	{
		std::vector<std::vector<Polygonal>> temp_sets;

		// 遍历所有的循环数集合与所有的多边形数，如果找到与集合尾部形成循环数的就添加到一个临时的集合中
		for(auto& set : cyclic_sets)
			for(auto &p : polygonals)
			{
				if(is_cyclic(set.back().number, p.number))
				{
					bool nobreak = true;

					for(auto& ps : set)
					{
						if(ps.sides == p.sides)
						{
							nobreak = false;
							break;
						}
					}

					if(nobreak)
					{
						auto copy(set);
						copy.push_back(p);
						temp_sets.push_back(copy);
					}
				}
			}

		// 完成一轮循环后将临时集合赋值给循环数集合，并进行下一轮循环
		cyclic_sets = temp_sets;
		++index;
	}

	for(auto&set : cyclic_sets)
	{
		unsigned sum{};

		if(is_cyclic(set.back().number, set.front().number))
			for(auto &p : set)
			{
				std::cout << p.sides << '\t' << p.number << '\t' << p.n << std::endl;
				sum += p.number;
			}

		if(sum)
			std::cout << "The answer is: " << sum << std::endl;
	}

}
