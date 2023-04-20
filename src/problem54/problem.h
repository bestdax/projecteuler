#pragma once
#include <iostream>
#include <vector>
enum Rank
{
	Two = 1,
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

enum Suit
{
	Spade,
	Heart,
	Diamond,
	Club
};

class Card
{
public:
	Rank rank;
	Suit suit;
	Card(Rank r, Suit s);
	Card(const Card &other);
	bool operator<(const Card &other) const;
	unsigned get_value();
	friend std::ostream& operator<<(std::ostream &os, const Card &c);
};


enum class HandRank
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
};

class Hand
{
public:
	Hand(std::vector<Card> h);
	std::vector<Card> cards;
	bool is_consecutive();
	bool is_same_suit();
	HandRank handrank;
	unsigned comp_value;
	bool operator<(const Hand &other) const;
	friend std::ostream& operator<<(std::ostream &os, const Hand &h);
private:
	void compute_rank_and_value();
	unsigned count(const Card &c) const;
};

class Solution
{
public:
	Solution();
	void answer();
	std::vector<Hand> hands;

};
