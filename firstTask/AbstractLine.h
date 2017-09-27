#pragma once
#include "opencv2/imgproc.hpp"
using namespace cv;
class AbstractLine
{
public:

	AbstractLine();
	~AbstractLine();
	virtual double angleBetweenOXandLine() = 0;
	virtual double get_a() = 0;
	static void drawLine(Point first, Point second, Mat& mat);
	static double angleBetweenLines(AbstractLine* first, AbstractLine* second);
	virtual void drawLineByEquasion(Mat& field) = 0;
};

