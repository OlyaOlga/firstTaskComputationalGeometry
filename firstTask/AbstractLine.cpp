#include "AbstractLine.h"
#include <algorithm>


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

double AbstractLine::angleBetweenLines(AbstractLine* first, AbstractLine * second)
{
	double alpha_first = first->angleBetweenOXandLine();
	double alpha_second = second->angleBetweenOXandLine();
	AbstractLine* bigger_a = (first->get_a() > second->get_a()) ? first : second;
	return (alpha_first + alpha_second) / 2 + bigger_a->angleBetweenOXandLine();
}
