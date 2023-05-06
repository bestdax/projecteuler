#pragma once
#include <iostream>
#include <vector>

class Solution
{
public:
	unsigned coin_sums();
	void answer();
private:
	std::vector<unsigned> coins {1, 2, 5, 10, 20, 50, 100, 200};
	unsigned total{200};

};
