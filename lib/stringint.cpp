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
