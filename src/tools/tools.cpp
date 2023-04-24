#include "tools.h"
#include <iostream>

bool is_prime(long number)
{
	if(number < 2) return false;

	int root = std::round(std::sqrt(number));

	for(int i = 2; i <= root; i++)
	{
		if(number % i == 0) return false;
	}

	return true;
}

std::vector<int> prime_factors(long number)
{
	std::vector<int> pf{};

	if(number < 2) return pf;

	for(int i = 2; i <= number; ++i)
	{
		if(is_prime(i) && number % i == 0)
		{
			pf.push_back(i);
			number /= i;
			i = 1;
		}
	}

	return pf;
}

// default constructor
LargeNumber::LargeNumber()
{
	sign = '+';
	_number = "0";
	size = 1;
}

// construct with std::string
LargeNumber::LargeNumber(std::string digit_string)
{
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

	size = _number.size();
}

// construct with number
LargeNumber::LargeNumber(long num)
{
	if(num < 0)
	{
		_number = std::to_string(-num);
		sign = '-';
		size = _number.size();
	}
	else
	{
		_number = std::to_string(num);
		size = _number.size();
		sign = '+';
	}
}

// operator <
bool LargeNumber::operator<(const LargeNumber& other) const
{
	if(this->sign == '+' && other.sign == '+')
	{
		if(this->size < other.size) return true;

		if(this->size == other.size)
		{
			for(unsigned i{}; i < this->size; ++i)
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
		if(this->size > other.size) return true;

		if(this->size == other.size)
		{
			for(unsigned i{}; i < this->size; ++i)
			{
				if(*(this->_number.begin() + i) > * (other._number.begin() + i)) return true;
			}

			return false;
		}

		return false;
	}
}

// output number;
std::string LargeNumber::number() const
{
	return this->sign + this->_number;
}

// operator ==
bool LargeNumber::operator==(const LargeNumber &other) const
{
	if(this->_number == other._number && this->sign == other.sign) return true;
	else return false;
}

bool LargeNumber::operator>(const LargeNumber &other) const
{
	if(!(*this == other || *this < other)) return true;

	return false;
}
bool LargeNumber::operator!=(const LargeNumber &other) const
{
	if(*this == other) return false;

	return true;
}

char LargeNumber::get_digit(unsigned index) const
{
	return index < this->size ? *(this->_number.crbegin() + index) : '0';
}

LargeNumber LargeNumber::operator+(const LargeNumber& other) const
{
	LargeNumber sum{""};

	if(other.sign == '-')
	{
		auto temp = other;
		temp.sign = '+';
		sum = *this - temp;
		return sum;
	}

	unsigned length = std::max(this->size, other.size);
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

bool LargeNumber::borrow(unsigned index)
{
	for(unsigned i = index; i < this->size; ++i)
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
LargeNumber LargeNumber::operator-(const LargeNumber& other) const
{
	LargeNumber difference{""};

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
	unsigned length = std::max(this->size, other.size);
	auto temp = *this;

	for(unsigned i{}; i < length; ++i)
	{
		std::cout << "here I am" << std::endl;
		std::cout << temp << " - " << other << std::endl;
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

LargeNumber LargeNumber::operator*(const LargeNumber &other) const
{
	LargeNumber product{""};

	if(this->sign != other.sign) product.sign = '-';
	else product.sign = '+';



	return product;
}
