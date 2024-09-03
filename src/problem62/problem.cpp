/*
Problem page link:
https://projecteuler.net/problem=62

dax 2024-09-03 08:05:53
*/
#include "problem.h"

Solution::Solution()
{
	unsigned long n = 2;

	while(true)
	{
		auto cubic = n * n * n;

		if(cubic > cubics.back())
			cubics.push_back(cubic);
		else
			break;

		++n;
	}
}

bool Solution::is_permutation(unsigned long a, unsigned long b)
{
	int count[10] {0};

	while(a > 0)
	{
		++count[a % 10];
		a /= 10;
	}

	while(b > 0)
	{
		--count[b % 10];
		b /= 10;
	}

	for(int i = 0; i < 10; ++i)
	{
		if(count[i] != 0) return false;
	}

	return true;
}

unsigned Solution::number_of_digits(unsigned long n)
{
	unsigned l{};

	while(n > 0)
	{
		++l;
		n /= 10;
	}

	return l;
}

void Solution::answer()
{
	std::vector<unsigned long> targets;

	for(int i = 0; i < cubics.size() - 1; ++i)
	{
		targets.push_back(cubics[i]);

		for(int j = i + 1; j < cubics.size(); ++j)
		{
			if(is_permutation(cubics[i], cubics[j]))
			{
				targets.push_back(cubics[j]);
			}

			if(targets.size() == 5)
			{
				for(auto& c : targets)
					std::cout << c << '\t';

				std::cout << std::endl;

				return;
			}

			if(number_of_digits(cubics[j]) > number_of_digits(cubics[i]))
			{
				targets.clear();
				break;
			}

		}

	}

	std::cout << "The answer is: " << cubics.back() << std::endl;
}
