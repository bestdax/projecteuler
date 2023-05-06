/*
Problem description:
Pandigital products
Problem 32
We shall say that an n-digit number is pandigital if it makes use of all the
digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through
5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can
be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only
include it once in your sum.

page link:
https://projecteuler.net/problem=32

dax 2023-05-06 12:56:12
*/
#include "problem.h"

std::vector<unsigned> Solution::get_digits(unsigned number)
{
	std::vector<unsigned> digits{};

	while(number != 0)
	{
		digits.insert(digits.begin(), number % 10);
		number /= 10;
	}

	return digits;
}

bool Solution::has_zero(unsigned number)
{
	auto digits = get_digits(number);
	auto it = std::find(digits.begin(), digits.end(), 0);
	return it != digits.end();
}

unsigned Solution::number_of_digits(std::vector<unsigned> numbers)
{
	unsigned nod{};

	for(auto number : numbers)
		nod += get_digits(number).size();

	return nod;
}

bool Solution::has_same_digit(std::vector<unsigned> numbers)
{
	std::vector<unsigned> digits{};

	for(auto number : numbers)
	{
		auto d = get_digits(number);
		digits.insert(digits.end(), d.begin(), d.end());
	}

	std::sort(digits.begin(), digits.end());
	auto it = std::unique(digits.begin(), digits.end());

	if(it != digits.end()) return true;
	else return false;
}
unsigned Solution::find_pandigital_products()
{
	std::vector<unsigned> products;

	for(unsigned i = 2; i < 5000; ++i)
		for(unsigned j = 2; j < 5000; ++j)
		{
			unsigned product = i * j;

			if(product > 10000) continue;

			if(has_zero(i) || has_zero(j) || has_zero(product)) continue;

			if(number_of_digits({i, j, product}) != 9) continue;

			if(has_same_digit({i, j, product})) continue;
			auto it = std::find(products.begin(), products.end(), product);

			if(it == products.end()) products.push_back(product);
		}

	return std::accumulate(products.begin(), products.end(), 0);
}

void Solution::answer()
{
	std::cout << "The answer is: " << find_pandigital_products() << std::endl;
}
