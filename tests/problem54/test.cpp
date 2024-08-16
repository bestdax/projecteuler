#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

Hand h1({{Rank::Three, Suit::Heart}, {Rank::Two, Suit::Spade}, {Rank::Two, Suit::Spade}, {Rank::Two, Suit::Spade},
	{Rank::Two, Suit::Spade}});
Hand h2({{Rank::Two, Suit::Heart}, {Rank::Three, Suit::Spade}, {Rank::Four, Suit::Spade}, {Rank::Five, Suit::Spade},
	{Rank::Six, Suit::Spade}});
Hand h3({{Rank::Two, Suit::Heart}, {Rank::Two, Suit::Spade}, {Rank::Two, Suit::Spade}, {Rank::Four, Suit::Spade},
	{Rank::Four, Suit::Spade}});
Hand h4({{Rank::Two, Suit::Heart}, {Rank::Two, Suit::Spade}, {Rank::Four, Suit::Spade}, {Rank::Four, Suit::Spade},
	{Rank::Five, Suit::Spade}});
Hand h5({{Rank::Four, Suit::Heart}, {Rank::Four, Suit::Spade}, {Rank::Two, Suit::Spade}, {Rank::Six, Suit::Spade},
	{Rank::Five, Suit::Spade}});
