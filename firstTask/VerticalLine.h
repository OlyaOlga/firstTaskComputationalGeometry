#pragma once
#include "AbstractLine.h"
#include "Line.h"
class VerticalLine :
	public AbstractLine
{
	int val;
public:
	VerticalLine(int _val);
	double angleBetweenOXandLine();
	double get_a();
	double get_b();
	void drawLineByEquasion(Mat& field);
	int get_val();
	Point lines_intersection(Line* another_line);
	Point lines_intersection(VerticalLine* another_line);
	AbstractLine* find_perpendicular(Point p);

	~VerticalLine();
};

