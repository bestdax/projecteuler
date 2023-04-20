/*
Problem description:
Problem 42
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so
the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its
alphabetical position and adding these values we form a word value. For example,
the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a
triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file
containing nearly two-thousand common English words, how many are triangle
words?

page link:
https://projecteuler.net/problem=42

dax 2023-05-23 12:57:09
*/
#include "problem.h"
#include <fstream>
#include <filesystem>
#include "number.h"

Solution::Solution()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("p042_words.txt");
	std::fstream file(p);
	std::string word;

	if(file.is_open())
	{
		while(std::getline(file, word, ','))
			words.push_back(word.substr(1, word.length() - 2));
	}
}

unsigned Solution::compute_word_value(std::string word)
{
	unsigned value{};

	for(auto c : word)
	{
		value += c - 64;
	}

	return value;
}

unsigned Solution::how_many_triangle_words()
{
	unsigned count{};

	for(auto word : words)
	{
		auto value = compute_word_value(word);

		if(dax::is_triangle_number(value)) ++count;
	}

	return count;
}

void Solution::answer()
{
	std::cout << "The answer is: " << how_many_triangle_words() << std::endl;
}
