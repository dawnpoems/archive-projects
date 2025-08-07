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

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif // FIXED_HPP