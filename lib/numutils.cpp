#include <numutils.h>
#include <vector>

bool dax::is_palindrome(ulong n, uint base)
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

ulong dax::gcd(ulong a, ulong b)
{
	while(b != 0)
	{
		auto temp = a;
		a = b;
		b = temp % b;
	}

	return a;
}

ulong dax::lcm(ulong a, ulong b)
{
	if(a == 0 || b == 0) return 0;

	return a / dax::gcd(a, b) * b;
}

bool dax::is_pandigital(uint n, bool include_zero)
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

ulong dax::factorial(uint n)
{
	if(n == 0) return 1;

	uint f{1};

	while(n)
	{
		f *= n;
		--n;
	}

	return f;
}

bool dax::is_pentagonal(ulong p)
{
	double  n = (std::sqrt(24 * p + 1) + 1) / 6;
	return n == static_cast<ulong>(n);
}

bool dax::is_triangle(ulong t)
{
	double  n = (std::sqrt(8 * t + 1) - 1) / 2;
	return n == static_cast<ulong>(n);
}

bool dax::is_hexagonal(ulong h)
{
	double  n = (std::sqrt(8 * h + 1) + 1) / 4;
	return n == static_cast<ulong>(n);
}

bool dax::is_square(ulong s)
{
	double n = std::sqrt(s);
	return n == static_cast<ulong>(n);
}

ulong dax::concatenate(ulong a, ulong b)
{
	auto temp = b;

	while(temp)
	{
		temp /= 10;
		a *= 10;
	}

	return a + b;
}

bool dax::is_permutation(ulong n, ulong m)
{
	auto ns = std::to_string(n);
	std::sort(ns.begin(), ns.end());
	auto ms = std::to_string(m);
	std::sort(ms.begin(), ms.end());
	return ns == ms;
}
