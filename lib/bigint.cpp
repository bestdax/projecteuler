#include <bigint.h>

BigUInt::BigUInt()
{
	data.push_back(0);
}

BigUInt::BigUInt(const BigUInt& other)
{
	data = other.data;
}

BigUInt::BigUInt(uint64_t num)
{
	while(num)
	{
		data.push_back(num % BASE);
		num /= BASE;
	}

	trim();
}

BigUInt::BigUInt(std::string sn)
{
	// 如果为空则赋值为0
	if(sn.empty()) data.push_back(0);

	// 数据合化性检查
	if(sn.find_first_not_of("0123456789") != std::string::npos)
		throw std::invalid_argument("输入字符串不合法");

	// 去掉前导零
	if(sn.front() == '0' && sn.size() > 1)
	{
		auto pos = sn.find_first_not_of('0');
		sn.erase(0, pos);
	}

	// 将字符串数字分段转化为数字，每段9位
	// 取9位是因为2^30=1'073'741'824，确保每个单段能够容得下
	// 将每一段都分别与BASE取余(从高位开始)，余数乘以BASE后滚入下一位

	std::vector<uint64_t> segments;

	for(int i = sn.size(); i  > 0; i -= SEG_LENGTH)
	{
		int start_index = (i >= SEG_LENGTH) ? i - SEG_LENGTH : 0;
		auto segment = sn.substr(start_index, i - start_index);
		auto segment_value = std::stoul(segment);
		segments.push_back(segment_value);
	}

	uint64_t remainder{};

	while(!segments.empty())
	{
		for(int i = segments.size() - 1; i >= 0; --i)
		{
			uint64_t current_value = segments[i] + remainder * SEG_BASE;
			remainder = current_value % BASE;
			segments[i] = current_value / BASE;
		}

		data.push_back(remainder);
		remainder = 0;

		if(!segments.empty() && segments.back() == 0) segments.pop_back();
	}

	trim();

}

void BigUInt::trim()
{
	while(!data.empty() && data.back() == 0)
	{
		data.pop_back();
	}

	if(data.empty())
		data.push_back(0);
}

std::string BigUInt::to_string() const
{
	BigUInt copy(*this);
	uint64_t remainder{};
	std::string sn;

	while(!copy.data.empty())
	{
		for(int i = copy.data.size() - 1; i >= 0; --i)
		{
			// 有可能会溢出，所以用64位的变量来暂存中间结果
			uint64_t current_value{};
			current_value = copy.data[i] + remainder * BASE;
			remainder = current_value % SEG_BASE;
			copy.data[i] = current_value / SEG_BASE;
		}

		if(!copy.data.empty() && copy.data.back() == 0) copy.data.pop_back();

		std::string temp_sn = std::to_string(remainder);

		// 如果已经空了，说明是最高位不用补零
		if(copy.data.empty())
		{
			sn = temp_sn + sn;
		}
		else
		{

			sn = std::string(SEG_LENGTH - temp_sn.size(), '0') + temp_sn + sn;
		}

		remainder = 0;

	}

	return sn;
}

std::ostream& operator<<(std::ostream& os, const BigUInt& n)
{
	os << n.to_string();
	return os;
}

bool BigUInt::operator==(const BigUInt& other) const
{
	return data == other.data;
}

BigUInt BigUInt::operator+(const BigUInt& other) const
{
	BigUInt result;

	result.data.resize(std::max(data.size(), other.data.size()));
	uint32_t carry{};

	for(unsigned i = 0; i < result.data.size(); ++i)
	{
		result.data[i] = carry + (i < data.size() ? data[i] : 0) + (i < other.data.size() ? other.data[i] : 0);
		carry = result.data[i] >> 30;
		result.data[i] = result.data[i] % BASE;
	}

	if(carry) result.data.push_back(carry);

	return result;
}

std::strong_ordering BigUInt::operator<=>(const BigUInt&other) const
{
	if(data.size() != other.data.size()) return data.size() <=> other.data.size();
	else
	{
		for(int i = data.size() - 1; i >= 0; --i)
		{
			if(data[i] != other.data[i])
				return data[i] <=> other.data[i];
		}

		return std::strong_ordering::equal;
	}

}

BigUInt& BigUInt::operator+=(const BigUInt &other)
{
	*this = *this + other;
	return *this;
}

BigUInt& BigUInt::operator++()
{
	*this += 1;
	return *this;
}

