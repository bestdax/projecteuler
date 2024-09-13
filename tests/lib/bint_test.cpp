#include <gtest/gtest.h>
#include <bigint.h>

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
	EXPECT_EQ(BigUInt("31431535436426000000000") + BigUInt("91481535736429000000000"),BigUInt( "122913071172855000000000"));
}
