#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER15, PATH)
{
	EXPECT_EQ(solution.path_number(2), 6);
	EXPECT_EQ(solution.path_number(3), 20);
}


