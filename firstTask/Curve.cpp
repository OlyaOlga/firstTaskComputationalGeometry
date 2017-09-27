#include"Curve.h"
#include "opencv2/imgproc.hpp"
#include <vector>

using namespace std;
using namespace cv;

Curve::Curve()
{
}

std::vector<cv::Point> Curve::getPoints()
{
	return basePoints;
}

std::istream & operator >> (std::istream & stream, Curve & curve)
{
		Point toAdd;
		stream >> toAdd.x;
		stream >> toAdd.y;
		curve.basePoints.push_back(toAdd);
		return stream;
}
