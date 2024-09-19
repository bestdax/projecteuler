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
}

TEST(bint, power)
{
	std::cout << BigUInt(17).power(1000) << std::endl;
	std::cout << StringInt(17).power(1000) << std::endl;
	EXPECT_EQ(BigUInt(2).power(3), 8);
}
