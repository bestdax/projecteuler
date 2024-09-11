#include "problem.h"
#include <utils.h>

int main(int argc, char *argv[])
{
	Solution solution;
	auto func = [&solution]()
	{
		solution.answer();
	};

	measure_exe_time(func);
	return 0;
}
