#include "Handle.h"

Handle::Handle() : up(new UPoint)
{
}

Handle::Handle(int x, int y) : up(new UPoint(x, y))
{
}

Handle::Handle(Point const& p) : up(new UPoint(p))
{
}

Handle::Handle(Handle const& h) : up(h.up)
{
	++up->u;
}

Handle::~Handle()
{
	if (--up->u == 0)
		delete up;
}

Handle& Handle::operator=(Handle const& h)
{
	++h.up->u;
	if (--up->u == 0)
		delete up;
	up = h.up;
	return *this;
}

int Handle::x() const
{
	return up->p.x();
}

int Handle::y() const
{
	return up->p.y();
}

Handle& Handle::x(int x)
{
	up->p.x(x);
	return *this;
}

Handle& Handle::y(int y)
{
	up->p.y(y);
	return *this;
}
