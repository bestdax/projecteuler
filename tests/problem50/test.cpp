#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER50, LONGEST)
{
	EXPECT_EQ(solution.consequtive_prime_sum(100), 41);
	EXPECT_EQ(solution.consequtive_prime_sum(1000), 953);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
