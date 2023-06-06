#pragma once
#include <iostream>
#include <vector>

typedef unsigned uint;
typedef unsigned long ulint;

class Solution
{
public:
	void answer();

};

// SqrtFraction class represent the fractional part of a square root
class SqrtFraction
{
public:
	SqrtFraction(ulint n);
	ulint radicant;
	int units;
	uint introot;

	SqrtFraction operator*(int n) const;
	SqrtFraction& operator*=(int n);
	SqrtFraction operator/(int n) const;
	SqrtFraction& operator/=(int n);
	friend SqrtFraction operator+(const SqrtFraction& lhs, const SqrtFraction& rhs);
	SqrtFraction& operator+=(const SqrtFraction& other);
	friend SqrtFraction operator-(const SqrtFraction& lhs, const SqrtFraction& rhs);
	SqrtFraction& operator-=(const SqrtFraction& other);
	friend std::ostream& operator<<(std::ostream &os, const SqrtFraction& sf);

	friend bool operator==(const SqrtFraction& lhs, const SqrtFraction& rhs);

};

// IntFrac represents a complex number with integer and sqrt fractional part
class IntFrac
{
public:
	IntFrac();
	IntFrac(uint, SqrtFraction);
	IntFrac(int);
	int ipart;
	SqrtFraction fpart;
	friend IntFrac operator+(const IntFrac& lhs, const IntFrac& rhs);
	friend IntFrac operator-(const IntFrac& lhs, const IntFrac& rhs);
	friend IntFrac operator*(const IntFrac& lhs, const IntFrac& rhs);
	IntFrac operator/(const IntFrac& other);
	friend std::ostream& operator<<(std::ostream &os, const IntFrac &intfrac);

	friend bool operator==(const IntFrac& lhs, const IntFrac& rhs);
};

class Fraction
{
public:
	Fraction(IntFrac u, IntFrac l);
	IntFrac upper;
	IntFrac lower;
	Fraction reciprocal();
	friend bool operator==(const Fraction& lhs, const Fraction& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};

class SqrtExpansion
{
public:
	SqrtExpansion(ulint n);
	std::vector<uint> factors;
	Fraction frac;
	std::vector<Fraction> fracs;
	uint period;
	void next();

};
