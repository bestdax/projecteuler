#pragma once
#include <cmath>
#include <utils.h>
#include <vector>
#include <utility>
#include <unordered_set>

struct Remainder
{
	int numerator;
	int denominator;

	bool operator==(const Remainder& other) const
	{
		return numerator == other.numerator && denominator == other.denominator;
	}
};

namespace std
{
	template <>
	struct hash<std::pair<int, int>>
	{
		std::size_t operator()(const std::pair<int, int> &p) const
		{
			std::size_t p1 = std::hash<int>()(p.first);
			std::size_t p2 = std::hash<int>()(p.second);

			return p1 ^ (p2 << 1);
		}
	};
}

// square root continued fraction class
class SqrtCF
{
	private:
		std::vector<int> coefficients;
		std::unordered_set<std::pair<int, int>> remainders;
	public:
		SqrtCF(int);
		int period();
};

class Solution
{
	public:
		void answer();

};
