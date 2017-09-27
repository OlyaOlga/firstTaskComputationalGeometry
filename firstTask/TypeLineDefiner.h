#pragma once
#include"AbstractLine.h"
#include"VerticalLine.h"
#include"Line.h"
#include "opencv2/imgproc.hpp"
using namespace cv;
class TypeLineDefiner
{
public:
	TypeLineDefiner();
	~TypeLineDefiner();

	AbstractLine* DefineType(Point first, Point second);
	AbstractLine* DefineType(double _x, double _y, double _angle);
};

