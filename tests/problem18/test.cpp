#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER18, FIND_MAX_PARENT)
{
	EXPECT_EQ(solution.find_max_parent(0,0), 0);
	EXPECT_EQ(solution.find_max_parent(2,1), 95);
	EXPECT_EQ(solution.find_max_parent(14,0), 63);
}


