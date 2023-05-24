#include "gtest/gtest.h"
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
	EXPECT_EQ(lint(101) % 100, 1);
	EXPECT_EQ(lint(102) % 100, 2);
	EXPECT_EQ(lint(103) % 100, 3);
	EXPECT_EQ(lint(104) % 100, 4);
	EXPECT_EQ(lint(105) % 100, 5);
	EXPECT_EQ(lint(106) % 100, 6);
	EXPECT_EQ(lint(107) % 100, 7);
	EXPECT_EQ(lint(108) % 100, 8);
	EXPECT_EQ(lint(109) % 100, 9);
	EXPECT_EQ(lint(110) % 100, 10);
	EXPECT_EQ(lint(111) % 100, 11);
	EXPECT_EQ(lint(112) % 100, 12);
	EXPECT_EQ(lint(113) % 100, 13);
	EXPECT_EQ(lint(114) % 100, 14);
	EXPECT_EQ(lint(115) % 100, 15);
	EXPECT_EQ(lint(116) % 100, 16);
	EXPECT_EQ(lint(117) % 100, 17);
	EXPECT_EQ(lint(118) % 100, 18);
	EXPECT_EQ(lint(119) % 100, 19);
	EXPECT_EQ(lint(120) % 100, 20);
	EXPECT_EQ(lint(121) % 100, 21);
	EXPECT_EQ(lint(122) % 100, 22);
	EXPECT_EQ(lint(123) % 100, 23);
	EXPECT_EQ(lint(124) % 100, 24);
	EXPECT_EQ(lint(125) % 100, 25);
	EXPECT_EQ(lint(126) % 100, 26);
	EXPECT_EQ(lint(127) % 100, 27);
	EXPECT_EQ(lint(128) % 100, 28);
	EXPECT_EQ(lint(129) % 100, 29);
	EXPECT_EQ(lint(130) % 100, 30);
	EXPECT_EQ(lint(131) % 100, 31);
	EXPECT_EQ(lint(132) % 100, 32);
	EXPECT_EQ(lint(133) % 100, 33);
	EXPECT_EQ(lint(134) % 100, 34);
	EXPECT_EQ(lint(135) % 100, 35);
	EXPECT_EQ(lint(136) % 100, 36);
	EXPECT_EQ(lint(137) % 100, 37);
	EXPECT_EQ(lint(138) % 100, 38);
	EXPECT_EQ(lint(139) % 100, 39);
	EXPECT_EQ(lint(140) % 100, 40);
	EXPECT_EQ(lint(141) % 100, 41);
	EXPECT_EQ(lint(142) % 100, 42);
	EXPECT_EQ(lint(143) % 100, 43);
	EXPECT_EQ(lint(144) % 100, 44);
	EXPECT_EQ(lint(145) % 100, 45);
	EXPECT_EQ(lint(146) % 100, 46);
	EXPECT_EQ(lint(147) % 100, 47);
	EXPECT_EQ(lint(148) % 100, 48);
	EXPECT_EQ(lint(149) % 100, 49);
	EXPECT_EQ(lint(150) % 100, 50);
	EXPECT_EQ(lint(151) % 100, 51);
	EXPECT_EQ(lint(152) % 100, 52);
	EXPECT_EQ(lint(153) % 100, 53);
	EXPECT_EQ(lint(154) % 100, 54);
	EXPECT_EQ(lint(155) % 100, 55);
	EXPECT_EQ(lint(156) % 100, 56);
	EXPECT_EQ(lint(157) % 100, 57);
	EXPECT_EQ(lint(158) % 100, 58);
	EXPECT_EQ(lint(159) % 100, 59);
	EXPECT_EQ(lint(160) % 100, 60);
	EXPECT_EQ(lint(161) % 100, 61);
	EXPECT_EQ(lint(162) % 100, 62);
	EXPECT_EQ(lint(163) % 100, 63);
	EXPECT_EQ(lint(164) % 100, 64);
	EXPECT_EQ(lint(165) % 100, 65);
	EXPECT_EQ(lint(166) % 100, 66);
	EXPECT_EQ(lint(167) % 100, 67);
	EXPECT_EQ(lint(168) % 100, 68);
	EXPECT_EQ(lint(169) % 100, 69);
	EXPECT_EQ(lint(170) % 100, 70);
	EXPECT_EQ(lint(171) % 100, 71);
	EXPECT_EQ(lint(172) % 100, 72);
	EXPECT_EQ(lint(173) % 100, 73);
	EXPECT_EQ(lint(174) % 100, 74);
	EXPECT_EQ(lint(175) % 100, 75);
	EXPECT_EQ(lint(176) % 100, 76);
	EXPECT_EQ(lint(177) % 100, 77);
	EXPECT_EQ(lint(178) % 100, 78);
	EXPECT_EQ(lint(179) % 100, 79);
	EXPECT_EQ(lint(180) % 100, 80);
	EXPECT_EQ(lint(181) % 100, 81);
	EXPECT_EQ(lint(182) % 100, 82);
	EXPECT_EQ(lint(183) % 100, 83);
	EXPECT_EQ(lint(184) % 100, 84);
	EXPECT_EQ(lint(185) % 100, 85);
	EXPECT_EQ(lint(186) % 100, 86);
	EXPECT_EQ(lint(187) % 100, 87);
	EXPECT_EQ(lint(188) % 100, 88);
	EXPECT_EQ(lint(189) % 100, 89);
	EXPECT_EQ(lint(190) % 100, 90);
	EXPECT_EQ(lint(191) % 100, 91);
	EXPECT_EQ(lint(192) % 100, 92);
	EXPECT_EQ(lint(193) % 100, 93);
	EXPECT_EQ(lint(194) % 100, 94);
	EXPECT_EQ(lint(195) % 100, 95);
	EXPECT_EQ(lint(196) % 100, 96);
	EXPECT_EQ(lint(197) % 100, 97);
	EXPECT_EQ(lint(198) % 100, 98);
	EXPECT_EQ(lint(199) % 100, 99);
	EXPECT_EQ(lint(200) % 100, 0);
	lint a = 105;
	a %= 100;
	EXPECT_EQ(a, 5);
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

