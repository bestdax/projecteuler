#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <compare>

class bint
{
	private:
		std::vector<uint32_t> digits;
		static const uint32_t BASE = 1 << 30;  // 2^30
		static const uint32_t DEC_BASE = 1000000000; // 10^9
		void trim();
	public:
		std::string to_str() const;
		bint() : digits(1, 0) {};

		bint(uint64_t num);
		bint(const std::string& str);
		bint operator+(const bint& other) const;
		bint operator*(const bint& other) const;
		bint& operator=(uint64_t num);
		auto operator<=>(const bint& other) const;
		bool operator==(const bint& other) const;
		friend std::ostream& operator<<(std::ostream& os, const bint& bigint);
};
