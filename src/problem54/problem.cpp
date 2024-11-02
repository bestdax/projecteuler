/*
Problem page link:
https://projecteuler.net/problem=54

dax 2024-09-24 10:34:34
*/
#include "problem.h"
#include <unordered_map>
#include <algorithm>
#include <filesystem>
#include <fstream>

PokerHand::PokerHand(std::vector<Card> incards)
{
	cards = incards;

	std::unordered_map<Rank, uint> card_count;

	for(auto & card : cards)
	{
		++card_count[card.rank];
	}

	// 根据牌的张数来排序，如果张数相同则从大到小排列
	std::sort(cards.begin(), cards.end(), [&card_count](Card a, Card b)
	{
		if(card_count[a.rank] != card_count[b.rank])
			return card_count[a.rank] > card_count[b.rank];
		else
			return a.rank > b. rank;
	});

	// 计算手牌的name
	bool is_straight = true;
	bool is_flush = true;

	for(uint i = 0; i < 4; ++i)
	{
		if(static_cast<uint>(cards[i].rank) - static_cast<uint>(cards[i + 1].rank) != 1)
			is_straight = false;

		if(cards[i].suit != cards[i + 1].suit)
			is_flush = false;
	}

	if(is_flush && is_straight)
	{
		name = HandName::StraightFlush;
		return;
	}

	if(card_count[cards[0].rank] == 4)
	{
		name = HandName::FourOfAKind;
		return;
	}

	if(card_count[cards[0].rank] == 3 && card_count[cards[3].rank] == 2)
	{
		name = HandName::FullHouse;
		return;
	}

	if(is_flush)
	{
		name = HandName::Flush;
		return;
	}

	if(is_straight)
	{
		name = HandName::Straight;
		return;
	}

	if(card_count[cards[0].rank] == 3)
	{
		name = HandName::ThreeOfAKind;
		return;
	}

	if(card_count[cards[0].rank] == 2 && card_count[cards[2].rank] == 2)
	{
		name = HandName::TwoPairs;
		return;
	}

	if(card_count[cards[0].rank] == 2)
	{
		name = HandName::OnePair;
		return;
	}

	name = HandName::HighCard;
}

std::strong_ordering PokerHand::operator<=>(const PokerHand& other) const
{
	if(name != other.name)
		return name <=> other.name;
	else
	{
		for(uint i = 0; i < 5; ++i)
		{
			if(cards[i].rank != other.cards[i].rank)
				return cards[i].rank <=> other.cards[i].rank;
		}
	}

	return std::strong_ordering::equal;
}

void Solution::read_hands()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0054_poker.txt");

	std::ifstream file(p);

	if(!file.is_open())
		std::cout << "Open file error" << std::endl;

	std::string rank_str = "123456789TJQKA";
	std::unordered_map<char, Rank> rankmap;

	for(uint i = 0; i < rank_str.size(); ++i)
	{
		rankmap[rank_str[i]] = Rank(i);
	}

	std::string suit_str = "DCHS";
	std::unordered_map<char, Suit> suitmap;

	for(uint i = 0; i < 4; ++i)
	{
		suitmap[suit_str[i]] = Suit(i);
	}

	std::string card_str;
	std::vector<Card> cards;

	while(file >> card_str)
	{
		Card card{rankmap[card_str[0]], suitmap[card_str[1]]};
		cards.push_back(card);

		if(cards.size() == 5)
		{
			PokerHand hand(cards);
			hands.push_back(hand);
			cards.clear();
		}
	}
}

void Solution::answer()
{
	read_hands();
	uint count{};
	for(uint i = 0; i < hands.size(); i += 2)
	{
		if(hands[i] > hands[i+1])
			++count;
	}
	std::cout << "The answer is: " << count << std::endl;
}
