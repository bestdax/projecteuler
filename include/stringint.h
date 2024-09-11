#pragma once
#include <iostream>
#include <string>
#include <compare>

class StringInt
{
	public:
		StringInt();
		StringInt(std::string);
		StringInt(uint64_t);
		StringInt(const StringInt&);
		void reverse();
		StringInt operator+(const StringInt& other)const;
		StringInt& operator+=(const StringInt& other);
		StringInt& operator++();
		bool operator==(const StringInt& other) const;
		StringInt operator*(const StringInt& other) const;
		StringInt& operator*=(const StringInt& other);
		StringInt power(const StringInt& other) const;
		std::string to_string() const;
		StringInt sum_of_digits() const;
		StringInt factorial() const;
		auto operator<=>(const StringInt& other) const;

	private:
		void trim();
		std::string data;
		friend std::ostream& operator<<(std::ostream&, const StringInt&);

};

StringInt operator+(const std::string&, const StringInt&);
StringInt operator+(uint64_t, const StringInt&);
