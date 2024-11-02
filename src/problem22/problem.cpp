/*
Problem page link:
https://projecteuler.net/problem=22

dax 2024-09-11 12:19:51
*/
#include "problem.h"
#include <filesystem>
#include <fstream>
#include <algorithm>

Solution::Solution()
{
	names.reserve(6000);
	std::filesystem::path p = __FILE__;
	p.replace_filename("0022_names.txt");

	std::ifstream file(p);
	std::string name;

	while(std::getline(file, name, ','))
	{
		names.push_back(name.substr(1, name.size() - 2));
	}

	std::sort(names.begin(), names.end());

}

uint Solution::name_score(std::string& name)
{
	uint score{};

	for(auto& c : name)
		score += c - 64;

	return score;
}

void Solution::answer()
{
	ulong sum{};

	for(uint i = 0; i < names.size(); ++i)
	{
		sum += (i + 1) * name_score(names[i]);
	}

	std::cout << "The answer is: " << sum << std::endl;
}
