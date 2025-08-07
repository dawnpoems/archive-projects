#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int value;
	static const int bits = 8;
public :
	Fixed();
	Fixed(Fixed const &fixed);
	Fixed &operator=(Fixed const &fixed);
	~Fixed();
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif // FIXED_HPP