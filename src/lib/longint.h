#include <string>
#include <iostream>

class Longint
{
public:
	Longint();
	Longint(std::string digit_string);
	Longint(long num);
	Longint operator+(const Longint &other) const;
	Longint& operator+=(const Longint &other);
	Longint operator-(const Longint &other) const;
	Longint& operator-=(const Longint &other);
	Longint operator*(const Longint &other) const;
	Longint& operator*=(const Longint &other);
	Longint operator/(const Longint &other) const;
	Longint& operator/=(const Longint &other);
	void operator=(const Longint &other);
	friend std::ostream& operator<<(std::ostream& os, const Longint& obj)
	{
		return os << obj.sign << obj._number;
	}
	~Longint();

	bool operator<(const Longint &other) const;
	bool operator==(const Longint &other) const;
	bool operator>(const Longint &other) const;
	bool operator!=(const Longint &other) const;
	Longint& operator--();
	Longint operator--(int);
	Longint& operator++();
	Longint operator++(int);


public:
	std::string number() const;
	unsigned size() const;
	Longint factorial(unsigned n);
	void print(std::string which);

private:
	std::string _number;
	char sign;
	char get_digit(unsigned index) const;
	bool borrow(unsigned index);

};
