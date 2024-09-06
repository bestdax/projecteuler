#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER38, PANDIGITAL_MULTIPLE)
{
	EXPECT_EQ(solution.pandigital_multiple(192), 192384576);
	EXPECT_EQ(solution.pandigital_multiple(9), 918273645);

}


