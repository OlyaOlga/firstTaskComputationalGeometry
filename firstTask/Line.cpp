#include "Line.h"
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

double Line::angleBetweenOXandLine()
{
	return Computation::from_rad_to_degree(atan(a));
}

void Line::drawLineByEquasion(Mat & field)
{
	line(field, Point(0, b), Point(field.cols, a*field.cols+b), Scalar(0), 3);
}



double Line::get_a()
{
	return a;
}


Line::~Line()
{
}
