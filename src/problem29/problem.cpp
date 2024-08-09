/*
Problem page link:
https://projecteuler.net/problem=29

dax 2024-08-09 15:48:51
*/
#include "problem.h"

std::vector<short> Solution::add(std::vector<short> a, std::vector<short> b)
{
	std::vector<short> result;
	auto pa = a.begin();
	auto pb = b.begin();
	bool carry = false;

	while(pa < a.end() || pb < b.end())
	{
		short d = (pa < a.end() ? *pa++ : 0) + (pb < b.end() ? *pb++ : 0) ;

		if(carry) d++;

		carry = d / 10;

		d %= 10;

		result.push_back(d);
	}

	if(carry) result.push_back(1);

	return result;
}

std::vector<short> _multiply(std::vector<short> a, unsigned d)
{
	if(d > 9) return std::vector<short> {};

	short carry = 0;

	std::vector<short> result;

	for(auto c : a)
	{
		short product = c * d;
		product += carry;
		carry = product / 10;
		product %= 10;
		result.push_back(product);
	}

	if(carry) result.push_back(carry);

	return result;
}

std::vector<short> Solution::multiply(std::vector<short>a, std::vector<short>b)
{
	std::vector<short> result;
	unsigned zero_count{};

	for(auto d : b)
	{
		auto temp = _multiply(a, d);

		for(unsigned i = 0; i < zero_count; ++i)
		{
			temp.insert(temp.begin(), 0);
		}

		result = add(result, temp);
		++zero_count;
	}

	return result;
}

void Solution::answer()
{
	std::vector<std::vector<short>> numbers;

	for(int a = 2; a <= 100; ++a)
		for(int b = 2; b <= 100; ++b)
		{
			std::vector<short> shorta;
			int tempa = a;

			// 将数字转化为char数组
			while(tempa)
			{
				shorta.push_back(tempa % 10);
				tempa /= 10;
			}

			// result存储运算的结果
			std::vector<short> result(shorta);

			// 将char数组a自乘b-1次
			for(int i = 1; i < b; ++i)
			{
				result = multiply(result, shorta);

			}

			auto it = numbers.begin();

			while(it != numbers.end())
			{
				if(*it++ == result) break;
			}

			if(it == numbers.end()) numbers.push_back(result);

		}

	std::cout << "The answer is: " << numbers.size() << std::endl;
}
