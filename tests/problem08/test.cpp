#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler08, largest)
{
	EXPECT_EQ(solution.largest_product_of_adjacent_digits(4), 5832);
}

