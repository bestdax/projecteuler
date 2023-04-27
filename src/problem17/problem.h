#pragma once
#include <iostream>
#include <string>
#include <map>
#include <iomanip>

class Solution
{
public:
	Solution();
	std::string say_number(unsigned number);
	unsigned count(unsigned number);
	unsigned count_range(unsigned range);
	void say_range(unsigned range);
	void answer();
private:
	std::map<int, std::string> dict;

};
