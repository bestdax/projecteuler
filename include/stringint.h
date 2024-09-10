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
		StringInt operator+(const StringInt& other)const;
		bool operator==(const StringInt& other) const;

	private:
		std::string data;
		friend std::ostream& operator<<(std::ostream&, const StringInt&);

};

StringInt operator+(const std::string&, const StringInt&);
StringInt operator+(uint64_t, const StringInt&);
