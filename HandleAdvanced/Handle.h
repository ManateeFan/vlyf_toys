#pragma once

#include "Point.h"
#include "UseCount.h"

class Handle
{
private:
	Point* p = new Point;
	UseCount u;
public:
	Handle() = default;
	Handle(int x, int y);
	Handle(Point const& p);
	Handle(Handle const& h);
	~Handle();

	Handle& operator=(Handle const& h);

	int x() const;
	int y() const;

	Handle& x(int x);
	Handle& y(int y);
};

