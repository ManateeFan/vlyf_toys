#pragma once

class Point
{
private:
	int xValue;
	int yValue;
public:
	Point();
	Point(int x, int y);

	int x() const;
	int y() const;

	Point& x(int x);
	Point& y(int y);
};

