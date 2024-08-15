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

bool Hand::is_same_suit()
{
	for(auto c : cards)
	{
		if(c.s != cards.back().s) return false;
	}

	return true;
}

bool Hand::is_four_of_a_kind()
{
	return 	std::equal(cards.cbegin(), cards.cbegin() + 3, cards.cbegin() + 1) ||
	        std::equal(cards.cbegin() + 1, cards.cend() - 1, cards.cbegin() + 2);
}

bool Hand::is_full_house()
{
	return std::equal(cards.cbegin(), cards.cbegin() + 2, cards.cbegin() + 1) && cards[3].r == cards[4].r
	       ||
	       cards[0].r == cards[1].r &&  std::equal(cards.cbegin() + 2, cards.cend() - 1, cards.cbegin() + 3);
}

bool Hand::is_consequtive()
{
	for(int i = 1; i < 5; ++i)
	{
		if(cards[i].r - cards[i - 1].r != 1) return false;
	}

	return true;
}

void Hand::init_hand()
{
	std::sort(cards.begin(), cards.end());

	if
	(
	    cards[0].r == Rank::Ten &&
	    cards[1].r == Rank::Jack &&
	    cards[2].r == Rank::Queen &&
	    cards[3].r == Rank::King &&
	    cards[4].r == Rank::Ace &&
	    is_same_suit()
	)
		name = HandName::RoyalFlush;
	else if(is_consequtive() && is_same_suit())
		name = HandName::StraightFlush;
}

void Solution::answer()
{
	std::cout << "The answer is: " << "" << std::endl;
}
