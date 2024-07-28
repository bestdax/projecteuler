#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler02, sum_of_even_fib)
{
	EXPECT_EQ(solution.sum_of_even_fibs(100), 44);
}

