#include "longint.h"

// default constructor
lint::lint()
{
	sign = '+';
	this->set_number("");
}
void lint::set_number(std::string num_str)
{
	this->_number = num_str;
	std::cout << "set number to: " << std::quoted(num_str) << std::endl;
}

lint::~lint()
{
}

// copy constructor
lint::lint(lint& other): _number(other._number), sign(other.sign)
{
	std::cout << "in copy constructor, set number to " << *this << std::endl;
}


// construct with std::string
lint::lint(std::string digit_string)
{
	if(digit_string.starts_with('-'))
	{
		sign = '-';
		this->set_number(digit_string.substr(1));
	}
	else if(digit_string.starts_with('+'))
	{
		sign = '+';
		this->set_number(digit_string.substr(1));
	}
	else
	{
		sign = '+';
		this->set_number(digit_string);
	}
}

// construct with number
lint::lint(long num)
{
	if(num < 0)
	{
		this->set_number(std::to_string(-num));
		this->sign = '-';
	}
	else
	{
		this->set_number(std::to_string(num));
		this->sign = '+';
	}
}

unsigned lint::size() const
{
	return this->_number.size();
}

lint& lint::operator++()
{
	*this = *this + 1;
	return *this;
}

lint lint::operator++(int)
{
	auto temp = *this;
	*this = *this + 1;
	return temp;
}

lint& lint::operator--()
{
	*this = *this - 1;
	return *this;
}

lint lint::operator--(int)
{
	auto temp = *this;
	*this = *this - 1;
	return temp;
}

lint& lint::operator+=(const lint& other)
{
	*this = *this + other;
	return *this;
}
lint& lint::operator-=(const lint& other)
{
	*this = *this - other;
	return *this;
}

lint& lint::operator*=(const lint &other)
{
	*this = *this * other;
	return *this;
}

// operator <
bool lint::operator<(const lint& other) const
{
	if(this->sign == '+' && other.sign == '+')
	{
		if(this->size() < other.size()) return true;

		if(this->size() == other.size())
		{
			for(unsigned i{}; i < this->size(); ++i)
			{
				if(*(this->_number.begin() + i) < (*(other._number.begin() + i))) return true;

				if(*(this->_number.begin() + i) > (*(other._number.begin() + i))) return false;
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

				if(*(this->_number.begin() + i) < * (other._number.begin() + i)) return false;
			}

			return false;
		}

		return false;
	}
}

// output number;
std::string lint::number() const
{
	if(this->_number.empty()) return "0";

	return this->sign == '-' ? this->sign + this->_number : this->_number;
}

// operator ==
bool lint::operator==(const lint &other) const
{
	if(this->_number == other._number && this->sign == other.sign) return true;
	else return false;
}

bool lint::operator>(const lint &other) const
{
	bool result;

	if(*this == other) result = false;
	else if(*this < other) result = false;
	else
		result =  true;

	return result;
}
bool lint::operator!=(const lint &other) const
{
	if(*this == other) return false;

	return true;
}

char lint::get_digit(unsigned index) const
{
	return index < this->size() ? *(this->_number.crbegin() + index) : '0';
}

lint lint::operator+(const lint& other) const
{
	std::cout << "In operator+" << std::endl;
	lint sum;

	if(this->sign == other.sign)
	{
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

		sum.sign = this->sign;
		return sum;
	}
	else
	{
		if(this->sign == '-')
		{
			lint temp(this->_number);
			sum = other - temp;
			return sum;
		}
		else
		{
			lint temp(this->_number);
			temp.sign = '+';
			sum = *this - temp;
			return sum;
		}
	}
}

bool lint::borrow(unsigned index)
{
	std::cout << *this << '\t' << index << std::endl;

	for(unsigned i = index; i < this->size(); ++i)
	{
		std::cout << "-----" <<  *this << std::endl;
		auto it = this->_number.rbegin() + i;

		if(this->get_digit(i) != '0')
		{
			std::cout << "upper" << std::endl;
			--(*it);
			return true;
		}
		else
		{
			std::cout << "lower" << std::endl;
			*it = '9';
		}
	}

	return false;
}

lint& lint::operator-()
{
	this->sign = this->sign == '-' ? '+' : '-';
	return *this;
}

// operator -
lint lint::operator-(const lint& other) const
{
	std::cout << "In operator-" << std::endl;
	std::cout << "*this: " << *this << std::endl;
	std::cout << "other: " << other << std::endl;
	lint difference;

	if(this->sign == '+' && other.sign == '-')
	{
		std::cout << "+-" << std::endl;
		lint temp(other._number);
		return *this + temp;
	}
	else if(this->sign == '-' && other.sign == '+')
	{
		std::cout << "--" << std::endl;
		lint temp(this->_number);
		return -(temp + other);
	}
	else if(this->sign == '-' && other.sign == '-')
	{
		std::cout << "--" << std::endl;
		lint temp1(this->_number);
		lint temp2(other._number);
		return temp2 - temp1;
	}

	// if this _number less than the other, reverse them and put a minus sign
	std::cout << "++" << std::endl;

	if(*this < other)
	{
		return -(other - *this);
	}

	// big _number minus small _number
	unsigned length = std::max(this->size(), other.size());
	std::cout << "contruct temp with this->_number: " << std::endl;
	lint temp(this->_number);

	for(unsigned i{}; i < length; ++i)
	{
		char char_digit_a = temp.get_digit(i);
		std::cout << "char_digit_a: " << char_digit_a << std::endl;
		char char_digit_b = other.get_digit(i);
		std::cout << "char_digit_b: " << char_digit_b << std::endl;
		int digit_diff = char_digit_a - char_digit_b;
		std::cout << "digit_diff: " << digit_diff << std::endl;

		if(digit_diff < 0 && temp.borrow(i + i))
		{
			digit_diff += 10;
		}

		char char_digit_diff = digit_diff + 48;
		std::cout << "char_digit_diff: " << char_digit_diff << std::endl;
		difference._number.insert(0, 1, char_digit_diff);
		std::cout << "difference: " << difference << std::endl;
	}

	std::cout << "difference: " << difference << std::endl;
	return difference;
}

lint lint::operator*(const lint &other) const
{
	lint product;
	lint count;
	lint multiplicand(this->_number);
	lint multiplier(this->_number);

	while(count < multiplier)
	{
		product += multiplicand;
		++count;
	}

	if(this->sign != other.sign) product.sign = '-';

	return product;
}

lint& lint::operator=(const lint& other)
{
	if(*this == other) return *this;

	this->set_number(other._number);
	this->sign = other.sign;
	return *this;
}

lint lint::operator/(const lint& other) const
{
	std::cout << "initializing quotient" << std::endl;
	lint quotient;
	std::cout << "initializing divident" << std::endl;
	lint divident(this->_number);
	std::cout << "initializing divisor" << std::endl;
	lint divisor(other._number);
	int count = 0;

	while(divident > divisor)
	{
		std::cout << "doing ++quotient" << std::endl;
		++quotient;
		std::cout << "doing divident -= divisor" << std::endl;
		divident -= divisor;
		count++;

		if(count > 4) break;

		std::cout << "divident: " << divident << std::endl;
		std::cout << divident << " > " << divisor << '\t' << (divident > divisor) << std::endl;
	}

	if(this->sign != other.sign) quotient.sign = '-';

	return quotient;
}

lint lint::factorial(unsigned n)
{
	lint f{1};

	for(unsigned i = 1; i <= n; ++i)
	{
		f *= i;
	}

	return f;
}
