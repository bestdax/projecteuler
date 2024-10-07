#pragma once
#include <utils.h>

struct Triangle
{
	unsigned a, b, c;

	bool operator==(const Triangle& other) const
	{
		return a == other.a && b == other.b && c == other.c;
	}

	std::strong_ordering operator<=>(const Triangle& other) const = default;

	unsigned perimeter()
	{
		return a + b + c;
	}
};

class Solution
{
	public:
		void answer();

};
