/*
Problem page link:
https://projecteuler.net/problem=84

dax 2024-11-02 17:21:58
*/
#include "problem.h"
#include <algorithm>
#include <set>

Solution::Solution(): gen(std::random_device{}())
{
	std::vector<std::string> initial_cc_cards = {"GO", "JAIL", "STAY", "STAY", "STAY", "STAY", "STAY", "STAY", "STAY", "STAY", "STAY", "STAY", "STAY", "STAY", "STAY", "STAY"};

	std::shuffle(initial_cc_cards.begin(), initial_cc_cards.end(), gen);

	for(const auto& card : initial_cc_cards)
		cc_cards.push(card);

	std::vector<std::string> initial_ch_cards = {"GO", "JAIL", "C1", "E3", "H2", "R1", "NEXT_R", "NEXT_R", "NEXT_U", "BACK3", "STAY", "STAY", "STAY", "STAY", "STAY", "STAY"};

	std::shuffle(initial_ch_cards.begin(), initial_ch_cards.end(), gen);

	for(const auto& card : initial_ch_cards)
	{
		ch_cards.push(card);
	}

	board =
	{
		"GO", "A1", "CC1", "A2", "T1", "R1", "B1", "CH1", "B2", "B3",
		"JAIL", "C1", "U1", "C2", "C3", "R2", "D1", "CC2", "D2", "D3",
		"FP", "E1", "CH2", "E2", "E3", "R3", "F1", "F2", "U2", "F3",
		"G2J", "G1", "G2", "CC3", "G3", "R4", "CH3", "H1", "T2", "H2",
	};

	for(int i = 0; i < board.size(); ++i)
	{
		positions[board[i]] = i;
	}
}

std::pair<uint, uint> Solution::roll_dices(uint faces, uint number)
{
	std::uniform_int_distribution<> distrib(1, faces);

	return {distrib(gen), distrib(gen)};
}

std::string Solution::draw_card(std::queue<std::string>& cards)
{
	auto card = cards.front();
	cards.pop();
	cards.push(card);

	return card;
}

void Solution::simulate_monopoly()
{
	uint position = 0; // start from GO
	uint consecutive_doubles = 0;

	for(int turn = 0; turn < 5000'0000; ++turn)
	{
		auto dices = roll_dices(4);

		if(dices.first == dices.second)
		{
			++consecutive_doubles;

			if(consecutive_doubles == 3)
			{
				position = positions["JAIL"];
				consecutive_doubles = 0;
				++counter["JAIL"];
				continue;
			}

			continue;
		}
		else
			consecutive_doubles = 0;

		position = (position + dices.first + dices.second) % board.size();

		if(board[position] == "G2J") position = positions["JAIL"];
		else if(board[position].starts_with("CC"))
		{
			auto card = draw_card(cc_cards);

			if(card == "GO") position = positions[card];
			else if(card == "G2J") position = positions["JAIL"];
		}
		else if(board[position].starts_with("CH"))
		{
			auto card = draw_card(ch_cards);
			std::set<std::string> gotos{"GO", "C1", "E3", "H2", "R1"};

			if(card == "G2J") position = positions["JAIL"];
			else if(gotos.contains(card))
			{
				position = positions[card];

			}
			else if(card == "NEXT_R")
			{
				while(!board[position].starts_with("R"))
				{
					++position;
					position %= board.size();
				}
			}
			else if(card == "NEXT_U")
			{
				while(!board[position].starts_with("U"))
				{
					++position;
					position %= board.size();
				}
			}
			else if(card == "BACK3")
			{
				position  = (position + board.size() - 3) % board.size();
			}
		}

		++counter[board[position]];
	}
}

void Solution::answer()
{
	simulate_monopoly();
	print("The answer is:");

	uint total_visits = 0;

	for(const auto& [key, value] : counter)
	{
		total_visits += value;
	}

	std::vector<std::pair<std::string, double>> probabilities;

	for(const auto& [key, value] : counter)
	{
		double probability = static_cast<double>(value) / total_visits * 100;
		probabilities.push_back({key, probability});
	}

	std::sort(probabilities.begin(), probabilities.end(), [](const auto & a, const auto & b)
	{
		return a.second > b.second;
	});

	for(const auto& [name, probability] : probabilities)
	{
		std::cout << name << " " << positions[name] << " : " << probability << std::endl;
	}
}
