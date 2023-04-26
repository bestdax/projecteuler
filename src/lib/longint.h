#include <string>
#include <iostream>
#include <iomanip>

class lint
{
public:
	lint();
	lint(std::string digit_string);
	lint(long num);
	lint(lint& other);
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
	bool operator==(const lint &other) const;
	bool operator>(const lint &other) const;
	bool operator!=(const lint &other) const;
	lint& operator--();
	lint operator--(int);
	lint& operator++();
	lint operator++(int);


public:
	std::string number() const;
	unsigned size() const;
	lint factorial(unsigned n);
	bool borrow(unsigned index);

private:
	void set_number(std::string num_str);
	std::string _number;
	char sign;
	char get_digit(unsigned index) const;

};
