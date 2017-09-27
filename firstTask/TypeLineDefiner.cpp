#include "TypeLineDefiner.h"



TypeLineDefiner::TypeLineDefiner()
{
}


TypeLineDefiner::~TypeLineDefiner()
{
}

AbstractLine* TypeLineDefiner::DefineType(Point first, Point second)
{
	if (first.x == second.x)
	{
		return new VerticalLine(first.x);
	}
	else
	{
		return new Line(first, second);
	}
}

AbstractLine * TypeLineDefiner::DefineType(double _x, double _y, double _angle)
{
	if (_angle == 90)
	{
		return new VerticalLine(_x);
	}
	else
	{
		return new Line(_x, _y, _angle);
	}
}

