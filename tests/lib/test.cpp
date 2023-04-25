#include "gtest/gtest.h"
#include "prime.h"
#include "longint.h"


// TEST(EULER15, LARGE_NUMBER_ADDITION)
// {
// 	EXPECT_EQ(Longint(5) + 5, Longint(10));
// 	EXPECT_EQ(Longint(5) - 5, Longint(0));
// 	EXPECT_EQ(Longint(5) - 1, Longint(4));
// }
// TEST(EULER15, LARGE_NUMBER_LESS)
// {
// 	Longint a{1};
// 	Longint b{999};
// 	Longint c{-1};
// 	Longint d{-100};
// 	EXPECT_FALSE(a > 100);
// 	EXPECT_TRUE(a != b);
// 	EXPECT_FALSE(c < d);
// 	EXPECT_TRUE(d == Longint(-100));
// }

// TEST(LIB, LONGINT_INCREAEMENT)
// {
// 	Longint a{2};
// 	EXPECT_EQ(++a, 3);
// 	EXPECT_EQ(++a, 4);
// 	EXPECT_EQ(a++, 4);
// 	EXPECT_EQ(a, 5);
// }

// TEST(LIB, LONGINT_PLUS_EQUAL)
// {
// 	Longint a{3};
// 	a += 2;
// 	EXPECT_EQ(a, 5);
// }

// TEST(LIB, LONGINT_MULTIPLY)
// {
// 	EXPECT_EQ(Longint(3) * Longint(9), Longint(27));
// 	EXPECT_EQ(Longint(112) * 9, Longint(1008));
// }

// TEST(LIB, LONGINT_FACTORAIL)
// {
// 	Longint a;
// 	std::cout << a.factorial(40) << std::endl;
// 	EXPECT_EQ(a.factorial(3), 6);
// }

// TEST(LIB, LONGINT_DIVISION)
// {
// 	EXPECT_EQ(Longint(25) / 5, 5);
// 	EXPECT_EQ(Longint(99) / 10, 9);
// }

TEST(LIB, INIT)
{
	Longint a(5);
	// EXPECT_EQ(Longint(5), 5);
}




int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
