#pragma once
#include <utils.h>
#include <vector>

class Solution
{
	private:
		std::vector<std::vector<unsigned>> matrix;
	public:
		Solution(): matrix(100, std::vector<unsigned>(100, 0)) {};

		void read_matrix();
		void answer();

};
