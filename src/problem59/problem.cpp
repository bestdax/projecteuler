/*
Problem page link:
https://projecteuler.net/problem=59

dax 2024-08-26 14:53:06
*/
#include "problem.h"

void Solution::read_file()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0059_cipher.txt");
	auto file = std::ifstream(p);

	if(!file.is_open()) std::cout << "Open file failed" << std::endl;

	std::string  c;

	while(std::getline(file, c, ','))
	{
		ciphered.push_back(char(std::stoi(c)));
	}

}

std::map<char, double> calculateFrequency(const std::string& text)
{
	std::map<char, double> frequency;

	for(char c : text)
	{
		if(isalpha(c))
		{
			frequency[tolower(c)]++;
		}
	}

	// 将频率转换为百分比
	for(auto& pair : frequency)
	{
		pair.second = (pair.second / text.length()) * 100;
	}

	return frequency;
}

double frequencyDifference(const std::map<char, double>& freq1, const std::map<char, double>& freq2)
{
	double diff = 0.0;

	for(auto& pair : freq1)
	{
		diff += std::abs(pair.second - freq2.at(pair.first));
	}

	return diff;
}

bool Solution::is_english(std::string& text)
{
	std::map<char, double> englishFrequency =
	{
		{'e', 12.70}, {'t', 9.06}, {'a', 8.17}, {'o', 7.51}, {'i', 6.97},
		{'n', 6.75}, {'s', 6.33}, {'h', 6.09}, {'r', 5.99}, {'d', 4.25},
		{'l', 4.03}, {'c', 2.78}, {'u', 2.76}, {'m', 2.41}, {'w', 2.36},
		{'f', 2.23}, {'g', 2.02}, {'y', 1.97}, {'p', 1.93}, {'b', 1.29},
		{'v', 0.98}, {'k', 0.77}, {'j', 0.15}, {'x', 0.15}, {'q', 0.10},
		{'z', 0.07}
	};
	auto textFrequency = calculateFrequency(text);
	double diff = frequencyDifference(textFrequency, englishFrequency);
	return diff < 30.0; // 经验阈值
}

void Solution::decipher()
{
	read_file();

	std::ofstream file("/Users/dax/Downloads/output.txt");

	for(char a = 'a'; a <= 'z'; ++a)
		for(char b = 'a'; b <= 'z'; ++b)
			for(char c = 'a'; c <= 'z'; ++c)
			{
				auto copy = ciphered;
				auto pass = std::string("") + a + b + c;

				auto size = ciphered.size();

				for(unsigned n = 0; n <  size; ++n)
				{
					copy[n] ^= pass[n % 3];
				}

				// if(is_english(copy))
				if(copy.find(" the ") != std::string::npos)
				{
					std::cout << "possible key: " << pass << std::endl;
					std::cout << "decrypted text: " << copy << std::endl;
					std::cout << "ascii sum: " << std::accumulate(copy.begin(), copy.end(), 0) << std::endl;
				}

			}
}

void Solution::answer()
{
	decipher();
	std::cout << "The answer is: " << "" << std::endl;
}
