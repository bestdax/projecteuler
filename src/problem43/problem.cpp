/*
Problem page link:
https://projecteuler.net/problem=43

dax 2024-08-12 14:24:00
*/
#include "problem.h"
#include <string>
#include <algorithm>

void Solution::answer()
{
	std::string pan_digits = "0987654321";
	unsigned long sum{};

	while(std::next_permutation(pan_digits.begin(), pan_digits.end()))
	{
		if(std::stoi(pan_digits.substr(1, 3)) % 2 != 0) continue;

		if(std::stoi(pan_digits.substr(2, 3)) % 3 != 0) continue;

		if(std::stoi(pan_digits.substr(3, 3)) % 5 != 0) continue;

		if(std::stoi(pan_digits.substr(4, 3)) % 7 != 0) continue;

		if(std::stoi(pan_digits.substr(5, 3)) % 11 != 0) continue;

		if(std::stoi(pan_digits.substr(6, 3)) % 13 != 0) continue;

		if(std::stoi(pan_digits.substr(7, 3)) % 17 != 0) continue;

		sum += std::stoul(pan_digits);
	}

	std::cout << "The answer is: " << sum << std::endl;
}
