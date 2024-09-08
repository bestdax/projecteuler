#include <gtest/gtest.h>
#include <numbertools.h>

TEST(prime, is_prime)
{
	EXPECT_TRUE(dax::is_prime(2));
	EXPECT_TRUE(dax::is_prime(3));
	EXPECT_TRUE(dax::is_prime(5));
	EXPECT_TRUE(dax::is_prime(7));
	EXPECT_TRUE(dax::is_prime(11));
	EXPECT_TRUE(dax::is_prime(13));
	EXPECT_TRUE(dax::is_prime(17));
	EXPECT_TRUE(dax::is_prime(19));
	EXPECT_TRUE(dax::is_prime(23));
	EXPECT_TRUE(dax::is_prime(29));
}

TEST(prime, is_prime_improved)
{
	EXPECT_TRUE(dax::is_prime_improved(2));
	EXPECT_TRUE(dax::is_prime_improved(3));
	EXPECT_TRUE(dax::is_prime_improved(5));
	EXPECT_TRUE(dax::is_prime_improved(7));
	EXPECT_TRUE(dax::is_prime_improved(11));
	EXPECT_TRUE(dax::is_prime_improved(13));
	EXPECT_TRUE(dax::is_prime_improved(17));
	EXPECT_TRUE(dax::is_prime_improved(19));
	EXPECT_TRUE(dax::is_prime_improved(23));
	EXPECT_TRUE(dax::is_prime_improved(29));
	EXPECT_TRUE(dax::is_prime_improved(97));
	EXPECT_TRUE(dax::is_prime_improved(101));
	EXPECT_FALSE(dax::is_prime_improved(91));
}
