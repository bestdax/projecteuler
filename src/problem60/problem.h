#pragma once
#include <iostream>
#include "number.h"
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <unordered_set>

// 自定义哈希函数
struct vector_hash
{
	std::size_t operator()(const std::vector<unsigned long>& v) const
	{
		std::size_t hash = 0;

		for(unsigned long elem : v)
		{
			hash ^= std::hash<unsigned long> {}(elem) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
		}

		return hash;
	}
};

// 自定义相等比较函数
struct vector_equal
{
	bool operator()(const std::vector<unsigned long>& lhs, const std::vector<unsigned long>& rhs) const
	{
		return lhs == rhs;
	}
};

class Solution
{
	private:
		std::vector<unsigned long> primes = dax::sieve_of_Euler(1e4);

	public:
		void answer();
		void answer2();
		bool is_prime_set(std::set<std::vector<unsigned long>>&, std::vector<unsigned long>, unsigned long n);
		std::set<std::vector<unsigned long>> find_all_prime_pairs();
		std::set<std::vector<unsigned long>> find_all_sets_with_n_members(unsigned n);
		bool is_prime_set(std::unordered_set<std::vector<unsigned long>, vector_hash, vector_equal>&,
		                  std::vector<unsigned long>, unsigned long n);
		std::unordered_set<std::vector<unsigned long>, vector_hash, vector_equal> find_all_prime_pairs_set();
		std::unordered_set<std::vector<unsigned long>, vector_hash, vector_equal> find_all_sets_with_n_members_set(unsigned n);

};
