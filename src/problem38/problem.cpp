/*
Problem page link:
https://projecteuler.net/problem=38

dax 2024-08-11 08:11:04
*/
#include "problem.h"
#include <string>
#include <algorithm>

bool Solution::is_multiple_pandigit(unsigned n)
{
	std::string pandigits = "123456789";
	std::string nstring{};
	std::string nsstore{};
	unsigned m{0};

	while(true)
	{
		nstring += std::to_string(n * ++m);
		nsstore += std::to_string(n * m);
		std::sort(nstring.begin(), nstring.end());

		if(nstring == pandigits)
		{
			auto temp = std::stoul(nsstore);
			max_pan = max_pan > temp ? max_pan : temp;
			return true;
		}

		if(nstring.size() > pandigits.size()) return false;
	}

}

void Solution::answer()
{
	for(unsigned i = 1; i < 1e4; ++i)
		is_multiple_pandigit(i);

	std::cout << "The answer is: " << max_pan << std::endl;
}
