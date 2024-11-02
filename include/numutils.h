#pragma once
#include <utils.h>
#include <unordered_set>
#include <string>
#include <cmath>

namespace dax
{
	bool is_palindrome(ulong, uint base = 10);
	ulong gcd(ulong, ulong);
	ulong lcm(ulong, ulong);
	bool is_pandigital(uint, bool include_zero = false);
	ulong factorial(uint);
	bool is_pentagonal(ulong);
	bool is_triangle(ulong);
	bool is_hexagonal(ulong);
	bool is_square(ulong);
	bool is_permutation(ulong, ulong);
	ulong concatenate(ulong, ulong);
}
