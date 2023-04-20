/*
Problem description:

page link:
https://projecteuler.net/problem=

dax 2023-06-03 20:39:10
*/
#include "problem.h"
#include "number.h"
#include <vector>
#include <fstream>
#include <string>

bool is_group_primes(std::vector<unsigned long> &numbers)
{
	for(auto it = numbers.begin(); it != numbers.end() - 1; ++it)
		for(auto it_next = it + 1; it_next != numbers.end(); ++it_next)
		{
			if(!dax::is_prime(dax::concatenate(*it, *it_next)))
				return false;

			if(!dax::is_prime(dax::concatenate(*it_next, *it)))
				return false;
		}

	return true;
}

void Solution::answer()
{
	std::ifstream file;
	file.open("src/problem60/prime_list.txt");
	std::vector<unsigned long> primes_list;
	std::string pnumber;

	if(file.is_open())
	{
		while(std::getline(file, pnumber, ','))
		{
			primes_list.push_back(std::stoi(pnumber));
		}
	}

	// std::cout << primes.back() << std::endl;
	std::vector<unsigned long> primes(primes_list.begin(), primes_list.begin() + 1000);

	// std::vector<unsigned> first_four{3, 7, 109, 673};
	// std::vector<unsigned long > first_four{3, 7, 541, 4159};
	// auto next = first_four.back();
	for(auto it1 = primes.begin(); it1 != primes.end() - 4; ++it1)
		for(auto it2 = it1 + 1; it2 != primes.end() - 3; ++it2)
			for(auto it3 = it2 + 1; it3 != primes.end() - 2; ++it3)
				for(auto it4 = it3 + 1; it4 != primes.end() - 1; ++it4)
				{
					std::vector<unsigned long> first_four{*it1, *it2, *it3, *it4};

					if(is_group_primes(first_four))
					{
						bool notfound = true;
						auto next = first_four.back();
						unsigned count = 0;

						while(notfound)
						{
							next = dax::next_prime_larger_than(next);
							auto temp = first_four;
							temp.push_back(next);

							if(is_group_primes(temp)) notfound = false;

							if(count == 1000)
							{
								next = 0;
								break;
							}

							++count;
						}

						if(next != 0)
						{
							std::cout << *it1 << '\t'
							          << *it2 << '\t'
							          << *it3 << '\t'
							          << *it4 << '\t'
							          << next << '\t'
							          // << *it5 << '\t'
							          << *it1 + *it2 + *it3 + *it4 + next
							          << std::endl;
							return;
						}
					}
				}

	// std::cout << "The answer is: " << next << std::endl;
}
