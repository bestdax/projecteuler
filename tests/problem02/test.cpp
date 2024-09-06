#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler02, sum_of_even_fibonacci)
{
	EXPECT_EQ(solution.sum_of_even_fibonacci(100), 44);
}
