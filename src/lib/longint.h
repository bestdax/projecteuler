#include <string>
#include <iostream>
#include <iomanip>

class lint
{
public:
	lint();
	lint(std::string digit_string);
	lint(long num);
	lint(const lint& other);
	lint operator+(const lint &other) const;
	lint& operator+=(const lint &other);
	lint operator-(const lint &other) const;
	lint& operator-();
	lint& operator-=(const lint &other);
	lint operator*(const lint &other) const;
	lint& operator*=(const lint &other);
	lint operator/(const lint &other) const;
	lint& operator/=(const lint &other);
	lint& operator=(const lint &other);
	friend std::ostream& operator<<(std::ostream& os, const lint& obj)
	{
		return os << obj.number();
	}
	~lint();

	bool operator<(const lint &other) const;
	bool operator<=(const lint &other) const;
	bool operator==(const lint &other) const;
	bool operator>(const lint &other) const;
	bool operator>=(const lint &other) const;
	bool operator!=(const lint &other) const;
	lint& operator--();
	lint operator--(int);
	lint& operator++();
	lint operator++(int);
	friend lint operator%(const lint &lhs, const lint &rhs);
	lint operator%=(const lint &other);


public:
	std::string number() const;
	unsigned size() const;
	lint factorial();
	lint power(unsigned n);
	lint digit_sum();
	bool is_palindrome();
	lint reverse();

private:
	bool borrow(unsigned index);
	void trim(); // trim zeros in the front;
	void set_number(std::string num_str);
	std::string _number;
	char sign;
	char get_digit(unsigned index) const;

};
