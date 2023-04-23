#include "gtest/gtest.h"
#include "prime.h"
#include "longint.h"


// TEST(LINT, INIT)
// {
// 	EXPECT_STREQ((lint(5) + 6).number().c_str(), "11");
// 	EXPECT_STREQ(lint("-155").number().c_str(), "-155");
// 	EXPECT_STREQ(lint(lint(5)).number().c_str(), "5");
// }
// TEST(LINT, COMP)
// {
// 	EXPECT_FALSE(lint(99) > 100);
// 	EXPECT_TRUE(lint(99) == 99);
// 	EXPECT_TRUE(lint(15) < lint(50));
// 	EXPECT_FALSE(lint(50) < lint(15));
// 	EXPECT_FALSE(lint(15) == lint(50));
// 	EXPECT_FALSE(lint(88) > lint(100));
// 	EXPECT_TRUE(lint(50) > lint(15));
// 	EXPECT_TRUE(lint(1999) != -999);
// }

// TEST(LINT, ADDTION)
// {
// 	EXPECT_EQ(lint(3) + lint(5), 8);
// 	EXPECT_EQ(lint(3) + lint(-5), lint(-2));
// 	EXPECT_EQ(lint(-5) + lint(9), lint(4));
// 	EXPECT_EQ(lint(-5) + lint(-6), lint(-11));
// }

TEST(LINT, BORROW)
{
	std::string s= "1000010";
	auto it = s.rbegin() + 1;
	--(*it);
	std::cout << s << std::endl;
	lint l(100);
	EXPECT_TRUE(l.borrow(0));
	EXPECT_EQ(l, 99);
}

TEST(LINT, SUBTRUCTION)
{
	EXPECT_EQ(lint(3) - lint(5), -2);
	EXPECT_EQ(lint(-2) - lint(5), -7);
	EXPECT_EQ(lint(3) - lint(-5), 8);
	EXPECT_EQ(lint(-3) - lint(-5), 2);
	EXPECT_EQ(lint(50) - lint(5), 45);
}

// TEST(LINT, INCREAEMENT)
// {
// 	lint a{2};
// 	EXPECT_EQ(++a, 3);
// 	EXPECT_EQ(++a, 4);
// 	EXPECT_EQ(a++, 4);
// 	EXPECT_EQ(a, 5);
// }

// TEST(LINT, PLUS_MINUS_EQUAL)
// {
// 	lint a{3};
// 	a += 2;
// 	EXPECT_EQ(a, 5);
// 	a -= 3;
// 	EXPECT_EQ(a, 2);
// 	a -= 3;
// 	EXPECT_EQ(a, -1);
// }

// TEST(LINT, MULTIPLY)
// {
// 	EXPECT_EQ(lint(3) * lint(9), lint(27));
// 	EXPECT_EQ(lint(112) * 9, lint(1008));
// }

// TEST(LIB, LONGINT_FACTORAIL)
// {
// 	lint a;
// 	std::cout << a.factorial(40) << std::endl;
// 	EXPECT_EQ(a.factorial(3), 6);
// }

// TEST(LINT, DIVISION)
// {
// 	EXPECT_EQ(lint(50) / lint(5), lint(10));
// 	// EXPECT_EQ(lint(99) / 10, 9);
// }

// TEST(LIB, INIT)
// {
// 	lint a(5);
// 	// EXPECT_EQ(lint(5), 5);
// }




int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
