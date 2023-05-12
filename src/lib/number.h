#pragma once
#include <vector>
#include <algorithm>

std::vector<unsigned> get_digits(unsigned long number);
unsigned long digits_to_number(std::vector<unsigned> digits);
bool has_digit(unsigned long number, unsigned digit);
bool has_same_digit(unsigned long number1, unsigned long number2);
std::vector<unsigned long> cancel_same_digit(unsigned long number1, unsigned long number2);
