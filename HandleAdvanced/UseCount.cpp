#include "UseCount.h"

UseCount::UseCount(UseCount const& u) :p(u.p)
{
	++* p;
}

bool UseCount::Only() const
{
	return *p == 1;
}

bool UseCount::Reattach(UseCount const& u)
{
	++* u.p;
	if (-- * p == 0)
	{
		delete p;
		p = u.p;
		return true;
	}
	return false;
}

bool UseCount::MakeOnly()
{
	if (*p == 1)
	{
		return false;
	}
	--* p;
	p = new int(1);
	return true;
}

UseCount::~UseCount()
{
	if (Only())
	{
		delete p;
	}
}
