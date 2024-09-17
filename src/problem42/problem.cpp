/*
Problem page link:
https://projecteuler.net/problem=42

dax 2024-09-17 23:28:30
*/
#include "problem.h"
#include <filesystem>
#include <fstream>

void Solution::read_names()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0042_words.txt");

	std::ifstream file(p);
	std::string name;

	while(std::getline(file, name, ','))
	{
		max_length = max_length > name.size() - 2 ? max_length : name.size() - 2;
		names.push_back(name.substr(1, name.size() - 2));
	}
}

void Solution::gen_triangles()
{
	auto limit = max_length * 26;
	unsigned n = 1;
	unsigned triangle = 1;

	while(triangle < limit)
	{
		++n;
		triangle = n * (n + 1) / 2;
		triangles.insert(triangle);

	}
}

unsigned Solution::name_score(std::string& name)
{
	unsigned score{};

	for(auto&c : name)
	{
		score += c - 64;
	}

	return score;
}

void Solution::answer()
{
	read_names();
	gen_triangles();

	unsigned count{};
	for(auto& name: names)
	{
		if(triangles.contains(name_score(name)))
			++count;
	}
	std::cout << "The answer is: " << count << std::endl;
}
