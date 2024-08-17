#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <filesystem>

enum class Rank
{
	Two = 2,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};

int operator-(Rank& lhs, Rank& rhs);

enum class Suit
{
	Club, Diamond, Heart, Spade
};

struct Card
{
	public:
		Rank rank;
		Suit suit;
		auto operator<=>(const Card& other) const
		{
			return rank <=> other.rank;
		};

		auto operator==(const Card& other) const
		{
			return rank == other.rank;
		};
};

static std::ostream& operator<<(std::ostream& os, const Rank& rank)
{
	switch(rank)
	{
	case Rank::Two:
		os << "2";
		break;

	case Rank::Three:
		os << "3";
		break;

	case Rank::Four:
		os << "4";
		break;

	case Rank::Five:
		os << "5";
		break;

	case Rank::Six:
		os << "6";
		break;

	case Rank::Seven:
		os << "7";
		break;

	case Rank::Eight:
		os << "8";
		break;

	case Rank::Nine:
		os << "9";
		break;

	case Rank::Ten:
		os << "T";
		break;

	case Rank::Jack:
		os << "J";
		break;

	case Rank::Queen:
		os << "Q";
		break;

	case Rank::King:
		os << "K";
		break;

	case Rank::Ace:
		os << "A";
		break;

	default:
		os << "";
	}

	return os;
};

static std::ostream& operator<<(std::ostream& os, const Suit& suit)
{
	switch(suit)
	{
	case Suit::Spade:
		os << "S";
		break;

	case Suit::Heart:
		os << "H";
		break;

	case Suit::Club:
		os << "C";
		break;

	case Suit::Diamond:
		os << "D";
		break;
	}

	return os;
}

static std::ostream& operator<<(std::ostream& os, const Card& card)
{
	os << card.rank << card.suit << ' ';

	return os;
};

enum class HandName
{
	HighCard,
	OnePair,
	TwoPairs,
	ThreeOfAKind,
	Straight,
	Flush,
	FullHouse,
	FourOfAKind,
	StraightFlush,
	RoyalFlush
};

class Hand
{
	public:
		Hand(std::vector<Card> cards): cards(cards)
		{
			init_hand();
		};

		bool is_same_suit();
		bool is_consequtive();
		auto operator<=>(const Hand& other) const
		{
			if(auto cmp = name <=> other.name; cmp != 0)
				return cmp;
			else
				return cards <=> other.cards;
		}

		void print();
		HandName name;
	private:
		void init_hand();
		std::unordered_map<Rank, unsigned> rank_count;
		std::vector<Card> cards;
		unsigned long score{};
};

class Solution
{
	public:
		void read_hands();
		std::vector<Hand> hands;
		void answer();
		std::unordered_map<char, Suit> csmap;
		std::unordered_map<char, Rank> crmap;

};
