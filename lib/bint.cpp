#include "bint.h"

void bint::trim()
{
	while(digits.size() > 1 && digits.back() == 0)
	{
		digits.pop_back();
	}
}

bint::bint(uint64_t num)
{
	while(num > 0)
	{
		digits.push_back(num % BASE);
		num /= BASE;
	}

	if(digits.empty())
	{
		digits.push_back(0);
	}
}

bint::bint(const std::string& str)
{
	bint base(1);
	*this = 0;

	for(char ch : str)
	{
		if(isdigit(ch))
		{
			*this = *this * 10 + (ch - '0');
		}
	}
}

bint bint::operator+(const bint& other) const
{
	bint result;
	result.digits.resize(std::max(digits.size(), other.digits.size()), 0);

	uint64_t carry = 0;

	for(size_t i = 0; i < result.digits.size(); ++i)
	{
		uint64_t sum = carry;

		if(i < digits.size())
		{
			sum += digits[i];
		}

		if(i < other.digits.size())
		{
			sum += other.digits[i];
		}

		result.digits[i] = sum % BASE;
		carry = sum / BASE;
	}

	if(carry)
	{
		result.digits.push_back(carry);
	}

	result.trim();
	return result;
}

bint bint::operator*(const bint& other) const
{
	bint result;
	result.digits.resize(digits.size() + other.digits.size(), 0);

	for(size_t i = 0; i < digits.size(); ++i)
	{
		uint32_t carry = 0;

		for(size_t j = 0; j < other.digits.size() || carry; ++j)
		{
			uint64_t temp = result.digits[i + j] +
			                static_cast<uint64_t>(digits[i]) * (j < other.digits.size() ? other.digits[j] : 0) +
			                carry;
			result.digits[i + j] = temp % BASE;
			carry = temp / BASE;
		}
	}

	result.trim();
	return result;
}

bint& bint::operator=(uint64_t num)
{
	digits.clear();

	while(num > 0)
	{
		digits.push_back(num % BASE);
		num /= BASE;
	}

	if(digits.empty())
	{
		digits.push_back(0);
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const bint& bigint)
{
	os << bigint.to_str();
	return os;
}

auto bint::operator<=>(const bint& other) const
{
	if(digits.size() != other.digits.size())
		return digits.size() <=> other.digits.size();
	else
	{
		for(unsigned i = digits.size() - 1; i >= 0; --i)
			if(digits[i] != other.digits[i])
				return digits[i] <=> other.digits[i];
	}

	return std::strong_ordering::equal;
}

bool bint::operator==(const bint& other) const
{
	return digits == other.digits;
}

std::string bint::to_str() const
{
	if(digits.empty())
	{
		return "0";
	}

	std::vector<uint64_t> dec_digits;
	bint current_value = *this;

	while(!current_value.digits.empty() && current_value.digits.back() > 0)
	{
		uint64_t remainder = 0;

		for(int i = current_value.digits.size() - 1; i >= 0; --i)
		{
			uint64_t temp = (remainder << 30) + current_value.digits[i];
			current_value.digits[i] = temp / bint::DEC_BASE;
			remainder = temp % bint::DEC_BASE;
		}

		dec_digits.push_back(remainder);
		current_value.trim();
	}

	os << dec_digits.back();

	for(int i = dec_digits.size() - 2; i >= 0; --i)
	{
		os << std::setw(9) << std::setfill('0') << dec_digits[i];
	}

	return os;
}

auto bint::operator<=>(const bint& other) const
{
	if(digits.size() != other.digits.size())
		return digits.size() <=> other.digits.size();
	else
	{
		for(unsigned i = digits.size() - 1; i >= 0; --i)
			if(digits[i] != other.digits[i])
				return digits[i] <=> other.digits[i];
	}

	return std::strong_ordering::equal;
}

bool bint::operator==(const bint& other) const
{
	return digits == other.digits;
}
