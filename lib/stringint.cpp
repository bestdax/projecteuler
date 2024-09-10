#include <stringint.h>
#include <algorithm>

StringInt::StringInt(): data("0") {};

StringInt::StringInt(std::string s): data(s)
{
	reverse();
}

StringInt::StringInt(uint64_t n): data(std::to_string(n))
{
	reverse();
}

void StringInt::reverse()
{
	std::reverse(data.begin(), data.end());
}

std::ostream& operator<<(std::ostream& os, const StringInt& n)
{
	for(auto it = n.data.rbegin(); it != n.data.rend(); ++it)
		os << (*it);

	return os;
}

StringInt StringInt::operator+(const StringInt& other) const
{
	StringInt result;
	result.data.resize(std::max(data.size(), other.data.size()));
	bool carry = false;

	for(unsigned i = 0; i < result.data.size(); ++i)
	{
		result.data[i] = (i < data.size() ? data[i] : '0') + (i < other.data.size() ? other.data[i] : '0') - '0';

		if(carry)
		{
			++result.data[i];
			carry = false;
		}

		if(result.data[i] > '9')
		{
			carry = true;
			result.data[i] -= 10;
		}
	}

	if(carry) result.data.push_back('1');

	return result;
}

StringInt operator+(std::string& lhs, StringInt& rhs)
{
	return rhs.operator + (lhs);
}

StringInt operator+(uint64_t lhs, const StringInt& rhs)
{
	return rhs.operator + (lhs);
}

bool StringInt::operator==(const StringInt& other) const
{
	return data == other.data;
}
