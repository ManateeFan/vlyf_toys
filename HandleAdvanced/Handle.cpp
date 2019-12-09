#include "Handle.h"



Handle::Handle(int x, int y) : p(new Point(x, y))
{
}

Handle::Handle(Point const& p) : p(new Point(p))
{
}

Handle::Handle(Handle const& h) : p(h.p), u(h.u)
{
}

Handle::~Handle()
{
	if (u.Only())
	{
		delete p;
	}
}

Handle& Handle::operator=(Handle const& h)
{
	if (u.Reattach(h.u))
	{
		delete p;
	}
	p = h.p;
	return *this;
}

int Handle::x() const
{
	return p->x();
}

int Handle::y() const
{
	return p->y();
}

Handle& Handle::x(int x)
{
	if (u.MakeOnly())
	{
		p = new Point(*p);
	}
	p->x(x);
	return *this;
}

Handle& Handle::y(int y)
{
	if (u.MakeOnly())
	{
		p = new Point(*p);
	}
	p->y(y);
	return *this;
}