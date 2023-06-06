/*
Problem description:

page link:
https://projecteuler.net/problem=64

dax 2023-06-06 15:44:30
*/
#include "problem.h"
#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>

SqrtFraction::SqrtFraction(ulint n): radicant(n)
{
	introot = std::sqrt(radicant);

	if(introot * introot == radicant) units = 0;
	else units = 1;
}

std::ostream& operator<<(std::ostream &os, const SqrtFraction& sf)
{
	uint root_ipart = std::floor(std::sqrt(sf.radicant));

	if(sf.units > 1)
		os << sf.units << "(√" << sf.radicant << " - " << root_ipart << ')';
	else if(sf.units == 1)
		os << "(√" << sf.radicant << " - " << root_ipart << ')';

	return os;
}


SqrtFraction SqrtFraction::operator*(int n) const
{
	auto product(*this);
	product.units *= n;
	return product;
}


SqrtFraction& SqrtFraction::operator*=(int n)
{
	units *= n;
	return *this;
}

SqrtFraction SqrtFraction::operator/(int n) const
{
	auto quotient(*this);
	quotient.units /= n;
	return quotient;
}

SqrtFraction& SqrtFraction::operator/=(int n)
{
	units /= n;
	return *this;
}

SqrtFraction operator+(const SqrtFraction& lhs, const SqrtFraction& rhs)
{
	if(lhs.radicant == rhs.radicant)
	{
		SqrtFraction sum(lhs.radicant);
		sum.units = lhs.units + rhs.units;
		return sum;
	}
	else
	{
		throw "Operation not supported!";
	}
}

SqrtFraction& SqrtFraction::operator+=(const SqrtFraction& other)
{
	*this = *this + other;
	return *this;
}

SqrtFraction operator-(const SqrtFraction& lhs, const SqrtFraction& rhs)
{
	if(lhs.radicant == rhs.radicant)
	{
		SqrtFraction difference(lhs.radicant);
		difference.units = lhs.units - rhs.units;
		return difference;
	}
	else
	{
		throw "Operation not supported!";
	}
}

SqrtFraction& SqrtFraction::operator-=(const SqrtFraction& other)
{
	*this = *this - other;
	return *this;
}

bool operator==(const SqrtFraction& lhs, const SqrtFraction& rhs)
{
	return lhs.radicant == rhs.radicant && lhs.units == rhs.units;
}

IntFrac::IntFrac(): ipart(0), fpart(SqrtFraction(0)) {} // IntFract constructor
IntFrac::IntFrac(int i): ipart(i), fpart(SqrtFraction(0)) {} // IntFract constructor
IntFrac::IntFrac(uint i, SqrtFraction f): ipart(i), fpart(f) {} // IntFract constructor

bool operator==(const IntFrac& lhs, const IntFrac& rhs)
{
	return lhs.ipart == rhs.ipart && lhs.fpart == rhs.fpart;
}

IntFrac operator+(const IntFrac &lhs, const IntFrac& rhs)
{
	if(lhs.fpart.radicant == rhs.fpart.radicant)
	{
		return IntFrac(lhs.ipart + rhs.ipart, lhs.fpart + rhs.fpart);
	}
	else
	{
		if(lhs.fpart.radicant == 0 && rhs.fpart.radicant != 0)
		{
			return IntFrac(lhs.ipart + rhs.ipart, rhs.fpart);
		}
		else if(lhs.fpart.radicant != 0 && rhs.fpart.radicant == 0)
		{
			return IntFrac(lhs.ipart + rhs.ipart, lhs.fpart);
		}
		else
			throw "Operation not support";
	}
}

IntFrac operator-(const IntFrac& lhs, const IntFrac& rhs)
{
	if(lhs.fpart.radicant == rhs.fpart.radicant)
	{
		return IntFrac(lhs.ipart - rhs.ipart, lhs.fpart - rhs.fpart);
	}
	else
	{
		throw "Operation not support";
	}
}

IntFrac operator*(const IntFrac& lhs, const IntFrac& rhs)
{
	IntFrac product{};

	if(lhs.fpart.radicant == rhs.fpart.radicant)
	{
		uint root_ipart = std::sqrt(rhs.fpart.radicant);
		IntFrac temp(lhs.fpart.units * rhs.fpart.units * (lhs.fpart.radicant - root_ipart * root_ipart),
		             SqrtFraction(lhs.fpart.radicant)  * (-2 * root_ipart) * lhs.fpart.units * rhs.fpart.units);
		product.ipart = lhs.ipart * rhs.ipart;
		product.fpart = lhs.fpart * rhs.ipart + rhs.fpart * lhs.ipart;
		product = product + temp;
	}

	return product;
}

std::ostream& operator<<(std::ostream &os, const IntFrac &intfrac)
{
	os << intfrac.ipart;
	auto temp(intfrac);

	if(intfrac.fpart.units > 0)
	{
		os << " + " << intfrac.fpart;
	}
	else if(intfrac.fpart.units == 0 || intfrac.fpart.radicant == 0)
	{
	}
	else
	{
		os << " - " << temp.fpart * -1;
	}

	return os;
}

Fraction::Fraction(IntFrac u, IntFrac l): upper(u), lower(l) {}

Fraction Fraction::reciprocal()
{
	return Fraction(lower, upper);
}

bool operator==(const Fraction& lhs, const Fraction& rhs)
{
	return lhs.upper == rhs.upper && lhs.lower == rhs.lower;
}
std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	os << f.upper << std::endl
	   << std::string(50, '-') << std::endl
	   << f.lower << std::endl;
	return os;
}


SqrtExpansion::SqrtExpansion(ulint n): frac(IntFrac(0, SqrtFraction(n)), IntFrac(1, SqrtFraction(n) * 0))
{
	uint ipart = std::sqrt(n);
	factors.push_back(ipart);
	fracs.push_back(Fraction(frac));
}

void SqrtExpansion::next()
{
	bool stop = false;

	while(!stop)
	{
		frac = frac.reciprocal();
		frac.upper = frac.upper * (frac.lower + 2 * (frac.lower.fpart.introot - frac.lower.ipart));
		frac.lower = frac.lower * (frac.lower + 2 * (frac.lower.fpart.introot - frac.lower.ipart));
		auto factor = frac.upper.ipart / frac.lower.ipart;
		// factors.push_back(frac.upper.ipart / frac.lower.ipart);
		frac.upper.ipart %= frac.lower.ipart;
		uint g = std::gcd(frac.upper.ipart, frac.upper.fpart.units);
		g = std::gcd(g, frac.lower.ipart);
		frac.upper.ipart /= g;
		frac.upper.fpart /= g;
		frac.lower.ipart /= g;
		factors.push_back(factor);
		auto it = std::find(fracs.begin(), fracs.end(), frac);

		if(it != fracs.end())
		{
			stop = true;
			period = fracs.end() - it;
		}
		else
		{
			fracs.push_back(Fraction(frac));
		}
	}
}

void Solution::answer()
{
	uint odd_count = 0;

	for(uint i = 2; i <= 10000; ++i)
	{
		uint root = std::sqrt(i);

		if(root * root != i)
		{
			SqrtExpansion se(i);
			se.next();

			if(se.period % 2 != 0) ++odd_count;
		}
	}

	std::cout << "The answer is: " << odd_count << std::endl;
}
