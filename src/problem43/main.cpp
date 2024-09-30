#include "problem.h"
#include <utils.h>

int main(int argc, char *argv[])
{
	Solution solution;
	auto func = [&solution]()
	{
		solution.answer();
	};

	auto func2 = [&solution]()
	{
		solution.answer2();
	};

	measure_exe_time(func);
	measure_exe_time(func2);
	return 0;
}
