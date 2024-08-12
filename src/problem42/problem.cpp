/*
Problem page link:
https://projecteuler.net/problem=42

dax 2024-08-12 13:21:44
*/
#include "problem.h"
#include "number.h"

Solution::Solution()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("p042_words.txt");

	std::ifstream file(p);

	if(!file.is_open()) std::cout << "Open file failed" << std::endl;

	std::string name;

	while(std::getline(file, name, ','))
	{
		names.push_back(name.substr(1, name.size() - 2));
	}

}

unsigned long Solution::calculate_name_score(std::string name)
{
	unsigned long score{};

	for(auto c : name)
	{
		score += c - 64;
	}

	return score;
}

void Solution::answer()
{
	unsigned count{};

	for(auto name : names)
	{
		if(dax::is_triangle(calculate_name_score(name)))
			++count;
	}

	std::cout << "The answer is: " <<names.size() << '\t' << count << std::endl;
}
