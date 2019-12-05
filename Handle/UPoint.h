#pragma once

#include "Point.h"

class UPoint
{
private:
	friend class Handle;
	Point p;
	int u;				//引用计数
	
	UPoint();
	UPoint(int x, int y);
	UPoint(Point const& p);
};

