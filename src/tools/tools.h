#pragma once
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

bool is_prime(long number);
std::vector<int> prime_factors(long number);

class LargeNumber
{
public:
	LargeNumber();
	LargeNumber(std::string digit_string);
	LargeNumber(long num);
	LargeNumber operator+(const LargeNumber &other) const;
	LargeNumber operator+=(LargeNumber &other);
	LargeNumber operator-(const LargeNumber &other) const;
	// LargeNumber operator-(long number) const;
	LargeNumber operator-=(const LargeNumber &other);
	LargeNumber operator*(const LargeNumber &other) const;
	LargeNumber operator*=(const LargeNumber &other);
	LargeNumber operator/(const LargeNumber &other) const;
	LargeNumber operator/=(const LargeNumber &other);
	friend std::ostream& operator<<(std::ostream& os, const LargeNumber& obj)
	{
		return os << obj.sign << obj._number;
	}

	bool operator<(const LargeNumber &other) const;
	bool operator==(const LargeNumber &other) const;
	bool operator>(const LargeNumber &other) const;
	bool operator!=(const LargeNumber &other) const;


public:
	std::string number() const;

private:
	std::string _number;
	char sign;
	unsigned size;
	char get_digit(unsigned index) const;
	bool borrow(unsigned index);

};
