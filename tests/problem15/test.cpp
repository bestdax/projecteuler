#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler15, paths_in_grid)
{
	EXPECT_EQ(solution.paths_in_grid(2), 6);
}
