#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER15, LARGE_NUMBER_ADDITION)
{
	LargeNumber a{1};
	LargeNumber b{999};
	LargeNumber c{-1};
	LargeNumber d{-100};
	auto e = b + d;
	auto f = c - d;
	auto g = b - d;
	auto h = a + 5;
	EXPECT_EQ((e - 1), LargeNumber(898));
	EXPECT_EQ(f, LargeNumber(-101));
	EXPECT_EQ(g, LargeNumber(1099));
	EXPECT_EQ(h, LargeNumber(6));
}
TEST(EULER15, LARGE_NUMBER_LESS)
{
	LargeNumber a{1};
	LargeNumber b{999};
	LargeNumber c{-1};
	LargeNumber d{-100};
	EXPECT_FALSE(a > b);
	EXPECT_TRUE(a != b);
	EXPECT_FALSE(c < d);
	EXPECT_TRUE(d == LargeNumber(-100));
}


int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
