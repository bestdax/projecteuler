#pragma once
#include <iostream>
#include <memory>

enum class Directions
{
	east,
	south,
	west,
	north
};

class Solution
{
public:
	Solution();
	void answer();
	unsigned long traverse_matrix();
	void forward();
	void turn();

private:
	unsigned matrix[1001][1001] {};
	unsigned current_row;
	unsigned current_col;
	unsigned number;
	Directions dir;

};
