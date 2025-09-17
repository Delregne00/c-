#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	value = other.value;
}

Fixed::Fixed(const int value)
{
	this->value = value << FractionalBits;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * ( 1 << FractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->value = other.value;
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits()const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << FractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->value >> FractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->value > other.value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->value < other.value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->value >= other.value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->value <= other.value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->value == other.value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->value != other.value);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result.value = this->value + other.value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result.value = this->value - other.value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;

	result.value = this->value * other.value / (1 << FractionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;

	result.value = (this->value / other.value)	* ( 1 << FractionalBits);
	return (result);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->value += 256;
	return (temp);
}

Fixed	&Fixed::operator++()
{
	this->value += 256;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->value -= 1;
	return (temp);
}

Fixed	&Fixed::operator--()
{
	this->value -= 1;
	return (*this);
}

Fixed& Fixed::min(Fixed &one, Fixed &two)
{
	if (one.value > two.value)
		return(two);
	else
		return(one);
}

Fixed& Fixed::max(Fixed &one, Fixed &two)
{
	if (one.value > two.value)
		return(one);
	else
		return(two);
}

const Fixed& Fixed::min(const Fixed &one, const Fixed &two)
{
	if (one.value > two.value)
		return(two);
	else
		return(one);
}

const Fixed& Fixed::max(const Fixed &one, const Fixed &two)
{
	if (one.value > two.value)
		return(one);
	else
		return(two);
}
