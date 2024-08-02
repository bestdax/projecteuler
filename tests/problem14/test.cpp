#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler14, count)
{
	EXPECT_EQ(solution.count_terms_of_collaz_seq(13), 10);
}

