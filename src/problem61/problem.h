#pragma once
#include <unordered_map>
#include <compare>

struct Polygon
{
	unsigned number;
	unsigned sides;

	bool operator==(const Polygon& other) const
	{
		return number == other.number && sides == other.sides;
	}

	std::strong_ordering operator<=>(const Polygon& other) const = default;
};

namespace std
{
	template <>
	struct hash<Polygon>
	{
		std::size_t operator()(const Polygon& p) const
		{
			std::size_t h1 = std::hash<unsigned>()(p.number);
			std::size_t h2 = std::hash<unsigned>()(p.sides);

			return h1 ^ (h2 << 1);
		}
	};
}

class Solution
{
	private:
		std::vector<Polygon> polygons;
		std::unordered_map<Polygon, std::vector<Polygon>> graph;
	public:
		Solution();
		bool is_cyclic(unsigned, unsigned);
		void answer();

};
