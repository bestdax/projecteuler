#include "gtest/gtest.h"
#include "problem02.h"

Solution solution;
TEST(EULER02, FIBS)
{
	std::vector<int> fib10{1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	EXPECT_EQ(solution.fibs(89), fib10);
}

TEST(EULER02, SUM_OF_EVEN_FIBS)
{
	EXPECT_EQ(solution.sum_of_even_fibs(89), 44);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
