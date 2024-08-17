#include "bint.h"
#include <gtest/gtest.h>

TEST(bint, test)
{
	bint a("12345678901234567890");
	bint b("98765432109876543210");
	EXPECT_TRUE(a + b == bint("111111111011111111100"));
	EXPECT_TRUE(a * b == bint("1219326311370217952237463801111263526900"));
}
