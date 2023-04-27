/*
Problem description:
Maximum path sum I
Problem 18
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from
top to bottom is 23.

   3
  7 4
 2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

                            75
                          95  64
                        17  47  82
                      18  35  87  10
                    20  04  82  47  65
                  19  01  23  75  03  34
                88  02  77  73  07  63  67
              99  65  04  28  06  16  70  92
            41  41  26  56  83  40  80  70  33
          41  48  72  33  47  32  37  16  94  29
        53  71  44  65  25  43  91  52  97  51  14
      70  11  33  28  77  73  17  78  39  68  17  57
    91  71  52  38  17  14  91  43  58  50  27  29  48
  63  66  04  68  89  53  67  30  73  16  69  87  40  31
04  62  98  27  23  09  70  98  73  93  38  53  60  04  23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67,
is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a
clever method! ;o)
page link:
https://projecteuler.net/problem=18

dax 2023-04-27 16:43:29
*/
#include "problem.h"

Solution::Solution()
{
	this->triangle =
	{

		{75},
		{95, 64},
		{17, 47, 82},
		{18, 35, 87, 10},
		{20,  4, 82, 47, 65},
		{19,  1, 23, 75,  3, 34},
		{88,  2, 77, 73,  7, 63, 67},
		{99, 65,  4, 28,  6, 16, 70, 92},
		{41, 41, 26, 56, 83, 40, 80, 70, 33},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
		{63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
		{ 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
	};
}

int Solution::find_max_parents(unsigned row, unsigned col)
{
	if(row == 0) return 0;
	else if(col == 0) return triangle[row - 1][col];
	else if(col == triangle[row].size() - 1) return *(triangle[row - 1].end() - 1);
	else
	{
		return std::max(triangle[row - 1][col], triangle[row - 1][col - 1]);
	}
}

std::vector<std::vector<int>> Solution::handled_row_by_row()
{
	std::vector<std::vector<int>> handled = triangle;

	for(unsigned row = 0; row < triangle.size(); ++row)
		for(unsigned col = 0; col < triangle[row].size(); ++col)
		{
			handled[row][col] = triangle[row][col] + find_max_parents(row, col);
		}

	return handled;
}

// int Solution::max_sum()
// {
// 	auto handled = handled_row_by_row();
// 	auto last_row = handled[handled.size()];
// 	return std::max_element(last_row.begin(), last_row.end());
// }

void Solution::answer()
{
	auto handled = handled_row_by_row();

	for(auto row : handled)
	{
		for(auto num : row)
		{
			std::cout << num << '\t';
		}

		std::cout << std::endl;
	}

	std::cout << "The answer is: " << "" << std::endl;
}
