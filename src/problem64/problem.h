#pragma once
#include <cmath>
#include <utils.h>
#include <vector>
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
	struct hash<Remainder>
	{
		std::size_t operator()(const Remainder& r) const
		{
			std::size_t r1 = std::hash<int>()(r.numerator);
			std::size_t r2 = std::hash<int>()(r.denominator);

			return r1 ^ (r2 << 1);
		}
	};
}

// square root continued fraction class
class SqrtCF
{
	private:
		std::vector<int> coefficients;
		std::unordered_set<Remainder> remainders;
	public:
		SqrtCF(int);
		int period();
};

class Solution
{
	public:
		void answer();

};
