/*
Problem description:
Poker hands
Problem 54
In the card game poker, a hand consists of five cards and are ranked, from
lowest to highest, in the following way:

High Card: Highest value card.
One Pair: Two cards of the same value.
Two Pairs: Two different pairs.
Three of a Kind: Three cards of the same value.
Straight: All cards are consecutive values.
Flush: All cards of the same suit.
Full House: Three of a kind and a pair.
Four of a Kind: Four cards of the same value.
Straight Flush: All cards are consecutive values of same suit.
Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest
value wins; for example, a pair of eights beats a pair of fives (see example 1
below). But if two ranks tie, for example, both players have a pair of queens,
then highest cards in each hand are compared (see example 4 below); if the
highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:

Hand	 	Player 1	 	Player 2	 	Winner
1	 	5H 5C 6S 7S KD 2C 3S 8S 8D TD
Pair of Fives Pair of Eights Player 2
2	 	5D 8C 9S JS AC 2C 5C 7D 8S QH
Highest card Ace Highest card Queen Player 1
3	 	2D 9C AS AH AC 3D 6D 7D TD QD
Three Aces Flush with Diamonds Player 2
4	 	4D 6S 9H QH QC 3D 6D 7H QD QS
Pair of Queens Highest card Nine Player 1
Pair of Queens
Highest card Seven
5	 	2H 2D 4C 4D 4S
Full House
With Three Fours
        3C 3D 3S 9S 9D
Full House
with Three Threes
        Player 1
The file, poker.txt, contains one-thousand random hands dealt to two players.
Each line of the file contains ten cards (separated by a single space): the
first five are Player 1's cards and the last five are Player 2's cards. You can
assume that all hands are valid (no invalid characters or repeated cards), each
player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?

page link:
https://projecteuler.net/problem=54

dax 2023-05-26 14:22:40
*/
#include "problem.h"
#include <cmath>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

Card::Card(Rank r, Suit s): rank(r), suit(s) {}
unsigned Card::get_value()
{
	return static_cast<unsigned>(rank);
}

// comparason between cards' rank
bool Card::operator<(const Card &other) const
{
	return this->rank < other.rank;
}

