#include "Line.h"
#include"VerticalLine.h"
#include "Computation.h"
#include<cmath>


Line::Line(double _a, double _b):
	a(_a),
	b(_b)
{
}

Line::Line(Point2f first, Point2f second)
{
	a = (second.y - first.y) / (second.x - first.x);
	b = first.y - a*first.x;
}

Line::Line(double _x, double _y, double _angle)
{
	a = tan(_angle*CV_PI / 180.0);
	b = _y - a*_x;
}

double Line::angleBetweenOXandLine()
{
	double res = Computation::from_rad_to_degree(atan(a));
	if (res < 0)
	{
		res = 180 + res;
	}
	return res;
}

void Line::drawLineByEquasion(Mat & field)
{
	line(field, Point(0, b), Point(field.cols, a*field.cols+b), Scalar(0,0,255), 3);
}

Point Line::lines_intersection(Line* another_line)
{
	Point2f res;
	res.x = (another_line->b - b) / (a - another_line->a);
	res.y = a*res.x + b;
	return res;
}

Point Line::lines_intersection(VerticalLine * another_line)
{
	Point2f res;
	res.x = another_line->get_val();
	res.y = a*res.x*b;
	return res;
}

double Line::get_a()
{
	return a;
}

double Line::get_b()
{
	return b;
}

AbstractLine* Line::find_perpendicular( Point p)
{
	if (a == 0)
	{
		return new VerticalLine(p.x);
	}
	double a_two = -1 / a;
	double b_two = p.y - a_two*p.x;
	return new Line(a_two, b_two);
}

Line::~Line()
{
}
