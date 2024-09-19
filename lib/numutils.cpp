#include <numutils.h>
#include <vector>

bool dax::is_palindrome(unsigned long n, unsigned base)
{
	if(n == 0) return true;

	std::vector<char> digits;

	while(n != 0)
	{
		char d = n % base;
		digits.push_back(d);
		n /= base;
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

bool dax::is_pandigital(unsigned n, bool include_zero)
{
	auto ns = std::to_string(n);
	std::unordered_set<char> digits_set(ns.begin(), ns.end());

	if(digits_set.size() != ns.size()) return false;

	char max_digit = (include_zero ? ns.size() - 1 : ns.size()) + '0';

	for(int i = 0; i < ns.size(); ++i)
	{
		if(ns[i] > max_digit) return false;
	}

	return true;

}

unsigned long dax::factorial(unsigned n)
{
	if(n == 0) return 1;

	unsigned f{1};

	while(n)
	{
		f *= n;
		--n;
	}

	return f;
}

bool dax::is_pentagonal(unsigned long p)
{
	double  n = (std::sqrt(24 * p + 1) + 1) / 6;
	return n == static_cast<unsigned long>(n);
}

bool dax::is_triangle(unsigned long t)
{
	double  n = (std::sqrt(8 * t + 1) - 1) / 2;
	return n == static_cast<unsigned long>(n);
}

bool dax::is_hexagonal(unsigned long h)
{
	double  n = (std::sqrt(8 * h + 1) + 1) / 4;
	return n == static_cast<unsigned long>(n);
}
