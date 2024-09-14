#include "problem.h"
#include <utils.h>

int main(int argc, char *argv[])
{
	Solution solution;
	auto func = [&solution]()
	{
		solution.answer();
	};

	auto func_bint = [&solution]()
	{
		solution.answer_bint();
	};

	measure_exe_time(func);
	measure_exe_time(func_bint);
	return 0;
}
