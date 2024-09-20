#pragma once

class Solution
{
	private:
	unsigned dp[201] = {0};
		unsigned coins[8] {1, 2, 5, 10, 20, 50, 100, 200};
	public:
		Solution();
		void answer();

};
