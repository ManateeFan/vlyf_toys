#include "Point.h"

Point::Point() : xValue(0), yValue(0)
{
}

Point::Point(int x, int y) : xValue(x), yValue(y)
{
}

int Point::x() const
{
	return xValue;
}

int Point::y() const
{
	return yValue;
}

Point& Point::x(int x)
{
	xValue = x;
	return *this;
}

Point& Point::y(int y)
{
	yValue = y;
	return *this;
}
