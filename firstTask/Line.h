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
	double angleBetweenOXandLine();
	void drawLineByEquasion(Mat& field);
	double get_a();
	~Line();
};