BigUInt& BigUInt::operator*=(const BigUInt &other)
{
	*this = *this * other;
	return *this;
}

BigUInt BigUInt::power(const BigUInt &exponent) const
{
	if(exponent == 0) return 1;

	if(*this == 0) return 0;

	BigUInt exp(exponent);
	BigUInt result{1};
	BigUInt base(*this);

	while(exp > 0)
	{
		if(exp % 2 == 1)
			result *= base;

		base *= base;
		exp /= 2;
	}

	return result;
}

bool BigUInt::is_palindrome()
{
	auto ns = to_string();
	auto l = ns.begin();
	auto r = ns.end() - 1;

	while(l < r)
	{
		if(*l != * r) return false;

		++l;
		--r;
	}

	return true;
}

BigUInt BigUInt::reverse() const
{
	auto ns = to_string();
	std::reverse(ns.begin(), ns.end());
	return BigUInt(ns);
}

BigUInt BigUInt::operator-(const BigUInt& other) const
{
	if(*this < other)
	{
		throw std::invalid_argument("BigUInt不支持负数运算");
	}

	BigUInt result(*this);

	bool borrow{false};

	for(unsigned i = 0; i < data.size(); ++i)
	{
		auto subtractor = i < other.data.size() ? other.data[i] : 0;

		if(borrow)
		{
			--result.data[i];
			borrow = false;
		}

		if(result.data[i] > subtractor)
		{
			result.data[i] -= subtractor;
		}
		else
		{
			result.data[i] += BASE - subtractor;
			borrow = true;
		}
	}

	result.trim();
	return result;
}

BigUInt& BigUInt::operator--()
{
	*this = *this - 1;
	return *this;
}

BigUInt& BigUInt::operator-=(const BigUInt& other)
{
	*this = *this - other;
	return *this;
}

BigUInt BigUInt::digital_sum() const
{
	BigUInt sum;
	auto ns = to_string();
	sum = std::accumulate(ns.begin(), ns.end(), 0);
	sum -= '0' * ns.size();
	return sum;
}

BigUInt BigUInt::length() const
{
	auto sn = to_string();
	return sn.size();
}

BigUInt operator*(const BigUInt& lhs, const BigUInt& rhs)
{
	BigUInt result;
	result.data.resize(lhs.data.size() + rhs.data.size());

	for(int i = 0; i < lhs.data.size(); ++i)
	{
		uint64_t carry = 0;

		for(int j = 0; j < rhs.data.size() || carry; ++j)
		{
			uint64_t temp = result.data[i + j] + static_cast<uint64_t>(lhs.data[i]) *
			                (j < rhs.data.size() ? rhs.data[j] : 0) + carry;
			carry = temp >> 30;
			result.data[i + j] = temp &(BigUInt::BASE - 1) ;
		}
	}

	result.trim();
	return result;
}

BigUInt BigUInt::operator/(const BigUInt& other) const
{
	if(other == 0) std::invalid_argument("除数不能为零");

	BigUInt quotient;
	quotient.data.resize(data.size());
	BigUInt remainder(*this);

	BigUInt divisor(other);
	BigUInt divisor_shifted;

	unsigned long shift_count{};

	while(remainder >= divisor_shifted)
	{
		divisor_shifted = divisor << shift_count;
		++shift_count;
	}

	while(shift_count > 0)
	{
		divisor_shifted = divisor << (shift_count - 1);
		unsigned l = 0;
		unsigned r = BASE;

		if(remainder > divisor_shifted)
		{
			while(l < r && r - l != 1)
			{
				auto mid = (l + r) / 2;

				if(mid * divisor_shifted == remainder)
				{
					l = mid;
					break;
				}
				else if(mid * divisor_shifted > remainder) r = mid;
				else l = mid;

			}

			quotient.data[shift_count - 1] = l;

			remainder.data.pop_back();

		}

		--shift_count;
	}

	quotient.trim();

	return quotient;
}

BigUInt BigUInt::operator<<(unsigned long shift) const
{
	BigUInt result;
	result.data.resize(shift + data.size());

	for(unsigned long i = shift; i < result.data.size(); ++i)
		result.data[i] = data[i - shift];

	return result;
}

BigUInt& BigUInt::operator/=(const BigUInt& other)
{
	*this = *this / other;
	return *this;
}

BigUInt BigUInt::operator%(const BigUInt& other) const
{
	auto quotient = *this / other;
	return *this - quotient * other;
}
