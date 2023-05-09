#include "number.h"


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

bool has_zero(unsigned long number)
{
	auto digits = get_digits(number);
	return std::find(digits.begin(), digits.end(), 0) != digits.end();

}

bool has_same_digit(unsigned long number1, unsigned long number2)
{
	auto digits1 = get_digits(number1);
	auto digits2 = get_digits(number2);
	for(auto d: digits1)
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
		for(auto d1: digits1)
		for(auto d2: digits2)
		{
			
		}
		
	}
}
