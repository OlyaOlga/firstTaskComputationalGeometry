#include "VerticalLine.h"



VerticalLine::VerticalLine(int _val):
	val(_val)
{
}

double VerticalLine::angleBetweenOXandLine()
{
	return 90.0;
}

double VerticalLine::get_a()
{
	return 0.0;
}

double VerticalLine::get_b()
{
	return 0.0;
}

void VerticalLine::drawLineByEquasion(Mat& field)
{
	line(field, Point(val, 0), Point(val, field.rows), Scalar(0));
}

int VerticalLine::get_val()
{
	return val;
}

Point VerticalLine::lines_intersection(Line * another_line)
{
	Point2f res;
	res.x = val;
	res.y = another_line->get_a()*res.x + another_line->get_b();
	return res;
}


Point VerticalLine::lines_intersection(VerticalLine * another_line)
{
	return Point(-1,-1);
}


AbstractLine * VerticalLine::find_perpendicular( Point p)
{
	return new Line(0, p.y);
}

VerticalLine::~VerticalLine()
{
}
