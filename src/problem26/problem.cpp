/*
Problem description:
Reciprocal cycles
A unit fraction contains 1 in the numerator. The decimal representation of the
unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in
its decimal fraction part.

page link:
https://projecteuler.net/problem=26

dax 2023-05-01 18:26:01
*/
#include "problem.h"


unsigned Solution::reciprocal(unsigned n)
{
	unsigned divident{1};
	std::string q{"0."};
	unsigned count{0};
	std::vector<unsigned> rmds{};

	while(std::find(rmds.begin(), rmds.end(), divident) == rmds.end())
	{
		rmds.push_back(divident);
		int cnt{};

		while(divident < n)
		{
			cnt++;
			divident *= 10;

			if(cnt > 1) q.push_back('0');
		}

		if(divident % n == 0)
		{
			q.push_back(divident / n + 48);
			break;
		}

		q.push_back(divident / n + 48);
		divident %= n;
		count++;
	}

	auto index = std::find(rmds.begin(), rmds.end(), divident);
	return rmds.end() - index;
}

unsigned Solution::number_has_longest_reciprocal_cycles_within(unsigned cap)
{
	unsigned number{}, length{};

	for(unsigned i = 2; i <= cap; ++i)
	{
		if(reciprocal(i) > length)
		{
			length = reciprocal(i);
			number = i;
		}
	}

	return number;
}

void Solution::answer()
{
	std::cout << "The answer is: " << number_has_longest_reciprocal_cycles_within(1000) << std::endl;
}
