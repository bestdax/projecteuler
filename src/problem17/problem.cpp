/*
Problem page link:
https://projecteuler.net/problem=17

dax 2024-08-02 23:46:44
*/
#include "problem.h"
#include <map>

std::string Solution::say_number(unsigned n)
{
	std::map<unsigned, std::string> nwmap;
	nwmap[0] = "";
	nwmap[1] = "one";
	nwmap[2] = "two";
	nwmap[3] = "three";
	nwmap[4] = "four";
	nwmap[5] = "five";
	nwmap[6] = "six";
	nwmap[7] = "seven";
	nwmap[8] = "eight";
	nwmap[9] = "nine";
	nwmap[10] = "ten";
	nwmap[11] = "eleven";
	nwmap[12] = "twelve";
	nwmap[13] = "thirteen";
	nwmap[14] = "fourteen";
	nwmap[15] = "fifteen";
	nwmap[16] = "sixteen";
	nwmap[17] = "seventeen";
	nwmap[18] = "eighteen";
	nwmap[19] = "nineteen";
	nwmap[20] = "twenty";
	nwmap[30] = "thirty";
	nwmap[40] = "forty";
	nwmap[50] = "fifty";
	nwmap[60] = "sixty";
	nwmap[70] = "seventy";
	nwmap[80] = "eighty";
	nwmap[90] = "ninety";
	nwmap[100] = "hundred";
	nwmap[1000] = "thousand";

	std::string say = "";

	if(n % 100 < 20) say += nwmap[n % 100];
	else say = nwmap[n - n / 100 * 100  - n % 10] + (n % 10 == 0 ? "" : " ") + nwmap[n % 10];

	if(n / 100) say = (n / 100 != 10 ? nwmap[n / 100] + " " + nwmap[100] : "") + (say != "" ? " and " : "") + say;

	if(n / 1000) say = nwmap[n / 1000] + " " + nwmap[1000] + say;

	return say;

}

void Solution::answer()
{
	int count{};
	std::string words{};

	for(int i = 1; i <= 1000; ++i)
		words += say_number(i), std::cout << say_number(i) << std::endl;

	for(auto p = words.begin(); p < words.end(); ++p)
		if(*p > 96 && *p < 123) ++count;

	std::cout << "The answer is: " << count << std::endl;
}
