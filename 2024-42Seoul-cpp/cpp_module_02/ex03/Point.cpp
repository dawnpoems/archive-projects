#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(int const x, int const y) : x(x), y(y)
{
}

Point::Point(float const x, float const y) : x(x), y(y)
{
}

Point::Point(Point const &point) : x(point.x), y(point.y)
{
}

Point &Point::operator=(Point const &point)
{
	this->x = point.x;
	this->y = point.y;
	return (*this);
}

Point::~Point()
{
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}





