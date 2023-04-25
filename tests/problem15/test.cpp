#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER15, LARGE_NUMBER_ADDITION)
{
	EXPECT_EQ(Longint(5) + 5, Longint(10));
	EXPECT_EQ(Longint(5) - 5, Longint(0));
	EXPECT_EQ(Longint(5) - 1, Longint(4));
}
TEST(EULER15, LARGE_NUMBER_LESS)
{
	Longint a{1};
	Longint b{999};
	Longint c{-1};
	Longint d{-100};
	EXPECT_FALSE(a > 100);
	EXPECT_TRUE(a != b);
	EXPECT_FALSE(c < d);
	EXPECT_TRUE(d == Longint(-100));
}


int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
