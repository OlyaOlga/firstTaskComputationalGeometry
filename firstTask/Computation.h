#pragma once
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

class Computation
{
public:
	static double count_norm(Point vect);
	static double scalar_product(Point p1, Point p2);
	static double cos_of_angle(Point vect1, Point vect2);
	static double arc_cos(double cos);
	static double find_angle(Point pv1, Point v2);
	static double from_rad_to_degree(double rad);
};