TEST(NUMBER, CONCATENATE)
{
	EXPECT_EQ(concatenate(123, 456), 123456);
}

TEST(NUMBER, HAS_SAME_DIGIT2)
{
	EXPECT_TRUE(has_same_digit(11));
	EXPECT_FALSE(has_same_digit(2345));
}

TEST(NUMBER, IS_N_PANDIGITAL)
{
	EXPECT_TRUE(is_n_pandigital(1234));
	EXPECT_TRUE(is_n_pandigital(23451));
	EXPECT_TRUE(is_n_pandigital(987654321));
	EXPECT_TRUE(is_n_pandigital(56813247));
	EXPECT_FALSE(is_n_pandigital(2345));
	EXPECT_FALSE(is_n_pandigital(1223));
	EXPECT_FALSE(is_n_pandigital(34567));
	EXPECT_FALSE(is_n_pandigital(654327));
}


TEST(NUMBER, IS_TRIANGLE_NUMBER)
{
	EXPECT_TRUE(is_triangle_number(1));
	EXPECT_TRUE(is_triangle_number(3));
	EXPECT_TRUE(is_triangle_number(6));
	EXPECT_TRUE(is_triangle_number(10));
	EXPECT_TRUE(is_triangle_number(15));
	EXPECT_TRUE(is_triangle_number(21));
	EXPECT_TRUE(is_triangle_number(28));
	EXPECT_TRUE(is_triangle_number(36));
	EXPECT_TRUE(is_triangle_number(45));
	EXPECT_TRUE(is_triangle_number(55));
	EXPECT_FALSE(is_triangle_number(2));
	EXPECT_FALSE(is_triangle_number(56));
}

TEST(NUMBER, IS_PENTAGONAL_NUMBER)
{
	EXPECT_TRUE(is_pentagonal_number(1));
	EXPECT_TRUE(is_pentagonal_number(5));
	EXPECT_TRUE(is_pentagonal_number(12));
	EXPECT_TRUE(is_pentagonal_number(22));
	EXPECT_TRUE(is_pentagonal_number(35));
	EXPECT_TRUE(is_pentagonal_number(51));
	EXPECT_TRUE(is_pentagonal_number(70));
	EXPECT_TRUE(is_pentagonal_number(92));
	EXPECT_TRUE(is_pentagonal_number(117));
	EXPECT_TRUE(is_pentagonal_number(145));
}

TEST(NUMBER, IS_HEXAGONAL_NUMBER)
{
	EXPECT_TRUE(is_hexagonal_number(1));
	EXPECT_TRUE(is_hexagonal_number(6));
	EXPECT_TRUE(is_hexagonal_number(15));
	EXPECT_TRUE(is_hexagonal_number(28));
	EXPECT_TRUE(is_hexagonal_number(45));
}


int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
