#pragma once
#include <iostream>
#include <string>

class StringInt
{
	public:
		StringInt();
		StringInt(std::string);
		StringInt(uint64_t);
		void reverse();

	private:
		std::string data;
		friend std::ostream& operator<<(std::ostream&, const StringInt&);

};
