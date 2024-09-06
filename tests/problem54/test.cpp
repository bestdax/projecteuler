#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER54, CARD)
{
	Card c(Rank::Two, Suit::Club);
	Card d(Rank::Three, Suit::Heart);
	EXPECT_EQ(c.get_value(), 1);
	EXPECT_TRUE(c < d);
	EXPECT_FALSE(d < c);
}

TEST(HAND, IS_SAME_SUIT)
{
	Card c(Rank::Two, Suit::Club);
	Card d(Rank::Three, Suit::Club);
	Card e(Rank::Four, Suit::Club);
	Card f(Rank::Five, Suit::Club);
	Card g(Rank::Six, Suit:: Club);
	Card h(Rank::Ace, Suit::Heart);
	Card i(Rank::Seven, Suit::Club);
	Card j(Rank::King, Suit::Club);
	Hand hand(std::vector<Card> {c, d, e, f, g});
	Hand hand2(std::vector<Card> {c, d, e, f, h});
	Hand hand3(std::vector<Card> {d, e, f, g, i});
	Hand hand4(std::vector<Card> {c, d, e, f, j});
	EXPECT_TRUE(hand.is_same_suit());
	EXPECT_TRUE(hand.is_consecutive());
	EXPECT_FALSE(hand2.is_same_suit());
	EXPECT_FALSE(hand2.is_consecutive());
	EXPECT_EQ(hand.handrank, HandRank::StraightFlush);
	EXPECT_EQ(hand2.handrank, HandRank::HighCard);
	EXPECT_TRUE(hand < hand3);
	EXPECT_TRUE(hand2 < hand);
	EXPECT_TRUE(hand4 < hand2);
}

