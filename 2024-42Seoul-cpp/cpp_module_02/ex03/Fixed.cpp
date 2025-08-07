#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(int const value)
{
	this->value = value << Fixed::bits;
}

Fixed::Fixed(float const value)
{
	this->value = roundf(value * (1 << Fixed::bits));
}

Fixed::Fixed(const Fixed& other) 
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}


bool Fixed::operator>(const Fixed& other) const
{
	return (this->value > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->value != other.getRawBits());
}


Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed ret = Fixed();
	ret.setRawBits(this->value + other.getRawBits());
	return (ret);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed ret = Fixed();
	ret.setRawBits(this->value - other.getRawBits());
	return (ret);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed ret = Fixed();
	ret.setRawBits((this->value * other.getRawBits()) >> Fixed::bits);
	return (ret);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed ret = Fixed();
	ret.setRawBits((this->getRawBits() << Fixed::bits) / other.getRawBits());
	return (ret);
}

Fixed& Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->value++;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->value--;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}


int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << Fixed::bits));
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}