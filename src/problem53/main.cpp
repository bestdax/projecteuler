#include "problem.h"
#include <utils.h>

int main(int argc, char *argv[])
{
	Solution solution;

	measure_exe_time(&Solution::answer, &solution);
	measure_exe_time(&Solution::answer2, &solution);

	return 0;
}
