#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER05, LCM_OF_RANGE)
{
	EXPECT_EQ(solution.lcm_of_range(10), 2520);
}

TEST(EULER05, LCM)
{
	EXPECT_EQ(solution.lcm(2, 4), 4);
}

TEST(TOOLS, PRIME_FACTORS)
{
	std::vector<int> a{2};
	std::vector<int> b{2, 2};
	std::vector<int> c{5, 7, 13, 29};
	EXPECT_EQ(prime_factors(13195), c);
	EXPECT_EQ(prime_factors(2), a);
	EXPECT_EQ(prime_factors(4), b);

}

TEST(EULER05, LCM_OF_RANGE2)
{
	EXPECT_EQ(solution.lcm_of_range2(10), 2520);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

