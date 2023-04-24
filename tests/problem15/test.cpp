#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER15, LARGE_NUMBER_ADDITION)
{
	EXPECT_EQ(LargeNumber(5) + 5, LargeNumber(10));
	EXPECT_EQ(LargeNumber(5) - 5, LargeNumber(0));
	EXPECT_EQ(LargeNumber(5) - 1, LargeNumber(4));
}
TEST(EULER15, LARGE_NUMBER_LESS)
{
	LargeNumber a{1};
	LargeNumber b{999};
	LargeNumber c{-1};
	LargeNumber d{-100};
	EXPECT_FALSE(a > 100);
	EXPECT_TRUE(a != b);
	EXPECT_FALSE(c < d);
	EXPECT_TRUE(d == LargeNumber(-100));
}


int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
