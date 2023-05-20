#include "gtest/gtest.h"
#include "prime.h"
#include "longint.h"
#include "number.h"


TEST(LINT, INIT)
{
    EXPECT_STREQ((lint(5) + 6).number().c_str(), "11");
    EXPECT_STREQ(lint("-155").number().c_str(), "-155");
    EXPECT_STREQ(lint(lint(5)).number().c_str(), "5");
}
TEST(LINT, COMP)
{
    EXPECT_FALSE(lint(99) > 100);
    EXPECT_TRUE(lint(99) == 99);
    EXPECT_TRUE(lint(15) < lint(50));
    EXPECT_FALSE(lint(50) < lint(15));
    EXPECT_FALSE(lint(15) == lint(50));
    EXPECT_FALSE(lint(88) > lint(100));
    EXPECT_TRUE(lint(50) > lint(15));
    EXPECT_TRUE(lint(1999) != -999);
    EXPECT_TRUE(lint(710) >= 6);
    EXPECT_TRUE(lint() == lint(0));
    EXPECT_TRUE(lint() == 0);
}

TEST(LINT, UNARY_MINUS)
{
    EXPECT_EQ(-lint(5), -5);
    EXPECT_EQ(-(lint(5) + lint(8)), -13);
}

TEST(LINT, ADDTION)
{
    EXPECT_EQ(lint(3) + lint(5), 8);
    EXPECT_EQ(lint(3) + lint(-5), lint(-2));
    EXPECT_EQ(lint(-5) + lint(9), lint(4));
    EXPECT_EQ(lint(-5) + lint(-6), lint(-11));
}

TEST(LINT, TRIM)
{
    EXPECT_EQ(lint("00003"), 3);
}

// TEST(LINT, BORROW)
// {
// 	lint l(100);
// 	lint d(122);
// 	lint e(710);
// 	// EXPECT_TRUE(l.borrow(0));
// 	// EXPECT_EQ(l, 99);
// 	// EXPECT_TRUE(d.borrow(1));
// 	// EXPECT_EQ(d, 112);
// 	EXPECT_TRUE(e.borrow(1));
// 	EXPECT_EQ(e, 700);
// }

TEST(LINT, SUBTRUCTION)
{
    EXPECT_EQ(lint(3) - lint(5), -2);
    EXPECT_EQ(lint(-2) - lint(5), -7);
    EXPECT_EQ(lint(3) - lint(-5), 8);
    EXPECT_EQ(lint(-3) - lint(-5), 2);
    EXPECT_EQ(lint(50) - lint(5), 45);
    EXPECT_EQ(lint(710) - lint(6), 704);
}

TEST(LINT, INCREAEMENT)
{
    lint a{2};
    EXPECT_EQ(++a, 3);
    EXPECT_EQ(++a, 4);
    EXPECT_EQ(a++, 4);
    EXPECT_EQ(a, 5);
}
TEST(LINT, MODULUS)
{
    // EXPECT_EQ(lint(101) % 100, 1);
}

TEST(LINT, PLUS_MINUS_EQUAL)
{
    lint a{3}, b{1199};
    a += 2;
    EXPECT_EQ(a, 5);
    a -= 3;
    EXPECT_EQ(a, 2);
    a -= 3;
    EXPECT_EQ(a, -1);
    b += 3898;
    EXPECT_EQ(b, 5097);
    a = lint(710);
    a -= 6;
    EXPECT_EQ(a, 704);
}

TEST(LINT, MULTIPLY)
{
    EXPECT_EQ(lint(3) * lint(9), lint(27));
    EXPECT_EQ(lint(112) * 9, lint(1008));
}

TEST(LIB, LONGINT_FACTORAIL)
{
    lint a{3};
    EXPECT_EQ(a.factorial(), 6);
    EXPECT_EQ(lint(5).factorial(), 120);
}

TEST(LINT, DIVISION)
{
    EXPECT_EQ(lint(50) / lint(5), lint(10));
    EXPECT_EQ(lint(99) / 10, 9);
    EXPECT_EQ(lint(720) / lint(6), 120);
    EXPECT_EQ(lint(115577800) / 8899, 12987);
    EXPECT_EQ(lint(101) / 100, 1);
}

TEST(LINT, POWER)
{
    EXPECT_EQ(lint(2).power(15), 32768);
}

TEST(LINT, DIGIT_SUM)
{
    EXPECT_EQ(lint(32768).digit_sum(), 26);
    EXPECT_EQ(lint().digit_sum(), 0);
}

TEST(NUMBER, GET_DIGITS)
{
    std::vector<unsigned> d{1, 1, 1, 2, 3, 2, 3, 4};
    EXPECT_EQ(get_digits(11123234), d);
}

TEST(NUMBER, DIGITS_TO_NUMBER)
{
    std::vector<unsigned> d{1, 2, 3, 4, 5, 0};
    EXPECT_EQ(digits_to_number(d), 123450);
}

TEST(NUMBER, HAS_ZERO)
{
    EXPECT_TRUE(has_digit(112200, 0));
    EXPECT_FALSE(has_digit(123456, 0));
}

TEST(NUMBER, HAS_SAME_DIGIT)
{
    EXPECT_TRUE(has_same_digit(12345, 56789));
    EXPECT_FALSE(has_same_digit(12345, 6789));
}

TEST(NUMBER, CANCEL_SAME_DIGIT)
{
    std::vector<unsigned long> n{1, 3};
    std::vector<unsigned long> t{16, 3};
    EXPECT_EQ(cancel_same_digit(12456, 2345), t);
}

TEST(NUMBER, ROTATE)
{
    EXPECT_EQ(rotate(2345), 5234);
    EXPECT_EQ(rotate(5234), 4523);
    EXPECT_EQ(rotate(4523), 3452);
    EXPECT_EQ(rotate(3452), 2345);
}





int main(int argc, char *argv[])
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
