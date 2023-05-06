#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution
{
public:
	std::vector<unsigned> get_digits(unsigned number);
	unsigned number_of_digits(std::vector<unsigned> numbers);
	bool has_same_digit(std::vector<unsigned> numbers);
	bool has_zero(unsigned number);
	unsigned find_pandigital_products();
	void answer();

};
