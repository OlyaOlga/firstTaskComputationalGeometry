#pragma once
#include "AbstractLine.h"
class VerticalLine :
	public AbstractLine
{
	int val;
public:
	VerticalLine(int _val);
	double angleBetweenOXandLine();
	double get_a();
	void drawLineByEquasion(Mat& field);
	~VerticalLine();
};

