#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int value;
	static const int bits = 8;
public :
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const &fixed);
	Fixed &operator=(Fixed const &fixed);
	~Fixed();
	
	bool operator>(Fixed const &fixed) const;
	bool operator<(Fixed const &fixed) const;
	bool operator>=(Fixed const &fixed) const;
	bool operator<=(Fixed const &fixed) const;
	bool operator==(Fixed const &fixed) const;
	bool operator!=(Fixed const &fixed) const;

	Fixed operator+(Fixed const &fixed) const;
	Fixed operator-(Fixed const &fixed) const;
	Fixed operator*(Fixed const &fixed) const;
	Fixed operator/(Fixed const &fixed) const;
	
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif // FIXED_HPP