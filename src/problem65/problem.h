#pragma once
#include <iostream>
#include <vector>
#include "longint.h"
class Solution
{
public:

	std::vector<lint> factors;
	void gen_factors(lint n);
	void gen_convergents();
	lint conv_upper;
	lint conv_lower;
	void answer();

};
