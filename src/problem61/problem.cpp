/*
Problem description:

page link:
https://projecteuler.net/problem=61

dax 2023-06-04 16:57:51
*/
#include "problem.h"
#include "number.h"
#include <algorithm>
#include <map>


void Solution::answer()
{
	std::vector<unsigned> numbers{};

	// generate all ploygonal numbers
	for(unsigned i = 1000; i < 10000; ++i)
	{
		if(dax::is_triangle_number(i) ||
		        dax::is_square(i) ||
		        dax::is_pentagonal_number(i) ||
		        dax::is_hexagonal_number(i) ||
		        dax::is_heptagonal_number(i) ||
		        dax::is_octagonal_number(i))
			numbers.push_back(i);
	}

	// iterate all numbers to find its cyclical neighbor
	std::vector<std::vector<unsigned>> lists;

	for(auto n : numbers)
	{
		std::vector<unsigned> temp{n};
		lists.push_back(temp);
	}

	for(unsigned i = 0; i < 5; ++i)
	{
		std::vector<std::vector<unsigned>> temp_lists;

		for(auto row : lists)
		{
			if(dax::size(row.back() % 100) != 2) continue; // if the third digit is zero, jump to next loop

			for(auto n : numbers)
			{
				if(row.back() % 100 == n / 100)
				{
					std::vector<unsigned> temp_row(row);

					if(std::find(temp_row.begin(), temp_row.end(), n) == temp_row.end())
					{
						temp_row.push_back(n);
						temp_lists.push_back(temp_row);
					}
				}
			}
		}

		lists = temp_lists;
	}

	for(auto row : lists)
	{
		if(row.front() / 100 == row.back() % 100) // filter out last and first are cyclical
		{
			std::vector<unsigned> categories;
			unsigned count = 0;

			for(auto n : row)
			{
				bool pushed = false;

				// if not in categories, push in and toggle pushed to true, one number can only be counted once

				if(dax::is_triangle_number(n))
				{
					if(std::find(categories.begin(), categories.end(), 3) == categories.end())
					{
						categories.push_back(3);
						pushed = true;
					}
				}

				if(dax::is_square(n))
				{
					if(std::find(categories.begin(), categories.end(), 4) == categories.end())
					{
						categories.push_back(4);
						pushed = true;
					}
				}

				if(dax::is_pentagonal_number(n))
				{
					if(std::find(categories.begin(), categories.end(), 5) == categories.end())
					{
						categories.push_back(5);
						pushed = true;
					}
				}

				if(dax::is_hexagonal_number(n))
				{
					if(std::find(categories.begin(), categories.end(), 6) == categories.end())
					{
						categories.push_back(6);
						pushed = true;
					}
				}

				if(dax::is_heptagonal_number(n))
				{
					if(std::find(categories.begin(), categories.end(), 7) == categories.end())
					{
						categories.push_back(7);
						pushed = true;
					}
				}

				if(dax::is_octagonal_number(n))
				{
					if(std::find(categories.begin(), categories.end(), 8) == categories.end())
					{
						categories.push_back(8);
						pushed = true;
					}
				}

				if(pushed) count++;
			}

			std::sort(categories.begin(), categories.end());
			auto last = std::unique(categories.begin(), categories.end());
			categories.erase(last, categories.end());

			// filter out 6 categories and counted six times
			if(categories.size() == 6 && count == 6)
			{
				unsigned sum{};

				for(auto n : row)
				{
					std::cout << n << '\t';
					sum += n;
				}

				std::cout << " = " << sum << std::endl;
			}
		}
	}
}
