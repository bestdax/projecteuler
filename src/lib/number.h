#pragma once
#include <vector>
#include <algorithm>

std::vector<unsigned> get_digits(unsigned long number);
bool has_zero(unsigned long number);
bool has_same_digit(unsigned long number1, unsigned long number2);
std::vector<unsigned long> cancel_same_digit(unsigned long number1, unsigned long number2);
