#pragma once
#include <vector>
#include <compare>

enum class HandName
{
	HighCard, OnePair, TwoPairs, ThreeOfAKind, Straight, Flush, FullHouse, FourOfAKind, StraightFlush
};

enum class Suit
{
	Diamond, Club, Heart, Spade
};

enum class Rank
{
	One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
};

struct Card
{
	Rank rank;
	Suit suit;
};

class PokerHand
{
	private:
		std::vector<Card> cards;
		HandName name;
	public:
		PokerHand(std::vector<Card>);
		std::strong_ordering operator<=>(const PokerHand& other) const;

};

class Solution
{
	private:
		std::vector<PokerHand> hands;
	public:
		void read_hands();
		void answer();

};
