#include "number.h"
#include <iostream>
#include <ostream>
#include <cmath>
#include <algorithm>

bool is_prime(unsigned long number)
{
	if(number < 2) return false;

	if(number % 2 == 0 || number % 5 == 0) return false;

	int root = std::round(std::sqrt(number));

	for(int i = 2; i <= root; i++)
	{
		if(number % i == 0) return false;
	}

	return true;
}

unsigned long next_prime_larger_than(unsigned long number)
{
	do
	{
		++number;

		if(is_prime(number)) return number;
	}
	while(true);
}

std::vector<unsigned> prime_factors(unsigned long number)
{
	std::vector<unsigned> pf{};

	if(number < 2) return pf;

	for(int i = 2; i <= number; ++i)
	{
		if(is_prime(i) && number % i == 0)
		{
			pf.push_back(i);
			number /= i;
			i = 1;
		}
	}

	return pf;
}


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

std::vector<unsigned> get_unique_digits(unsigned long number)
{
	auto digits = get_digits(number);
	std::sort(digits.begin(), digits.end());
	auto last = std::unique(digits.begin(), digits.end());
	digits.erase(last, digits.end());
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

// partial same
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

bool has_same_digit(unsigned long number)
{
	auto digits = get_digits(number);
	std::sort(digits.begin(), digits.end());

	for(auto it = digits.begin(); it < digits.end() - 1; ++it)
	{
		if(*it == *(it + 1)) return true;
	}

	return false;
}

bool has_exact_same_digits(unsigned long number1, unsigned long number2)
{
	auto digits1 = get_digits(number1);
	auto digits2 = get_digits(number2);

	if(digits1.size() != digits2.size()) return false;

	std::sort(digits1.begin(), digits1.end());
	std::sort(digits2.begin(), digits2.end());
	auto size = digits1.size();

	for(unsigned i = 0; i < size; ++i)
	{
		if(digits1[i] != digits2[i]) return false;
	}

	return true;
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

unsigned long concatenate(unsigned long number1, unsigned long number2)
{
	auto len = size(number2);
	return number1 * std::pow(10, len) + number2;
}
unsigned long concatenate(std::vector<unsigned long> numbers)
{
	unsigned long number{};

	for(auto n : numbers)
		number = concatenate(number, n);

	return number;
}

bool is_n_pandigital(unsigned number)
{
	if(has_digit(number, 0)) return false;

	if(has_same_digit(number)) return false;

	auto len = size(number);

	for(unsigned i = len + 1; i < 10; ++ i)
		if(has_digit(number, i)) return false;

	return true;
}

bool is_triangle_number(unsigned long number)
{
	auto n = (std::round(std::sqrt(number * 8 + 1)) - 1) / 2;
	return n * (n + 1) == number * 2;
}

bool is_pentagonal_number(unsigned long number)
{
	unsigned n = (std::sqrt(24 * number + 1) + 1) / 6;
	return number == n * (3 * n - 1) / 2;
}

bool is_hexagonal_number(unsigned long number)
{
	unsigned n = (std::sqrt(8 * number + 1) + 1) / 4;
	return number == (2 * n * n - n);
}

bool is_heptagonal_number(unsigned long number)
{
	unsigned n = (std::sqrt(40 * number + 9) + 3) / 10;
	return n * (5 * n - 3) / 2 == number;
}

bool is_octagonal_number(unsigned long number)
{
	unsigned n = (std::sqrt(number * 3 + 1) + 1) / 3;
	return n * (3 * n - 2) == number;
}

bool is_odd(unsigned long number)
{
	return number % 2 != 0;
}

bool is_even(unsigned long number)
{
	return number % 2 == 0;
}

bool is_square(unsigned long number)
{
	unsigned long sqrt = std::round(std::sqrt(number));
	return number == sqrt * sqrt;
}

bool is_cube(unsigned long number)
{
	unsigned long cube_root = std::cbrt(number);
	return std::pow(cube_root, 3) == number;
}

unsigned long factorial(unsigned n)
{
	unsigned long f{1};

	for(unsigned i = 1; i <= n; ++i)
	{
		f *= i;
	}

	return f;
}

unsigned long combination(unsigned n, unsigned r)
{
	unsigned long c = 1;
	unsigned l = 1;

	for(unsigned u = n; u > r; --u)
	{
		c *= u;

		while(c % l == 0 && l <= n - r)
		{
			c /= l;
			++l;
		}
	}

	return c;
}

unsigned long permutation(unsigned n, unsigned r)
{
	// return factorial(n) / factorial(n - r);
	unsigned long p = 1;

	for(unsigned u = n; u > n - r; --u)
		p *= u;

	return p;
}
