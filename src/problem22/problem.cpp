/*
Problem page link:
https://projecteuler.net/problem=22

dax 2024-08-05 10:44:18
*/
#include "problem.h"

void Solution::read_file(std::string filename)
{
	std::filesystem::path p = __FILE__;
	p.replace_filename(filename);

	auto fs = std::ifstream(p);

	if(!fs) std::cout << "Open file failed" << std::endl;

	std::string name;

	while(std::getline(fs, name, ','))
	{
		names.push_back(name.substr(1, name.length() - 2));
	}
}

unsigned long Solution::namescore()
{
	std::sort(names.begin(), names.end());
	unsigned nth = 0;
	unsigned long scoresum{};
	unsigned long score{};

	for(auto name : names)
	{
		score = 0;

		for(auto c : name)
		{
			score += (c - 64);
		}

		scoresum += ++nth * score;
	}

	return scoresum;
}

void Solution::answer()
{
	read_file("p022_names.txt");
	std::cout << "The answer is: " << namescore() << std::endl;
}
