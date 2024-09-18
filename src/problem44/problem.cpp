/*
Problem page link:
https://projecteuler.net/problem=44

dax 2024-09-18 14:51:32
*/
#include "problem.h"
#include <numutils.h>
#include <utils.h>

void Solution::next_pentagonal()
{
	++n;
	pentagonals.push_back(n * (3 * n - 1) / 2);
}

void Solution::answer()
{
	while(true)
	{
		next_pentagonal();

		if(pentagonals.size() > 1)
		{
			for(auto it = pentagonals.rbegin() + 1;  it != pentagonals.rend(); ++it)
			{
				if(dax::is_pentagonal(pentagonals.back() - *it) && dax::is_pentagonal(*it + pentagonals.back()))
				{
					std::cout << "The answer is " << pentagonals.back() - *it << std::endl;;
					return;
				}
			}
		}
	}

}
