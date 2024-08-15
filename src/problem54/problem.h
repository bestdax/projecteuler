#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum class Rank
{
	Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
};

int operator-(Rank& lhs, Rank& rhs);

enum class Suit
{
	Club, Diamond, Heart, Spade
};

struct Card
{
	public:
		Rank r;
		Suit s;
		auto operator<=>(const Card& other) const
		{
			return r <=> other.r;
		};

		auto operator==(const Card& other) const
		{
			return r == other.r;
		};
};

enum class HandName
{
	HighCard, OnePair, TwoPairs, ThreeOfAKind, Straight, Flush, FullHouse, FourOfAKind, StraightFlush, RoyalFlush
};

class Hand
{
	public:
		Hand(std::vector<Card> cards): cards(cards)
		{
			init_hand();
		};

	private:
		bool is_same_suit();
		bool is_consequtive();
		bool is_four_of_a_kind();
		bool is_full_house();
		void init_hand();
		std::vector<Card> cards;
		HandName name;
		unsigned long score{};
};

class Solution
{
	public:
		void answer();

};
