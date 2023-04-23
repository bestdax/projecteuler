#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER08, LARGEST_PRODUCT)
{
	EXPECT_EQ(solution.largest_product(4), 5832);
}
int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
