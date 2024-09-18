#include <gtest/gtest.h>
#include <numutils.h>

TEST(numutils, is_palindrome)
{
	EXPECT_TRUE(dax::is_palindrome(11223432211));
	EXPECT_FALSE(dax::is_palindrome(1122344542211));
}

TEST(numutils, gcd)
{
	EXPECT_EQ(dax::gcd(48, 18), 6);
	EXPECT_EQ(dax::gcd(18, 48), 6);
}

TEST(numutils, lcm)
{
	EXPECT_EQ(dax::lcm(48, 18), 144);
}

TEST(numutils, factorial)
{
	EXPECT_EQ(dax::factorial(9), 362880);
}

TEST(numutils, pentagonal)
{
	EXPECT_FALSE(dax::is_pentagonal(20242));
}
