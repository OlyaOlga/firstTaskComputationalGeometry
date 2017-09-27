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
