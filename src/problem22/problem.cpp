/*
Problem description:
Names scores
Problem 22
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value
by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the
938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
page link:
https://projecteuler.net/problem=22

dax 2023-04-28 11:47:43
*/
#include "problem.h"

Solution::Solution()
{
	get_names();
	sort();
}

std::string Solution::get_absolute_resource_path(std::string filename)
{
	std::filesystem::path p = __FILE__;
	p.replace_filename(filename);
	return p;
}

std::string Solution::get_text_from_file(std::string filename)
{
	auto p = get_absolute_resource_path(filename);
	std::ifstream file(p);
	std::string string;

	if(file.is_open())
	{
		std::string line;

		while(std::getline(file, line))
		{
			string += line;
		}
	}

	return string;
}

void Solution::get_names()
{
	auto string = get_text_from_file("p022_names.txt");
	std::string::size_type s = 0;
	auto end = std::string::npos;

	while(true)
	{
		s = string.find_first_of('"', s);

		if(s == end) break;
		else
		{
			auto e = string.find_first_of('"', s + 1);

			if(e == end) break;
			else
			{
				auto name = string.substr(s + 1, e - s - 1);
				names.push_back(name);
				s = e + 1;
			}
		}
	}
}

void Solution::sort()
{
	std::sort(names.begin(), names.end());
}

unsigned Solution::get_rank(std::string name)
{
	auto pos =  std::find(names.begin(), names.end(), name);

	if(pos != names.end())
		return pos - names.begin() + 1;
	else
		return 0;
}

unsigned Solution::get_char_sum(std::string name)
{
	unsigned sum{};

	for(auto c : name)
	{
		sum += c - 64;
	}

	return sum;
}

unsigned Solution::get_name_score(std::string name)
{
	unsigned rank = get_rank(name);
	unsigned sum = get_char_sum(name);
	return rank * sum;
}

unsigned long Solution::sum_of_name_score()
{
	unsigned long sum{};

	for(auto name : names)
		sum += get_name_score(name);

	return sum;
}



void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_name_score() << std::endl;
}
