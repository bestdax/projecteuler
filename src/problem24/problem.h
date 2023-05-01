#pragma once
#include <iostream>
#include <algorithm>
#include <string>

class Solution
{
public:
	std::string nth_permutation(std::string collection, unsigned n);
	void set_string(std::string col);
	std::string get_colllection();
	bool next_permutation();
	void answer();
	std::string collection;
private:

};
