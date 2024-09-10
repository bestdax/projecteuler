/*
Problem page link:
https://projecteuler.net/problem=17

dax 2024-09-10 14:14:47
*/
#include "problem.h"
#include <vector>

std::string Solution::say_number(unsigned n)
{
	std::vector<std::string> to_19 =
	{
		"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
		"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
		"eighteen", "nineteen"

	};
	std::vector<std::string> tens =
	{
		"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
	};

	std::string say;

	unsigned s = n / 1000;
	n %= 1000;

	if(s) say += to_19[s - 1] + " thousand";

	unsigned h = n / 100;
	n %= 100;

	if(h) say = say + (say.empty() ? "" : " ") + to_19[h - 1] + " hundred";

	if(n && !say.empty()) say += " and ";

	if(n)
	{
		if(n < 20) say += to_19[n - 1];
		else
		{
			unsigned t = n / 10;
			n %= 10;
			say += tens[t - 2];

			if(n) say = say + '-' + to_19[n - 1];
		}
	}

	return say;
}

unsigned Solution::count_char(std::string s)
{
	unsigned count{};

	for(auto&d : s)
	{
		if(d >= 'a' && d <= 'z') ++count;
	}

	return count;
}

void Solution::answer()
{
	unsigned count{};

	for(int i = 1; i <= 1000; ++i)
		count += count_char(say_number(i));

	std::cout << "The answer is: " << count << std::endl;
}
