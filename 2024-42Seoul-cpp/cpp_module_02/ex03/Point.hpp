#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	Fixed x;
	Fixed y;
public:
	Point();
	Point(int const x, int const y);
	Point(float const x, float const y);
	Point(Point const &point);
	Point &operator=(Point const &point);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};

#endif // POINT_HPP