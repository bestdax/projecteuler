#include "bint.h"
#include <gtest/gtest.h>

TEST(bint, test)
{
	bint a("12345678901234567890");
	bint b("98765432109876543210");
	EXPECT_TRUE(a + b == bint("111111111011111111100"));
	EXPECT_TRUE(a * b == bint("1219326311370217952237463801111263526900"));
}

TEST(bint, palindrome)
{
	bint a("11223344332211");
	EXPECT_TRUE(a.is_palindrome());
	EXPECT_FALSE(bint("12343321").is_palindrome());
}

TEST(bint, reverse)
{
	EXPECT_TRUE(bint(12345).reverse() == bint(54321));
}

TEST(bint, selfplus)
{
	bint a(13);
	a += bint(5);
	EXPECT_EQ(a, 18);
}
