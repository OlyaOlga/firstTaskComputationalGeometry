#pragma once
#include "opencv2/imgproc.hpp"
using namespace cv;
class VerticalLine;
class Line;
class AbstractLine
{
public:

	AbstractLine();
	~AbstractLine();
	virtual double angleBetweenOXandLine() = 0;
	virtual double get_a() = 0;
	virtual double get_b() = 0;
	static void drawLine(Point first, Point second, Mat& mat);
	static double angleBetweenOXandBisector(AbstractLine* first, AbstractLine* second);
	virtual void drawLineByEquasion(Mat& field) = 0;
	virtual Point lines_intersection(Line* another_line)=0;
	virtual Point lines_intersection(VerticalLine* another_line) = 0;
	virtual Point lines_intersection(AbstractLine* another_line);

	virtual AbstractLine* find_perpendicular(Point p) = 0;
};

