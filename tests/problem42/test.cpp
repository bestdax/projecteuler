#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler42, score)
{
	EXPECT_EQ(solution.calculate_name_score("SKY"), 55);
}

