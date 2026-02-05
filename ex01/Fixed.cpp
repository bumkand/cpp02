#include "Fixed.hpp"

Fixed::Fixed() :
	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fbits;
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)(round(value * (1 << _fbits)));
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / ( 1 << _fbits));
}

int		Fixed::toInt(void) const
{
	return (_value >> _fbits);
}

std::ostream& operator<<(std::ostream& ost, const Fixed& other)
{
	//std::cout << "Copy assignment operator called (<<)" << std::endl;
	ost << other.toFloat();
	return ost;
}