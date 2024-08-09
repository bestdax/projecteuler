/*
Problem page link:
https://projecteuler.net/problem=28

dax 2024-08-09 14:25:27
*/
#include "problem.h"
#include <vector>

void Solution::answer()
{
	std::vector<unsigned long>numbers{1};
	// square是指四方角点的个数, 除了1以外，1001 x 1001的矩阵中有2000个角点
	unsigned long n{1}, sum{1}, square{0};

	while(++square <= 2000)
	{
		n += (1 + (square - 1) / 4) * 2;
		numbers.push_back(n);
		sum += n;
	}

	std::cout << "The answer is: " << sum << std::endl;
}
