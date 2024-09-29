#pragma once
#include <iostream>
#include <vector>
#include <prime.h>
#include <unordered_set>
#include <utility>
#include <set>

namespace std
{
template <>
struct hash<std::pair<unsigned long, unsigned long>>
{
	size_t operator()(const std::pair<unsigned long, unsigned long> & p) const
	{
		std::size_t hash = 0;

		size_t h1 = std::hash<unsigned long>()(p.first);
		size_t h2 = std::hash<unsigned long>()(p.second);

		hash = h1 ^ (h2 << 1);

		return hash;
	}
};
}

class Solution
{
	private:
		unsigned long limit;
		std::vector<bool> is_prime;
		std::vector<std::vector<unsigned long>> prime_groups;
		std::unordered_set<std::pair<unsigned long, unsigned long>> group_set;
	public:
		Solution(): limit(1e4) {};

		void init_groups();

		bool is_prime_pair(unsigned long a, unsigned long b);
		bool is_prime_group(std::vector<unsigned long>);
		void answer();

};
