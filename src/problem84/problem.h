#pragma once
#include <utils.h>
#include <vector>
#include <queue>
#include <random>
#include <unordered_map>
#include <utility>

class Solution
{
	private:
		std::queue<std::string> cc_cards;
		std::queue<std::string> ch_cards;
		std::vector<std::string> board;
		std::mt19937 gen;
		std::unordered_map<std::string, uint> positions;
		std::unordered_map<std::string, uint> counter;
	public:
		Solution();
		std::pair<uint, uint> roll_dices(uint faces = 6, uint number = 2);
		std::string draw_card(std::queue<std::string>& cards);
		void simulate_monopoly();
		void answer();

};
