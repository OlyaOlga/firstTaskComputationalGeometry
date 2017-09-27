#include "Computation.h"


#define PI 3.14159265;

double Computation::count_norm(Point vect)
{
	return sqrt(pow(vect.x, 2) + pow(vect.y, 2));
}

double Computation::scalar_product(Point p1, Point p2)
{
	return p1.x*p2.x + p1.y * p2.y;
}

double Computation::cos_of_angle(Point vect1, Point vect2)
{
	return(scalar_product(vect1, vect2) / (count_norm(vect1) * count_norm(vect2)));
}

double Computation::arc_cos(double cos)
{
	return acos(cos) * 180 / PI;
}

double Computation::find_angle(Point v1, Point v2)
{
	return arc_cos(cos_of_angle(v1, v2));
}

double Computation::from_rad_to_degree(double rad)
{
	return rad*180/PI;
}
