#pragma once

class Point
{
private:
    int xValue = 0;
    int yValue = 0;

public:
    Point() = default;
    Point(int x, int y);

    int x() const;
    int y() const;

    Point& x(int x);
    Point& y(int y);
};

