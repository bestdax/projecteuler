/*
Problem page link:
https://projecteuler.net/problem=17

dax 2024-09-10 14:14:47
*/
#include "problem.h"
#include <vector>
#include <iomanip>

std::string to_19[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                       "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                       "eighteen", "nineteen"
                      };

std::string divisor_names[] = {"", "thousand", "million", "billion", "trillion"};

std::string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

std::string Solution::say_number(long n)
{

	if(n < 0) return "minus " + say_number(-n);

	if(n < 20) return to_19[n];

	if(n < 100) return tens[n / 10] + (n % 10 ? "-" + to_19[n % 10] : "");

	if(n < 1000) return to_19[n / 100] + " hundred" + (n % 100 == 0 ? "" : " and " + say_number(n % 100));

	std::string result;
	std::vector<int> parts;

	while(n)
	{
		parts.push_back(n % 1000);
		n /= 1000;
	}

	for(int i = 0; i < parts.size(); ++i)
	{
		// 如果分段为0则直接跳过
		if(parts[i] == 0) continue;

		// 如果分段不为零则调用say_number，然后接分段的名称，如果分段有名称就加个空格，最后接上后面的内容；
		result =  say_number(parts[i]) + (divisor_names[i].empty() ? "" : " " + divisor_names[i])    +
		          (result.empty() ? "" : " " + result);
	}

	return result;

}

uint Solution::count_char(std::string s)
{
	uint count{};

	for(auto&d : s)
	{
		if(d >= 'a' && d <= 'z') ++count;
	}

	return count;
}

void Solution::answer()
{
	uint count{};

	for(int i = 1; i <= 1000; ++i)
		count += count_char(say_number(i));

	std::cout << "The answer is: " << count << std::endl;
}
