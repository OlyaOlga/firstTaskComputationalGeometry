#include "AbstractLine.h"
#include "opencv2/imgproc.hpp"
#include <algorithm>
#include<iostream>
#include"Line.h"
#include"VerticalLine.h"

using namespace cv;
using namespace std;
AbstractLine::AbstractLine()
{
}

AbstractLine::~AbstractLine()
{
}

void AbstractLine::drawLine(Point first, Point second, Mat & mat)
{	
		line(mat, first, second, Scalar(0));
}

double AbstractLine::angleBetweenOXandBisector(AbstractLine* first, AbstractLine * second)
{
	double alpha_first = abs((((int)first->angleBetweenOXandLine()) % 180));
	double alpha_second = abs(((int)second->angleBetweenOXandLine()) % 180);
	if (alpha_first == 0)
	{
		alpha_first = 180;
	}
	if (alpha_second == 0)
	{
		alpha_second = 180;
	}
	double t = (alpha_first + alpha_second) / 2;

	return t;
}

Point AbstractLine::lines_intersection(AbstractLine * another_line)
{
	Point res;
	Line* line = dynamic_cast<Line *>(another_line);
	if (line != nullptr)
	{
		res = lines_intersection(line);
	}
	else
	{
		VerticalLine* vLine = dynamic_cast<VerticalLine*>(another_line);
		res = lines_intersection(vLine);
	}
	return res;
}



