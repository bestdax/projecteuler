/*
Problem page link:
https://projecteuler.net/problem=54

dax 2024-08-15 15:22:56
*/
#include "problem.h"

int operator-(Rank& lhs, Rank& rhs)
{
	return int(lhs) - int(rhs);
}

void Hand::print()
{
	for(auto card: cards)
	{
		std::cout << card;
	}
}

bool Hand::is_same_suit()
{
	for(auto c : cards)
	{
		if(c.suit != cards.back().suit) return false;
	}

	return true;
}

bool Hand::is_consequtive()
{
	for(int i = 1; i < 5; ++i)
	{
		if(cards[i].rank - cards[i - 1].rank != 1) return false;
	}

	return true;
}

void Hand::init_hand()
{

	if(rank_count.empty())
	{
		for(auto card : cards)
		{
			++rank_count[card.rank];
		}
	}

	std::sort(cards.begin(), cards.end(), [&](const Card& a, const Card& b)
	{
		if(rank_count[a.rank] != rank_count[b.rank])
			return rank_count[a.rank] < rank_count[b.rank];
		else
			return a.rank < b.rank;
	});

	if(is_consequtive() && is_same_suit())
		name = HandName::StraightFlush;
	else if(rank_count[cards.back().rank] == 4)
		name = HandName::FourOfAKind;
	else if(rank_count[cards.front().rank] == 2 && rank_count[cards.back().rank] == 3)
		name = HandName::FullHouse;
	else if(is_same_suit())
		name = HandName::Flush;
	else if(is_consequtive())
		name = HandName::Straight;
	else if(rank_count[cards.back().rank] == 3)
		name = HandName::ThreeOfAKind;
	else if(rank_count[cards.back().rank] == 2 && rank_count[cards[2].rank] == 2)
		name = HandName::TwoPairs;
	else if(rank_count[cards.back().rank] == 2)
		name = HandName::OnePair;
	else
		name = HandName::HighCard;
}

void Solution::read_hands()
{

	csmap['C'] = Suit::Club;
	csmap['H'] = Suit::Heart;
	csmap['D'] = Suit::Diamond;
	csmap['S'] = Suit::Spade;
	crmap['2'] = Rank::Two;
	crmap['3'] = Rank::Three;
	crmap['4'] = Rank::Four;
	crmap['5'] = Rank::Five;
	crmap['6'] = Rank::Six;
	crmap['7'] = Rank::Seven;
	crmap['8'] = Rank::Eight;
	crmap['9'] = Rank::Nine;
	crmap['T'] = Rank::Ten;
	crmap['J'] = Rank::Jack;
	crmap['Q'] = Rank::Queen;
	crmap['K'] = Rank::King;
	crmap['A'] = Rank::Ace;
	std::filesystem::path p = __FILE__;
	p.replace_filename("0054_poker.txt");
	auto file = std::ifstream(p);

	if(!file.is_open()) std::cout << "Open file failed" << std::endl;

	std::string str_card;

	std::vector<Card> cards;

	while(std::getline(file, str_card, ' '))
	{
		Card card;
		card.rank = crmap[str_card[0]];
		card.suit = csmap[str_card[1]];
		cards.push_back(card);

		if(cards.size() == 5)
		{
			hands.push_back(Hand(cards));
			cards.clear();
		}
	}

}

void Solution::answer()
{
	read_hands();
	unsigned count{};

	for(auto it = hands.begin(); it < hands.end() - 1; it += 2)
	{
		if(*it > *(it + 1))
		{
			++count;
			it->print();
		 std::cout << std::endl;

		}
	}

	std::cout << "The answer is: " << count << std::endl;
}
