#include <stringint.h>
#include <gtest/gtest.h>

TEST(sint, init)
{
	StringInt a;
	StringInt b(581501314);
	StringInt c("581098108480318043108431");

	std::cout << "a " << a << std::endl;
	std::cout << "b " << b << std::endl;
	std::cout << "c " << c << std::endl;
}

TEST(sint, addition)
{
	EXPECT_EQ(StringInt("333") + 5, 338);
	EXPECT_EQ(8 + StringInt("333"), 341);
	EXPECT_EQ(888 + StringInt("333"), 1221);
}

TEST(sint, multiply)
{
	EXPECT_EQ(StringInt("333") * 5, 1665);
	EXPECT_EQ(StringInt("333") * 44, 14652);
	EXPECT_EQ(StringInt("333") * 0, 0);
}

TEST(sint, power)
{
	EXPECT_EQ(StringInt(0).power(1000), 0);
	EXPECT_EQ(StringInt(13414).power(0), 1);
	EXPECT_EQ(StringInt(2).power(10), 1024);
}

TEST(sint, sum_of_digits)
{
	EXPECT_EQ(StringInt(123456789).sum_of_digits(), 45);
}

TEST(sint, factorial)
{
	EXPECT_EQ(StringInt(10).factorial(), 3628800);
}
