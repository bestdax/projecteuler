#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <compare>
#include <algorithm>
#include <numeric>
#include <utility>
#include <limits>

template<typename T>
class BigVector;

class BigUInt
{
	private:
		std::vector<uint32_t> data;
		static const uint32_t BASE = 1 << 30;
		static const uint32_t SEG_LENGTH = 9;
		static const uint32_t SEG_BASE = 1e9;
		void trim();
		uint32_t mod(uint32_t) const;
	public:
		BigUInt();
		BigUInt(std::string);
		BigUInt(uint64_t);
		BigUInt(const BigUInt &other);
		std::string to_string() const;
		uint64_t toul() const;
		BigUInt operator+(const BigUInt &other) const;
		BigUInt& operator+=(const BigUInt &other);
		BigUInt& operator++();
		std::pair<BigUInt, BigUInt> divide(const BigUInt &other) const;
		std::pair<BigUInt, BigUInt> divide_by_two() const;
		BigUInt& operator/=(const BigUInt &other);
		BigUInt operator%(const BigUInt &other) const;
		BigUInt operator-(const BigUInt &other) const;
		BigUInt& operator-=(const BigUInt &other);
		BigUInt& operator--();
		BigUInt& operator*=(const BigUInt &other);
		BigUInt power(const BigUInt &other) const;
		BigUInt sqrt() const;
		bool operator==(const BigUInt &other) const;
		std::strong_ordering operator<=>(const BigUInt &other) const;
		bool is_palindrome();
		bool is_prime();
		BigUInt reverse() const;
		BigUInt digital_sum() const;
		BigUInt length() const;
		BigUInt operator<<(unsigned long) const;
		friend std::ostream& operator<<(std::ostream& os, const BigUInt& n);
		friend BigUInt operator*(const BigUInt& lhs, const BigUInt& rhs);
		template<typename T>
		friend class BigVector;
};

BigVector<char> sieve_of_eratosthenes(const BigUInt& limit);
BigUInt operator/(const BigUInt &lhs, const BigUInt &rhs);
BigUInt operator*(const BigUInt& lhs, const BigUInt& rhs);

template<typename T>
class BigVector
{
	private:
		std::vector<std::vector<T>> vectors;
		BigUInt _size;
	public:
		BigVector(BigUInt size, T value)
		{

			_size = size;

			BigUInt segments_count = size / BigUInt::BASE;

			for(BigUInt i = 0; i < segments_count; ++i)
			{
				vectors.push_back(std::vector(BigUInt::BASE, value));
			}

			if(size % BigUInt::BASE != 0) vectors.push_back(std::vector((size % BigUInt::BASE).toul(), value));
		}

		BigUInt size() const
		{
			return _size;
		}

		T& operator[](BigUInt index)
		{
			if(index >= size()) throw std::out_of_range("索引越界");

			BigUInt segment_index = index / BigUInt::BASE;
			BigUInt offset_in_segment = index % BigUInt::BASE;

			if(offset_in_segment == 0 && segment_index > 0)
				return vectors[segment_index.toul() - 1].back();

			if(segment_index > 0)
				return vectors[segment_index.toul()][offset_in_segment.toul() - 1];
			else
				return vectors[0][offset_in_segment.toul()];
		}

		const T& operator[](BigUInt index) const
		{
			if(index > size()) throw std::out_of_range("索引越界");

			BigUInt segment_index = index / BigUInt::BASE;
			BigUInt offset_in_segment = index % BigUInt::BASE;

			if(offset_in_segment == 0 && segment_index > 0)
				return vectors[segment_index.toul() - 1].back();

			if(segment_index > 0)
				return vectors[segment_index.toul()][offset_in_segment.toul() - 1];
			else
				return vectors[0][offset_in_segment.toul()];
		}
};
