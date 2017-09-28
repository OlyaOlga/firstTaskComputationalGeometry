#pragma once
#include "opencv2/imgproc.hpp"
#include"AbstractLine.h"
using namespace cv;
class Line:
	public AbstractLine
{
	double a;
	double b;
public:
	Line(double _a, double _b);
	Line(Point2f first, Point2f second);
	Line(double _x, double _y, double _angle);
	double angleBetweenOXandLine();
	void drawLineByEquasion(Mat& field);
	Point lines_intersection(Line* another_line);
	Point lines_intersection(VerticalLine* another_line);
	double get_a();
	double get_b();
    AbstractLine* find_perpendicular(Point p);

	~Line();
};

