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
