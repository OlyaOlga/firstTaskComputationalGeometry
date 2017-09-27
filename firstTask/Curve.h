#pragma once
#include <iostream>
#include "opencv2/imgproc.hpp"

class Curve
{
	std::vector<cv::Point> basePoints;
public:
	Curve();
	std::vector<cv::Point> getPoints();
	friend std::istream& operator >> (std::istream& stream, Curve& curve);
};
