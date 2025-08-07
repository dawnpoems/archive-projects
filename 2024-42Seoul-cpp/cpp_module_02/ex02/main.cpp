#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout <<"1 > 2 :" << (Fixed(1) > Fixed(2)) << std::endl;
	std::cout <<"1 < 2 :" << (Fixed(1) < Fixed(2)) << std::endl;
	std::cout <<"1 >= 2 :" << (Fixed(1) >= Fixed(2)) << std::endl;
	std::cout <<"1 >= 1 :" << (Fixed(1) >= Fixed(1)) << std::endl;
	std::cout <<"1 <= 2 :" << (Fixed(1) <= Fixed(2)) << std::endl;
	std::cout <<"1 <= 1 :" << (Fixed(1) <= Fixed(1)) << std::endl;
	std::cout <<"1 == 2 :" << (Fixed(1) == Fixed(2)) << std::endl;
	std::cout <<"1 == 1 :" << (Fixed(1) == Fixed(1)) << std::endl;
	std::cout <<"1 != 2 :" << (Fixed(1) != Fixed(2)) << std::endl;
	std::cout <<"1 != 1 :" << (Fixed(1) != Fixed(1)) << std::endl;

	std::cout <<"1 + 2 :" << (Fixed(1) + Fixed(2)) << std::endl;
	std::cout <<"100 + 200 :" << (Fixed(100) + Fixed(200)) << std::endl;
	std::cout <<"2.05 + 1.05 :" << (Fixed(2.05f) + Fixed(1.05f)) << std::endl;

	std::cout <<"1 - 2 :" << (Fixed(1) - Fixed(2)) << std::endl;
	std::cout <<"100 - 200 :" << (Fixed(100) - Fixed(200)) << std::endl;
	std::cout <<"2.05 - 1.05 :" << (Fixed(2.05f) - Fixed(1.05f)) << std::endl;

	std::cout <<"1 * 2 :" << (Fixed(1) * Fixed(2)) << std::endl;
	std::cout <<"100 * 200 :" << (Fixed(100) * Fixed(200)) << std::endl;
	std::cout <<"2.05 * 1.05 :" << (Fixed(2.05f) * Fixed(1.05f)) << std::endl;

	std::cout <<"1 / 2 :" << (Fixed(1) / Fixed(2)) << std::endl;
	std::cout <<"100 / 3 :" << (Fixed(100) / Fixed(3)) << std::endl;
	std::cout <<"2.05 / 1.05 :" << (Fixed(2.05f) / Fixed(1.05f)) << std::endl;

	std::cout << "a : " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ :" << a++ << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "--a : " << --a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a-- : " << a-- << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "max(a, b) : " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a, b) : " << Fixed::min( a, b ) << std::endl;

	return 0;
}