#include "UPoint.h"

UPoint::UPoint() : u(1)
{
}

UPoint::UPoint(int x, int y) : p(x, y), u(1)
{
}

UPoint::UPoint(Point const& tp) : p(tp), u(1)
{
}
