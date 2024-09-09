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

unsigned long dax::gcd(unsigned long a, unsigned long b)
{
	while(b != 0)
	{
		auto temp = a;
		a = b;
		b = temp % b;
	}

	return a;
}

unsigned long dax::lcm(unsigned long a, unsigned long b)
{
	if(a == 0 || b == 0) return 0;

	return a / dax::gcd(a, b) * b;
}
