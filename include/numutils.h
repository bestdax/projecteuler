#pragma once
#include <unordered_set>
#include <string>
#include <cmath>

namespace dax
{
bool is_palindrome(unsigned long, unsigned base = 10);
unsigned long gcd(unsigned long, unsigned long);
unsigned long lcm(unsigned long, unsigned long);
bool is_pandigital(unsigned, bool include_zero = false);
unsigned long factorial(unsigned);
bool is_pentagonal(unsigned long);
bool is_triangle(unsigned long);
bool is_hexagonal(unsigned long);
bool is_square(unsigned long);
unsigned long concatenate(unsigned long, unsigned long);
}
