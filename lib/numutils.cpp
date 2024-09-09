#include <numutils.h>
#include <vector>

bool dax::is_palindrome(unsigned long n)
{
	std::vector<char> digits;

	while(n != 0)
	{
		char d = n % 10;
		digits.push_back(d);
		n /= 10;
	}

	auto l = digits.begin();
	auto r = digits.end() - 1;

	while(l < r)
	{
		if(*l != *r)return false;

		++l, --r;
	}

	return true;
}
