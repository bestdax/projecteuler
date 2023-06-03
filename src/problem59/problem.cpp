/*
Problem description:

page link:
https://projecteuler.net/problem=

dax 2023-06-03 17:55:19
*/
#include "problem.h"
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>

void Solution::answer()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0059_cipher.txt");
	std::fstream file(p);
	std::vector<char> encipered;

	if(file.is_open())
	{
		std::string char_string;

		while(std::getline(file, char_string, ','))
		{
			// encipered.push_back(static_cast<char>(char_string));
			encipered.push_back(static_cast<char>(std::stoi(char_string)));
		}
	}

	unsigned long ascii_sum{};

	for(unsigned i = 0; i < encipered.size(); ++i)
	{
		if(i % 3 == 0)  ascii_sum += (encipered[i] ^ 'e');

		if(i % 3 == 1)  ascii_sum += (encipered[i] ^ 'x');

		if(i % 3 == 2) ascii_sum += (encipered[i] ^ 'p');
	}

	std::cout << "The answer is: " << ascii_sum << std::endl;
}
