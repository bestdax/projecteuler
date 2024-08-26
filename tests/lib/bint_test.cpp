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

TEST(bint, digital_sum)
{
	EXPECT_EQ(bint(12345).digtal_sum(), bint(15));
}

TEST(bint, compare)
{
	EXPECT_TRUE(bint(12) > bint(5));
}

TEST(bint, power)
{
	EXPECT_EQ(bint(2).power(3), bint(8));
}

TEST(bint, middle)
{
	EXPECT_EQ(bint(1111111111111111111).middle(), 555555555555555555);
}

TEST(bint, subtract)
{
	EXPECT_EQ(bint(12345) - 33, 12312);
	EXPECT_EQ(bint((1 << 30)) - 1, 1073741823);
}

TEST(bint, divide)
{
	EXPECT_EQ(bint(123) / 4, 30);
	EXPECT_EQ(bint("999999999999999999999") / 314314314, 3181528665601);
	EXPECT_EQ(bint("99") / 3, 33);
}

TEST(bint, module)
{
	EXPECT_EQ(bint("999999999999999999999") % 314314314, 286287285);
}

TEST(bint, sqrt)
{
	EXPECT_EQ(bint("999999999999999999999").sqrt(), 31622776601);
}
