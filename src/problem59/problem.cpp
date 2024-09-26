/*
Problem page link:
https://projecteuler.net/problem=59

dax 2024-09-26 11:05:38
*/
#include "problem.h"
#include <fstream>
#include <filesystem>
#include <ios>

void Solution::read_text()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0059_cipher.txt");
	std::ifstream file(p);

	std::string ns;

	while(std::getline(file, ns, ','))
	{
		ciphered += std::stoul(ns);
	}

}

std::string Solution::decript(std::string pass)
{
	std::string text;

	for(unsigned i = 0; i < ciphered.size(); ++i)
	{
		text += ciphered[i] ^ pass[i % pass.size()];
	}

	return text;
}

bool Solution::next_pass()
{
	if(pass == "zzz") return false;

	unsigned index = 0;

	while(index < pass.size())
	{
		if(++pass[index] > 'z')
		{
			pass[index] = 'a';
			++index;
		}
		else break;
	}

	return true;
}

bool Solution::find_the_in_text(std::string text)
{
	auto pos = text.find(" the ");

	if(pos != std::string::npos) return true;

	return false;
}

unsigned long Solution::ascii_sum(std::string text)
{
	unsigned long sum{};

	for(const auto& c : text)
	{
		sum += c;
	}

	return sum;
}

void Solution::answer()
{
	read_text();

	do
	{
		auto text = decript(pass);

		if(find_the_in_text(text))
			std::cout << "The answer is: " << ascii_sum(text) << std::endl;
	}
	while(next_pass());
}
