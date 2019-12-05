#pragma once

#include "UPoint.h"

class Handle
{
private:
	UPoint* up;

public:
	Handle();
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

