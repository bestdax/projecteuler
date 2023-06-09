/*
Problem page link:
https://projecteuler.net/problem=66

dax 2023-06-09 16:06:21
*/
#include "problem.h"
#include "number.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

void Solution::answer()
{
	unsigned long max = 0;
	unsigned max_d;
	std::map<unsigned long, unsigned long> square2root;
	unsigned long max_root{1};
	unsigned long max_square{1};

	// for(unsigned i = 1; i < 100000; ++i)
	// {
	// 	unsigned long max_root = i;
	// 	unsigned long max_square = i * i;
	// 	square2root.insert(std::make_pair(max_square, max_root));
	// }

	for(unsigned d = 1; d <= 100; ++d)
	{
		if(is_square(d)) continue;

		bool notfound = true;
		unsigned long y = 1;
		unsigned long number;

		while(notfound)
		{
			number = d * y * y + 1;

			if(number > max_square)
			{
				std::cout << number << '\t' << max_square << std::endl;
				unsigned long cap = max_root * 2;

				for(unsigned i = max_root + 1; i <= cap; ++i)
				{
					if(i % 1000 == 0) std::cout << "Inserting squares of base " << i << std::endl;

					++max_root;
					max_square = max_root * max_root;
					square2root.insert(std::make_pair(max_square, max_root));
				}
			}

			if(square2root.contains(number))
			{
				auto x = square2root[number];
				std::cout << d << '\t' <<  y << '\t' << x << std::endl;

				if(x > max)
				{
					max = x;
					max_d = d;
				}

				notfound = false;
			}

			++y;
		}
	}

	std::cout << "The answer is: " << max_d << std::endl;
}
