/*
Problem description:
Number spiral diagonals
Problem 28
Starting with the number 1 and moving to the right in a clockwise direction a 5
by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed
in the same way?

page link:
https://projecteuler.net/problem=28

dax 2023-05-03 11:59:30
*/
#include "problem.h"
Solution::Solution(): current_row(500), current_col(500), number(1), dir(Directions::east)
{
	matrix[current_row][current_col] = number;
}


unsigned long Solution::traverse_matrix()
{
	unsigned long sum_of_diagonals{1};

	while(true)
	{
		forward();
		turn();

		if(current_col > 1000) break;

		++number;
		matrix[current_row][current_col] = number;

		if(current_col == current_row || current_row + current_col == 1000) sum_of_diagonals += number;
	}

	return sum_of_diagonals;
}

void Solution::forward()
{
	switch(dir)
	{
	case Directions::east:
		current_col += 1;
		break;

	case Directions::south:
		current_row += 1;
		break;

	case Directions::west:
		current_col -= 1;
		break;

	case Directions::north:
		current_row -= 1;
		break;
	}
}

void Solution::turn()
{
	switch(dir)
	{
	case Directions::east:
		if(matrix[current_row + 1][current_col] == 0) dir = Directions::south;

		break;

	case Directions::south:
		if(matrix[current_row][current_col - 1] == 0) dir = Directions::west;

		break;

	case Directions::west:
		if(matrix[current_row - 1][current_col] == 0) dir = Directions::north;

		break;

	case Directions::north:
		if(matrix[current_row][current_col + 1] == 0) dir = Directions::east;

		break;
	}
}

void Solution::answer()
{
	std::cout << "The answer is: " << fill_matrix() << std::endl;
}
