#include "Fixed.hpp"

Fixed::Fixed() :
	_value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = value << _fbits;
}
Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>((roundf(value * (1 << _fbits))));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / ( 1 << _fbits));
}

int		Fixed::toInt(void) const
{
	return (_value / (1 << _fbits));
}

std::ostream& operator<<(std::ostream& ost, const Fixed& other)
{
	//std::cout << "Copy assignment operator called (<<)" << std::endl;
	ost << other.toFloat();
	return ost;
}

bool Fixed::operator>(const Fixed& other) const
{
	if (this->getRawBits() > other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed& other) const
{
	if (this->getRawBits() < other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
	if (this->getRawBits() >= other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed& other) const
{
	if (this->getRawBits() <= other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed& other) const
{
	if (this->getRawBits() == other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed& other) const
{
	if (this->getRawBits() != other.getRawBits())
		return true;
	else
		return false;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed	plus;

	plus.setRawBits(this->getRawBits() + other.getRawBits());
	return plus;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed	minus;

	minus.setRawBits(this->getRawBits() - other.getRawBits());
	return minus;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	multi;

	multi.setRawBits((static_cast<long long>(this->getRawBits()) * static_cast<long long>(other.getRawBits())) / (1 << _fbits));
	return multi;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	division;

	division.setRawBits((this->getRawBits() << _fbits) / other.getRawBits());
	return division;
}

Fixed& Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed& Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	plus;

	plus = *this;
	this->setRawBits(this->getRawBits() + 1);
	return plus;
}

Fixed Fixed::operator--(int)
{
	Fixed	minus;

	minus = *this;
	this->setRawBits(this->getRawBits() - 1);
	return minus;
}

Fixed& Fixed::min(Fixed& one, Fixed& two)
{
	if (one.getRawBits() < two.getRawBits())
		return one;
	else
		return two;
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two)
{
	if (one.getRawBits() < two.getRawBits())
		return one;
	else
		return two;
}

Fixed& Fixed::max(Fixed& one, Fixed& two)
{
	if (one.getRawBits() > two.getRawBits())
		return one;
	else
		return two;
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two)
{
	if (one.getRawBits() > two.getRawBits())
		return one;
	else
		return two;
}