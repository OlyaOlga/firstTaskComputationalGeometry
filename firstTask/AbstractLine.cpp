#include "AbstractLine.h"
#include "opencv2/imgproc.hpp"
#include <algorithm>
#include<iostream>

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
	double alpha_first = first->angleBetweenOXandLine();
	double alpha_second = second->angleBetweenOXandLine();
	
	AbstractLine* bigger_a = (first->angleBetweenOXandLine() > second->angleBetweenOXandLine()) ? first : second;
	double bigger_angle = bigger_a->angleBetweenOXandLine();

	return (abs(alpha_first - alpha_second)) / 2 + bigger_angle - (abs(alpha_first - alpha_second));
}
