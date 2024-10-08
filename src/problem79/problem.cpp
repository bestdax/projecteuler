/*
Problem page link:
https://projecteuler.net/problem=79

dax 2024-10-08 19:35:30
*/
#include "problem.h"
#include <filesystem>
#include <fstream>
#include <stack>
#include <string>

// 读取文本中的密码并建图
void Solution::read_pass()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0079_keylog.txt");
	std::ifstream file(p);

	std::string line;

	while(std::getline(file, line))
	{
		graph[line[0]].insert(line[1]);
		graph[line[1]].insert(line[2]);
	}

}

void Solution::answer()
{
	read_pass();

	// DFS算法搜索
	std::stack<std::string> stack;

	for(auto& node : graph)
	{
		stack.push(std::to_string(node.first - '0'));

		while(!stack.empty())
		{
			auto pass = stack.top();
			stack.pop();

			for(auto& next : graph[pass.back()])
			{
				stack.push(pass + next);
			}

			// 保证密码是所有数字的一个排列
			if(pass.size() == graph.size())
				print("The answer is:", pass);
		}
	}

}
