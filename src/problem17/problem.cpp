/*
Problem description:
Number letter counts
Problem 17
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19
letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115
(one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
page link:
https://projecteuler.net/problem=17

dax 2023-04-27 14:47:37
*/
#include "problem.h"

Solution::Solution()
{
	dict[0] = "zero";
	dict[1] = "one";
	dict[2] = "two";
	dict[3] = "three";
	dict[4] = "four";
	dict[5] = "five";
	dict[6] = "six";
	dict[7] = "seven";
	dict[8] = "eight";
	dict[9] = "nine";
	dict[10] = "ten";
	dict[11] = "eleven";
	dict[12] = "twelve";
	dict[13] = "thirteen";
	dict[14] = "fourteen";
	dict[15] = "fifteen";
	dict[16] = "sixteen";
	dict[17] = "seventeen";
	dict[18] = "eighteen";
	dict[19] = "nineteen";
	dict[20] = "twenty";
	dict[30] = "thirty";
	dict[40] = "forty";
	dict[50] = "fifty";
	dict[60] = "sixty";
	dict[70] = "seventy";
	dict[80] = "eighty";
	dict[90] = "ninety";
	dict[100] = "one hundred";
	dict[200] = "two hundred";
	dict[300] = "three hundred";
	dict[400] = "four hundred";
	dict[500] = "five hundred";
	dict[600] = "six hundred";
	dict[700] = "seven hundred";
	dict[800] = "eight hundred";
	dict[900] = "nine hundred";
	dict[1000] = "one thousand";
}

std::string Solution::say_number(unsigned number)
{
	std::string say{};
	int thousands = number / 1000 * 1000;
	int hundreds = number % 1000 / 100 * 100;
	int tens = number % 100 / 10 * 10;
	int ones = number % 100 % 10;
	int teens = 0;

	if(tens == 10) teens = tens + ones;

	if(thousands) say += dict[thousands];

	if(hundreds) say += (thousands ? ' ' + dict[hundreds] : dict[hundreds]);

	if(!say.empty() && (tens || ones)) say += " and ";

	if(teens) say += dict[teens];
	else
	{
		if(tens && ones) say += dict[tens] + "-" + dict[ones];
		else
		{
			if(tens) say += dict[tens];

			if(ones) say += dict[ones];
		}
	}

	return say;
}

unsigned Solution::count(unsigned number)
{
	unsigned cnt = 0;
	auto speaking_number = say_number(number);

	for(auto c : speaking_number)
	{
		if(c != ' ' && c != '-') ++cnt;
	}

	return cnt;
}

unsigned Solution::count_range(unsigned range)
{
	unsigned cnt{};

	for(unsigned i = 1; i <= range; ++i)
		cnt += this->count(i);

	return cnt;
}

void Solution::say_range(unsigned range)
{
	for(unsigned i = 1; i <=range; ++i)
	std::cout << std::quoted(say_number(i)) << '\t' << count_range(i) << std::endl;
}


void Solution::answer()
{
	std::cout << "The answer is: " << count_range(1000) << std::endl;
}
