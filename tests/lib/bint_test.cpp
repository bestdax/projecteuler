#include <gtest/gtest.h>
#include <bigint.h>
#include <stringint.h>

TEST(bint, init)
{
	BigUInt b("000031431535436426");
}

TEST(bint, to_string)
{
	EXPECT_STREQ(BigUInt("000031431535436426").to_string().c_str(), "31431535436426");
}

TEST(bint, plus)
{
	EXPECT_EQ(BigUInt("31431535436426") + 3, 31431535436429);
	EXPECT_EQ(BigUInt("31431535436426000000000") + BigUInt("91481535736429000000000"), BigUInt("122913071172855000000000"));
}

TEST(bint, multiply)
{
	EXPECT_EQ(BigUInt("9876543210123456789") * BigUInt("1234567890987654321"),
	          BigUInt("12193263121170553265523548251112635269"));
	EXPECT_EQ(BigUInt(4478554083) * 2 + 1855077841, 10812186007);
}

TEST(bint, power)
{
	std::cout << BigUInt(17).power(1000) << std::endl;
	std::cout << StringInt(17).power(1000) << std::endl;
	EXPECT_EQ(BigUInt(2).power(3), 8);
}

TEST(bint, is_palindrome)
{
	EXPECT_TRUE(BigUInt(1122332211).is_palindrome());
}

TEST(bint, reverse)
{
	EXPECT_EQ(BigUInt(123).reverse(), 321);
}

TEST(bint, subtruct)
{
	EXPECT_EQ(BigUInt(123) - 49, 74);
	EXPECT_EQ(BigUInt(1233333333333333333) - 4999999999999, 1233328333333333334);
}

TEST(bint, digital_sum)
{
	EXPECT_EQ(BigUInt(123).digital_sum(), 6);
}

TEST(bint, length)
{
	EXPECT_EQ(BigUInt(123456789).length(), 9);
}
