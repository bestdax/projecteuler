/*
Problem page link:
https://projecteuler.net/problem=32

dax 2024-08-10 16:52:32
*/
#include "problem.h"
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

bool Solution::is_pandigital(unsigned n)
{
	std::string all_digits = "123456789";
	auto string_number = std::to_string(n);

	if(string_number.size() > 9) return false;

	std::sort(string_number.begin(), string_number.end());
	return string_number == all_digits.substr(0, string_number.size());
}

void Solution::answer()
{
	std::vector<unsigned> products{};
	std::string all_digits = "123456789";

	while(std::next_permutation(all_digits.begin(), all_digits.end()))
	{
		unsigned multiplicand = std::stoul(all_digits.substr(0, 1));
		unsigned multiplier = std::stoul(all_digits.substr(1, 4));
		unsigned product = std::stoul(all_digits.substr(5, 4));

		if(multiplicand * multiplier == product)
		{
			auto it = std::find(products.begin(), products.end(), product);

			if(it == products.end()) products.push_back(product);
		}
		multiplicand = std::stoul(all_digits.substr(0, 2));
		multiplier = std::stoul(all_digits.substr(2, 3));
		product = std::stoul(all_digits.substr(5, 4));

		if(multiplicand * multiplier == product)
		{
			auto it = std::find(products.begin(), products.end(), product);

			if(it == products.end()) products.push_back(product);
		}
	}


	std::cout << "The answer is: " << std::accumulate(products.begin(), products.end(), 0) << std::endl;
}
