#pragma once
#include <iostream>
#include <vector>

class Solution
{
public:
	unsigned long replace(unsigned long number, unsigned index, unsigned digit);
	unsigned long replace_with_position_list(unsigned long number, std::vector<unsigned> position_list, unsigned digit);
	std::vector<unsigned long> replace_with_same_digits(unsigned long prime_number);
	void answer();

};