std::ostream& operator<<(std::ostream &os, const Card &c)
{
	std::vector<std::string> ranks{"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
	std::vector<std::string> suits{"Spade", "Heart", "Diamond", "Club"};
	auto rank = ranks[static_cast<unsigned>(c.rank) - 1];
	auto suit = suits[static_cast<unsigned>(c.suit)];
	os << rank << " of " << suit << '\t';
	return os;
}

// constructor
Hand::Hand(std::vector<Card> c): cards(c)
{
	std::sort(cards.begin(), cards.end());
	compute_rank_and_value();
}

std::ostream& operator<<(std::ostream &os, const Hand &h)
{
	for(auto card : h.cards)
		std::cout << card;

	std::vector<std::string> handranks
	{
		"HighCard",
		"OnePair",
		"TwoPairs",
		"ThreeOfAKind",
		"Straight",
		"Flush",
		"FullHouse",
		"FourOfAKind",
		"StraightFlush",

	};
	std::cout << handranks[static_cast<unsigned>(h.handrank)] << std::endl;
	return os;
}


Card::Card(const Card &other): rank(other.rank), suit(other.suit)
{
}

bool Hand::is_same_suit()
{
	for(auto it = cards.begin() + 1; it != cards.end(); ++it)
	{
		if(it->suit != (it - 1)->suit) return false;
	}

	return true;
}

bool Hand::is_consecutive()
{
	for(auto it = cards.begin() + 1; it != cards.end(); ++it)
	{
		if(it->rank - (it - 1)->rank != 1) return false;
	}

	return true;
}

unsigned Hand::count(const Card &c) const
{
	return std::count_if(cards.begin(), cards.end(), [c](const Card & d)
	{
		return d.rank == c.rank;
	});
}

void Hand::compute_rank_and_value()
{
	// straight flush(including royal flush)
	if(is_consecutive() && is_same_suit())
	{
		handrank = HandRank::StraightFlush;
		comp_value = static_cast<int>(cards.back().rank);
		return;
	}

	// four of a kind
	unsigned cnt = count(cards.front());

	if(cnt == 4)
	{
		handrank = HandRank::FourOfAKind;
		comp_value = cards.front().get_value();
		return;
	}
	else
	{
		cnt = count(cards.back());

		if(cnt == 4)
		{
			handrank = HandRank::FourOfAKind;
			comp_value = cards.back().get_value();
			return;
		}
	}

	// full house
	if(count(cards.front()) + count(cards.back()) == 5)
	{
		handrank = HandRank::FullHouse;

		if(count(cards.front()) == 3) comp_value = cards.front().get_value();
		else comp_value = cards.back().get_value();

		return;
	}

	// flush
	if(is_consecutive())
	{
		handrank = HandRank::Flush;
		comp_value = cards.back().get_value();
		return;
	}

	// three of a kind
	if(count(cards[2]) == 3)
	{
		handrank = HandRank::ThreeOfAKind;
		comp_value = cards[2].get_value();
		return;
	}

	// check two pairs, one pair, and high card
	unsigned pair_count{};
	unsigned pair_rank{};
	unsigned pair_value;
	unsigned single_card_count{};
	unsigned single_card_value;

	for(unsigned i = Two; i <= Ace; ++i)
	{
		Card c(static_cast<Rank>(i), Suit::Club);

		// pair count and compute
		if(count(c) == 2)
		{
			pair_rank = i;
			pair_value += std::pow(13, 5 + pair_count) * pair_rank;
			++pair_count;
		}

		// single card count and compute
		if(count(c) == 1)
		{
			single_card_value += std::pow(13, single_card_count) * i;
			++single_card_count;
		}
	}

	// two pairs
	if(pair_count == 2)
	{
		handrank = HandRank::TwoPairs;
		comp_value = pair_value + single_card_value;
		return;
	}

	// one pair
	if(pair_count == 1)
	{
		handrank = HandRank::OnePair;
		comp_value = pair_value + single_card_value;
		return;
	}

	// high card
	if(pair_count == 0)
	{
		handrank = HandRank::HighCard;
		comp_value = single_card_value;
	}
}

bool Hand::operator<(const Hand &other) const
{
	if(this->handrank != other.handrank) return this->handrank < other.handrank;
	else
		return this->comp_value < other.comp_value;
}

Solution::Solution()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0054_poker.txt");
	std::fstream file(p);
	std::string line;
	std::map<char, Rank> rankmap;
	std::map<char, Suit> suitmap;
	std::string rank_chars = "23456789TJQKA";
	std::string suit_chars = "SHDC";

	for(unsigned i = 0; i < rank_chars.size(); ++i)
	{
		rankmap[rank_chars[i]] = static_cast<Rank>(i + 1);
	}

	for(unsigned i = 0; i < suit_chars.size(); ++i)
	{
		suitmap[suit_chars[i]] = static_cast<Suit>(i);
	}

	std::vector<Card> cards;

	if(file.is_open())
	{
		while(std::getline(file, line))
		{
			std::stringstream ss(line);
			std::string card;

			while(std::getline(ss, card, ' '))
			{
				auto rank = rankmap[card[0]];
				auto suit = suitmap[card[1]];
				Card c(rank, suit);
				cards.push_back(c);
			}
		}
	}

	for(auto it = cards.begin(); it != cards.end(); it += 5)
	{
		std::vector<Card> h(it, it + 5);
		Hand hand(h);
		hands.push_back(hand);
	}
}

void Solution::answer()
{
	unsigned count {};

	for(auto it = hands.begin(); it < hands.end() - 1; it += 2)
	{
		if(*(it + 1) < *it)
		{
			++count;
		}
	}

	std::cout << "The answer is: " << count << std::endl;
}
