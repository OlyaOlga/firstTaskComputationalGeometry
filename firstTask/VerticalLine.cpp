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

void VerticalLine::drawLineByEquasion(Mat& field)
{
	line(field, Point(val, 0), Point(val, field.rows), Scalar(0));
}


VerticalLine::~VerticalLine()
{
}
