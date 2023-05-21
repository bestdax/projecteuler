#include "number.h"
#include <iostream>
#include <ostream>
#include <cmath>


std::vector<unsigned> get_digits(unsigned long number)
{
	std::vector<unsigned> digits{};

	while(number)
	{
		digits.push_back(number % 10);
		number /= 10;
	}

	std::reverse(digits.begin(), digits.end());
	return digits;
}

unsigned long digits_to_number(std::vector<unsigned> digits)
{
	unsigned long number{};

	for(auto d : digits)
		number = (number * 10 + d);

	return number;
}

bool has_digit(unsigned long number, unsigned digit)
{
	auto digits = get_digits(number);
	return std::find(digits.begin(), digits.end(), digit) != digits.end();
}

bool has_same_digit(unsigned long number1, unsigned long number2)
{
	auto digits1 = get_digits(number1);
	auto digits2 = get_digits(number2);

	for(auto d : digits1)
	{
		auto it = std::find(digits2.begin(), digits2.end(), d);

		if(it != digits2.end()) return true;
	}

	return false;
}

std::vector<unsigned long> cancel_same_digit(unsigned long number1, unsigned long number2)
{
	std::vector<unsigned long>numbers{number1, number2};

	if(has_same_digit(numbers[0], numbers[1]))
	{
		auto digits1 = get_digits(numbers[0]);
		auto digits2 = get_digits(numbers[1]);

		for(auto it1 = digits1.rbegin(); it1 != digits1.rend(); ++it1)
			for(auto it2 = digits2.rbegin(); it2 != digits2.rend(); ++it2)
			{
				if(*it1 == *it2)
				{
					std::erase(digits1, *it1);
					std::erase(digits2, *it2);
				}
			}

		numbers[0] = digits_to_number(digits1);
		numbers[1] = digits_to_number(digits2);
	}

	return numbers;
}

unsigned size(unsigned long number)
{
	unsigned s{0};

	while(number != 0)
	{
		++s;
		number /= 10;
	}

	return s;
}

unsigned long rotate(unsigned long number)
{
	auto d = number % 10;
	number /= 10;
	number += std::pow(10, size(number)) * d;
	return number;
}

bool is_palindrome(unsigned long number)
{
	auto number_string = std::to_string(number);
	int middle = number_string.size() / 2;

	for(int i = 0; i < middle; ++i)
	{
		if(*(number_string.begin() + i) != *(number_string.end() - 1 - i)) return false;
	}

	return true;
}
