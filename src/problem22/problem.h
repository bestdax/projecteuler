#pragma once
#include <utils.h>
#include <string>
#include <vector>

class Solution
{
	private:
		std::vector<std::string> names;
	public:
		Solution();
		unsigned name_score(std::string& name);
		void answer();

};
