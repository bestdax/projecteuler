#include "longint.h"

void Longint::print(std::string which)
{
	if(which == "number") std::cout << "created from number contructor" << std::endl;
	else if(which == "default") std::cout << "created from default constructor" << std::endl;
	else std::cout << "created from string constructor" << std::endl;

	std::cout << this << '\t' << *this << std::endl;
}
// default constructor
Longint::Longint()
{
	sign = '+';
	_number = "0";
}

Longint::~Longint()
{
	print("default");
	std::cout << this << '\t' << *this <<  "object destoried" << std::endl;
}

// construct with std::string
Longint::Longint(std::string digit_string)
{
	print("string");

	if(digit_string.starts_with('-'))
	{
		sign = '-';
		_number = digit_string.substr(1);
	}
	else if(digit_string.starts_with('+'))
	{
		sign = '+';
		_number = digit_string.substr(1);
	}
	else
	{
		sign = '+';
		_number = digit_string;
	}
}

// construct with number
Longint::Longint(long num)
{
	print("number");

	if(num < 0)
	{
		_number = std::to_string(-num);
		sign = '-';
	}
	else
	{
		_number = std::to_string(num);
		sign = '+';
	}
}

unsigned Longint::size() const
{
	return this->_number.size();
}

Longint& Longint::operator++()
{
	*this = *this + 1;
	return *this;
}

Longint Longint::operator++(int)
{
	auto temp = *this;
	*this = *this + 1;
	return temp;
}

Longint& Longint::operator--()
{
	*this = *this - 1;
	return *this;
}

Longint Longint::operator--(int)
{
	auto temp = *this;
	*this = *this - 1;
	return temp;
}

Longint& Longint::operator+=(const Longint& other)
{
	*this = *this + other;
	return *this;
}
Longint& Longint::operator-=(const Longint& other)
{
	*this = *this - other;
	return *this;
}


Longint& Longint::operator*=(const Longint &other)
{
	*this = *this * other;
	return *this;
}

// operator <
bool Longint::operator<(const Longint& other) const
{
	if(this->sign == '+' && other.sign == '+')
	{
		if(this->size() < other.size()) return true;

		if(this->size() == other.size())
		{
			for(unsigned i{}; i < this->size(); ++i)
			{
				if(*(this->_number.begin() + i) < * (other._number.begin() + i)) return true;
			}

			return false;
		}

		return false;
	}
	else if(this->sign == '+' && other.sign == '-')
	{
		return false;
	}
	else if(this->sign == '-' && other.sign == '+')
	{
		return true;
	}
	else
	{
		if(this->size() > other.size()) return true;

		if(this->size() == other.size())
		{
			for(unsigned i{}; i < this->size(); ++i)
			{
				if(*(this->_number.begin() + i) > * (other._number.begin() + i)) return true;
			}

			return false;
		}

		return false;
	}
}

// output number;
std::string Longint::number() const
{
	return this->sign + this->_number;
}

// operator ==
bool Longint::operator==(const Longint &other) const
{
	if(this->_number == other._number && this->sign == other.sign) return true;
	else return false;
}

bool Longint::operator>(const Longint &other) const
{
	if(!(*this == other || *this < other)) return true;

	return false;
}
bool Longint::operator!=(const Longint &other) const
{
	if(*this == other) return false;

	return true;
}

char Longint::get_digit(unsigned index) const
{
	return index < this->size() ? *(this->_number.crbegin() + index) : '0';
}

Longint Longint::operator+(const Longint& other) const
{
	Longint sum{""};

	if(other.sign == '-')
	{
		auto temp = other;
		temp.sign = '+';
		sum = *this - temp;
		return sum;
	}

	unsigned length = std::max(this->size(), other.size());
	bool carry = false;

	for(unsigned i{}; i < length; ++i)
	{
		char char_digit_a = this->get_digit(i);
		char char_digit_b = other.get_digit(i);
		char char_digit_sum = char_digit_a + char_digit_b - 48;

		if(carry) char_digit_sum++;

		carry = (char_digit_sum - 48) / 10;
		char_digit_sum = (char_digit_sum - 48) % 10 + 48;
		sum._number.insert(0, 1, char_digit_sum);
	}

	if(carry) sum._number.insert(0, 1, '1');

	return sum;
}

bool Longint::borrow(unsigned index)
{
	for(unsigned i = index; i < this->size(); ++i)
	{
		if(this->get_digit(i) != 0)
		{
			*(this->_number.rbegin() + i)--;
			return true;
		}
		else
		{
			*(this->_number.rbegin() + i) = '9';
			this->borrow(i + 1);
		}
	}

	return false;
}

// operator -
Longint Longint::operator-(const Longint& other) const
{
	Longint difference{""};

	// if this _number is minus, use addtion method and put a minus sign
	if(this->sign == '-')
	{
		difference = *this + other;
		difference.sign = '-';
		return difference;
	}

	// if the other _number is minus, use addtion method
	if(other.sign == '-')
	{
		auto temp = other;
		temp.sign = '+';
		difference = *this + temp;
		return difference;
	}

	// if this _number less than the other, reverse them and put a minus sign
	if(*this < other)
	{
		auto temp = other;
		difference = temp - *this;
		difference.sign = '-';
		return difference;
	}

	// big _number minus small _number
	unsigned length = std::max(this->size(), other.size());
	Longint temp{""};
	temp = *this;

	for(unsigned i{}; i < length; ++i)
	{
		char char_digit_a = temp.get_digit(i);
		char char_digit_b = other.get_digit(i);
		int digit_diff = char_digit_a - char_digit_b;

		if(digit_diff < 0 && temp.borrow(i + i))
		{
			digit_diff += 10;
		}

		char char_digit_diff = digit_diff + 48;
		difference._number.insert(0, 1, char_digit_diff);
	}

	return difference;
}

Longint Longint::operator*(const Longint &other) const
{
	Longint product{""};
	Longint count{""};
	Longint multiplicand = *this;
	multiplicand.sign = '+';
	Longint multiplier = other;
	multiplier.sign = '+';

	while(count < multiplier)
	{
		product += multiplicand;
		++count;
	}

	if(this->sign != other.sign) product.sign = '-';

	return product;
}

void Longint::operator=(const Longint& other)
{
	this->_number = other._number;
	this->sign = other.sign;
}

Longint Longint::operator/(const Longint& other) const
{
	Longint quotient{""};
	Longint divident = *this;
	divident.sign = '+';
	Longint divisor = other;
	divisor.sign = '+';
	// while(divident > divisor)
	{
		divident -= divisor;
		divident -= divisor;
		divident -= divisor;
		// quotient += 1;
	}

	if(this->sign != other.sign) quotient.sign = '-';

	return quotient;
}

Longint Longint::factorial(unsigned n)
{
	Longint f{1};

	for(unsigned i = 1; i <= n; ++i)
	{
		f *= i;
	}

	return f;
}
