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

std::strong_ordering bint::operator<=>(const bint& other) const
{
	if(digits.size() != other.digits.size())
		return digits.size() <=> other.digits.size();
	else
	{
		for(int i = digits.size() - 1; i >= 0; --i)
		{
			if(digits[i] != other.digits[i])
				return digits[i] <=> other.digits[i];
		}
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

	std::string sn;
	// os << dec_digits.back();

	for(int i = dec_digits.size() - 1; i >= 0; --i)
	{
		auto temp = std::to_string(dec_digits[i]);

		if(i != dec_digits.size() - 1)
		{
			temp = std::string(9 - temp.size(), '0') + temp;
		}

		sn += temp;

	}

	if(sn.empty()) sn = "0";

	return sn;
}

bool bint::is_palindrome()
{
	auto sn = to_str();
	auto l = sn.begin();
	auto r = sn.end() - 1;

	while(l < r)
	{
		if(*l != *r) return false;

		++l, --r;
	}

	return true;
}

bint bint::reverse()
{
	auto sn = to_str();
	std::reverse(sn.begin(), sn.end());
	return bint(sn);
}

bint& bint::operator+=(const bint& other)
{
	*this = *this + other;
	return *this;
}

bint bint::digtal_sum()
{
	auto sn = to_str();
	bint dm;

	for(auto c : sn)
		dm += bint(c - '0');

	return dm;
}

bint& bint::operator++()
{
	*this += 1;
	return *this;
}

bint bint::power(const bint& other)
{
	if(other == 0)
	{
		*this = 1;
		return *this;
	}
	else
	{

		bint prod(1);

		for(bint i = 1; i <= other; ++i)
		{
			prod = prod * (*this);
		}

		return prod;
	}
}

bint bint::number_of_digits()
{
	return to_str().size();
}

bint bint::middle()  const
{
	bint m = *this;

	uint32_t remainder{};

	for(int i = m.digits.size() - 1; i >= 0; --i)
	{

		m.digits[i] += remainder * BASE;
		remainder = m.digits[i] % 2;
		m.digits[i] /= 2;
	}

	return m;
}

bint bint::operator-(const bint& other) const
{
	if(*this < other) throw std::runtime_error("减法错误：被减数小于减数");

	bint result;
	bool borrow{false};
	result.digits.resize(digits.size(), 0);

	for(int i = 0; i < digits.size(); ++i)
	{
		if(digits[i] < other.digits[i])
		{
			result.digits[i] = BASE + digits[i] - other.digits[i];

			if(borrow) --result;
		}
		else
			result.digits[i] =  digits[i] - other.digits[i];
	}
}

