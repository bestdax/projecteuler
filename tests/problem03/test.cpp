#include "gtest/gtest.h"
#include "problem.h"
#include "tools.h"

Solution solution;

TEST(EULER03, IS_PRIME)
{
	EXPECT_TRUE(is_prime(2));
	EXPECT_TRUE(is_prime(3));
	EXPECT_TRUE(is_prime(5));
	EXPECT_FALSE(is_prime(4));
	EXPECT_FALSE(is_prime(33));
}

TEST(EULER03, PRIME_FACTORS)
{
	std::vector<int> pf{5, 7, 13, 29};
	EXPECT_EQ(prime_factors(13195), pf);
}

TEST(EULER03, LARGEST_PRIME_FACTOR)
{
	EXPECT_EQ(solution.largest_prime_factor(13195), 29);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
