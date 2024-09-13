#pragma once
#include <vector>
#include <string>
#include <iostream>

class BigUInt
{
	private:
		std::vector<uint32_t> data;
		static const uint32_t BASE = 1 << 30;
		static const uint32_t SEG_LENGTH = 9;
		static const uint32_t SEG_BASE = 1e9;
		void trim();
		uint32_t mod(uint32_t) const;
	public:
		BigUInt();
		BigUInt(std::string);
		BigUInt(uint64_t);
		BigUInt(const BigUInt &other);
		std::string to_string() const;
		BigUInt operator+(const BigUInt &other) const;
		bool operator==(const BigUInt &other) const;
		friend std::ostream& operator<<(std::ostream& os, const BigUInt& n);
};
