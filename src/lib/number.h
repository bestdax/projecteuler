#pragma once
#include <vector>
#include <algorithm>

bool is_prime(unsigned long number);
std::vector<unsigned> prime_factors(unsigned long number);
std::vector<unsigned> get_digits(unsigned long number);
std::vector<unsigned> get_unique_digits(unsigned long number);
unsigned long digits_to_number(std::vector<unsigned> digits);
bool has_digit(unsigned long number, unsigned digit);
bool has_same_digit(unsigned long number1, unsigned long number2);
bool has_same_digit(unsigned long number);
std::vector<unsigned long> cancel_same_digit(unsigned long number1, unsigned long number2);
unsigned size(unsigned long number);
unsigned long rotate(unsigned long number);
bool is_palindrome(unsigned long number);
unsigned long concatenate(unsigned long number1, unsigned long number2);
unsigned long concatenate(std::vector<unsigned long> numbers);
bool is_n_pandigital(unsigned number);
bool is_triangle_number(unsigned long number);
bool is_pentagonal_number(unsigned long number);
bool is_hexagonal_number(unsigned long number);
bool is_odd(unsigned long number);
bool is_even(unsigned long number);
bool is_square(unsigned long number);
