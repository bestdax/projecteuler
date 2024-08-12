#include "number.h"
#include "gtest/gtest.h"

using namespace dax;
TEST(number, isprime)
{
	EXPECT_TRUE(is_prime(2));
	EXPECT_TRUE(is_prime(5));
	EXPECT_FALSE(is_prime(4));
	EXPECT_FALSE(is_prime(99));
}

TEST(number, gcd)
{
	EXPECT_EQ(gcd(4, 8), 4);
	EXPECT_EQ(gcd(4, 12), 4);
}

TEST(number, lcm)
{
	EXPECT_EQ(lcm(12, 8), 24);
}

TEST(number, sieve_of_Eratosthenes)
{
	EXPECT_TRUE(sieve_of_Eratosthenes(10)[3]);
	EXPECT_TRUE(sieve_of_Eratosthenes(10)[2]);
	EXPECT_TRUE(sieve_of_Eratosthenes(10)[5]);
	EXPECT_TRUE(sieve_of_Eratosthenes(10)[7]);
	EXPECT_FALSE(sieve_of_Eratosthenes(10)[4]);
	EXPECT_FALSE(sieve_of_Eratosthenes(10)[6]);
	EXPECT_FALSE(sieve_of_Eratosthenes(10)[8]);
	EXPECT_FALSE(sieve_of_Eratosthenes(10)[9]);
	EXPECT_FALSE(sieve_of_Eratosthenes(10)[10]);
}

TEST(number, sieve_of_Euler)
{
	EXPECT_EQ(sieve_of_Euler(10)[3], 7);
}

TEST(number, abundant)
{
	EXPECT_TRUE(is_abundant(12));
}

TEST(number, pandigital)
{
	EXPECT_TRUE(is_pandigital(1234));
	EXPECT_TRUE(is_pandigital(51234));
	EXPECT_FALSE(is_pandigital(512534));
}
